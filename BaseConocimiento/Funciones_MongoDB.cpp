/*	TFG:	Sistema de conocimiento para robótica cognitiva social
			Grado en Ingeniería en Tecnologías Industriales
			Sofía Hernangómez Flores
			2021

	Tutor:	Daniel Galán Vicente
*/


#include "pch.h"	//	Archivo de precompilado
#include "Funciones_MongoDB.h"
#include "Funciones.h"
#include "Funciones_Archivos.h"
#include "Botones_Documento.h"

#include "json/json.h"
using namespace Json;


//Declaración variables externas que se utilizan en Funciones_MongoDB.cpp
extern bson_error_t error;
extern mongoc_client_t* cliente;
extern mongoc_database_t* base_de_datos;
extern mongoc_collection_t* coleccion;
extern bson_t* query;
extern mongoc_cursor_t* cursor;
extern bson_t* documento;


//Función que comprueba si una Base de Datos existe o no
int ComprobacionExistenciaBase(string consulta) {
	char** lista_bases_disponibles;
	lista_bases_disponibles = mongoc_client_get_database_names_with_opts(cliente, NULL, &error);
	if (lista_bases_disponibles) {
		for (unsigned int i = 0; lista_bases_disponibles[i]; i++) {
			if ((std::strcmp(consulta.c_str(), lista_bases_disponibles[i])) == 0) {
				return 1;
			}
		}
		bson_strfreev(lista_bases_disponibles);
	}
	else fprintf(stderr, "Command failed: %s\n", error.message);
	return 0;
}


//Función que comprueba si una colección existe o no
int ComprobacionExistenciaColeccion(string dato) {
	int solucion = 0;
	char** lista_bases_disponibles;
	lista_bases_disponibles = mongoc_client_get_database_names_with_opts(cliente, NULL, &error);
	if (lista_bases_disponibles) {
		for (unsigned int i = 0; lista_bases_disponibles[i]; i++) {
			if (solucion == 0) {
				string base = lista_bases_disponibles[i];
				solucion = ColeccionPerteneceABase(base, dato);
			}
		}
		bson_strfreev(lista_bases_disponibles);
	}
	else fprintf(stderr, "Command failed: %s\n", error.message);
	return solucion;
}


//Función que comprueba si una Base de Datos es inherente a MongoDB
int BaseInherenteMongoDB(string Base) {
	if (std::strcmp(Base.c_str(), "admin") == 0) {
		return 1;
	}
	else if (std::strcmp(Base.c_str(), "config") == 0) {
		return 1;
	}
	else if (std::strcmp(Base.c_str(), "local") == 0) {
		return 1;
	}
	else if (std::strcmp(Base.c_str(), "confianza") == 0) {
		return 1;
	}
	else return 0;
}


//Función que comprueba si una colección pertenece a una Base de Datos dada o no
int ColeccionPerteneceABase(string Nombre_Base, string consulta_Coleccion) {
	base_de_datos = mongoc_client_get_database(cliente, Nombre_Base.c_str());
	char** lista_colecciones_disponibles;
	lista_colecciones_disponibles = mongoc_database_get_collection_names(base_de_datos, &error);
	if (lista_colecciones_disponibles) {
		for (unsigned int j = 0; lista_colecciones_disponibles[j]; j++) {
			if ((std::strcmp(consulta_Coleccion.c_str(), lista_colecciones_disponibles[j])) == 0) {
				return 1;
			}
		}
		bson_strfreev(lista_colecciones_disponibles);
	}
	else fprintf(stderr, "Command failed: %s\n", error.message);
	mongoc_database_destroy(base_de_datos);
	return 0;
}


//Función para saber si existe un bson coincidente con la consulta
int BuscarBSONCoincidente(string Nombre_Base, string Nombre_Coleccion, string contenido_fichero) {
	int coincidencia = 0;
	const char* contenido_consulta = contenido_fichero.c_str();

	//	Creamos un documento bson con el dato que queremos buscar
	query = bson_new_from_json((const uint8_t*)contenido_consulta, -1, &error);

	coleccion = mongoc_client_get_collection(cliente, Nombre_Base.c_str(), Nombre_Coleccion.c_str());

	//	Función de MongoDB que comprueba si algún documento de la colección contiene la consulta realizada
	cursor = mongoc_collection_find_with_opts(coleccion, query, NULL, NULL);

	//	Creación de objeto de tipo bson_t para guardar el contenido del documento que coincida
	const bson_t* salida;

	if (mongoc_cursor_next(cursor, &salida)) {
		coincidencia = 1;
	}
	mongoc_cursor_destroy(cursor);
	mongoc_collection_destroy(coleccion);

	return coincidencia;
}


//Función que devuelve el nombre de las colecciones a las que pertenece un documento
vector <string> BuscarBaseColeccionDoc(string json_consulta) {

	vector <string> Lista_BasesColecciones_Doc;

	const char* json = json_consulta.c_str();
	//	Creamos un documento bson con el dato que queremos buscar
	query = bson_new_from_json((const uint8_t*)json, -1, &error);

	char** lista_bases_disponibles;
	lista_bases_disponibles = mongoc_client_get_database_names_with_opts(cliente, NULL, &error);

	if (lista_bases_disponibles) {
		for (unsigned int i = 1; lista_bases_disponibles[i]; i++) {
			const char* nombre_base = lista_bases_disponibles[i];
			string nombre_base_str = nombre_base;
			base_de_datos = mongoc_client_get_database(cliente, nombre_base);
			char** lista_colecciones_disponibles;
			lista_colecciones_disponibles = mongoc_database_get_collection_names(base_de_datos, &error);
			if (lista_colecciones_disponibles) {
				for (unsigned int j = 0; lista_colecciones_disponibles[j]; j++) {
					const char* nombre_coleccion = lista_colecciones_disponibles[j];
					string nombre_coleccion_str = nombre_coleccion;
					coleccion = mongoc_client_get_collection(cliente, nombre_base, nombre_coleccion);

					//	Función de MongoDB que comprueba si algún documento de la colección contiene la consulta realizada
					cursor = mongoc_collection_find_with_opts(coleccion, query, NULL, NULL);

					//	Creación de objeto de tipo bson_t para guardar el contenido del documento que coincida
					char* datos;
					const bson_t* doc;

					if (mongoc_cursor_next(cursor, &doc)) {
						string basecoleccion = nombre_base_str + "#" + nombre_coleccion_str;
						Lista_BasesColecciones_Doc.push_back(basecoleccion);
					}
					mongoc_cursor_destroy(cursor);
					mongoc_collection_destroy(coleccion);
				}

			}
			mongoc_database_destroy(base_de_datos);
		}

	}
	bson_destroy(query);
	return Lista_BasesColecciones_Doc;
}


//Función que devuelve el nombre de las Bases de Datos a las que pertenece una coleccion
vector <string> BuscarBaseColeccion(string nombre_coleccion) {
	vector <string> BasesDatos;
	char** lista_bases_disponibles;
	lista_bases_disponibles = mongoc_client_get_database_names_with_opts(cliente, NULL, &error);

	if (lista_bases_disponibles) {
		for (unsigned int i = 1; lista_bases_disponibles[i]; i++) {
			string nombre_base = lista_bases_disponibles[i];
			if (ColeccionPerteneceABase(nombre_base, nombre_coleccion) == 1) {
				BasesDatos.push_back(nombre_base);
			}
		}
	}
	return BasesDatos;
}


vector <string> ExtraerContenidoDocumento(string nombre_base, string nombre_coleccion, string contenido_identificador) {
	vector <string> docu;

	const char* json = contenido_identificador.c_str();
	//	Creamos un documento bson con el dato que queremos buscar
	query = bson_new_from_json((const uint8_t*)json, -1, &error);

	coleccion = mongoc_client_get_collection(cliente, nombre_base.c_str(), nombre_coleccion.c_str());

	//	Función de MongoDB que comprueba si algún documento de la colección contiene la consulta realizada
	cursor = mongoc_collection_find_with_opts(coleccion, query, NULL, NULL);

	//	Creación de objeto de tipo bson_t para guardar el contenido del documento que coincida
	const bson_t* doc;

	while (mongoc_cursor_next(cursor, &doc)) {
		string ubicacion = "Consulta.txt";
		ofstream archivo;
		archivo.open(ubicacion);
		archivo << bson_as_canonical_extended_json(doc, NULL);
		archivo.close();
		docu = LeerJSON(ubicacion);
		remove(ubicacion.c_str());
	}
	mongoc_cursor_destroy(cursor);
	mongoc_collection_destroy(coleccion);
	bson_destroy(query);
	return docu;
}


//Función que devuelve el número de documentos que hay en una colección
double NumeroDeDocumentosColeccion(string nombre_base, string nombre_coleccion) {
	int n;
	vector <string> DocumentosColeccion = ListaDocumentosDisponibles(nombre_base, nombre_coleccion);
	if (DocumentosColeccion.empty()) n = 0;
	else n = DocumentosColeccion.size();
	return n;
}


//Función que devuelve el número de colecciones que hay en una Base de Datos
double NumeroDeColecciones(string nombre_base) {
	int n;
	vector <string> Colecciones = ListaColeccionesDisponibles(nombre_base);
	if (Colecciones.empty()) n = 0;
	else n = Colecciones.size();
	return n;
}


//Función que devuelve el nombre de las Bases de Datos disponibles
vector <string> ListaBasesDeDatosDisponibles() {
	vector <string> Nombres_Bases;
	char** lista_bases_disponibles;
	lista_bases_disponibles = mongoc_client_get_database_names_with_opts(cliente, NULL, &error);
	if (lista_bases_disponibles) {
		for (unsigned int i = 1; lista_bases_disponibles[i]; i++) {
			if (BaseInherenteMongoDB(lista_bases_disponibles[i]) == 0) {
				Nombres_Bases.push_back(lista_bases_disponibles[i]);
			}
		}
	}
	bson_strfreev(lista_bases_disponibles);
	return Nombres_Bases;
}


//Función que devuelve el nombre de las colecciones disponibles en una Base de Datos
vector <string> ListaColeccionesDisponibles(string nombre_base) {
	vector <string> Nombres_Colecciones;
	base_de_datos = mongoc_client_get_database(cliente, nombre_base.c_str());
	char** lista_colecciones_disponibles = mongoc_database_get_collection_names(base_de_datos, &error);
	if (lista_colecciones_disponibles) {
		for (unsigned int i = 0; lista_colecciones_disponibles[i]; i++) {
			Nombres_Colecciones.push_back(lista_colecciones_disponibles[i]);
		}
	}
	bson_strfreev(lista_colecciones_disponibles);
	return Nombres_Colecciones;
}


//Función que devuelve el nombre de los documentos disponibles en una colección
vector <string> ListaDocumentosDisponibles(string nombre_base, string nombre_coleccion) {
	vector <string> Nombres_Documentos;
	vector <string> Documentos = BuscarDocumentosColeccion(nombre_base, nombre_coleccion);
	for (int i = 0; i < Documentos.size(); i++) {
		int pos;
		string nombre_identificador;
		string palabra_a_buscar = "identificador";
		pos = Documentos[i].find(palabra_a_buscar);
		if (pos != string::npos) {
			nombre_identificador = Documentos[i].substr(pos + strlen(palabra_a_buscar.c_str()), strlen(Documentos[i].c_str()));
			pos = nombre_identificador.find('"');
			nombre_identificador = nombre_identificador.substr(pos + 1, strlen(nombre_identificador.c_str()));
			pos = nombre_identificador.find('"');
			nombre_identificador = nombre_identificador.substr(pos + 1, strlen(nombre_identificador.c_str()));
			pos = nombre_identificador.find('"');
			nombre_identificador = nombre_identificador.substr(0, pos);
			Nombres_Documentos.push_back(nombre_identificador.c_str());
		}
	}
	return Nombres_Documentos;
}


//Función que devuelve el nombre de los archivos multimedia disponibles en una Base De Datos
vector <string> ListaArchivosMultimediaDisponibles(string tipo_documento) {
	vector <string> Nombres_ArchivosMultimedia;

	vector <string> Documentos = BuscarDocumentosMultimedia(tipo_documento);
	for (int i = 0; i < Documentos.size(); i++) {
		int pos;
		string nombre_filename;
		string palabra_a_buscar = "filename";
		pos = Documentos[i].find(palabra_a_buscar);
		if (pos != string::npos) {
			nombre_filename = Documentos[i].substr(pos + strlen(palabra_a_buscar.c_str()), strlen(Documentos[i].c_str()));
			pos = nombre_filename.find('"');
			nombre_filename = nombre_filename.substr(pos + 1, strlen(nombre_filename.c_str()));
			pos = nombre_filename.find('"');
			nombre_filename = nombre_filename.substr(pos + 1, strlen(nombre_filename.c_str()));
			pos = nombre_filename.find('"');
			nombre_filename = nombre_filename.substr(0, pos);
			Nombres_ArchivosMultimedia.push_back(nombre_filename.c_str());
		}
	}
	return Nombres_ArchivosMultimedia;
}


//Función que devuelve el nombre de los atributos (clave) contenidos en un documento
vector <string> ListaAtributosDisponibles(string nombre_base, string nombre_coleccion, string nombre_documento) {
	vector <string> Nombres_Atributos;
	vector <string> contenido_documento = BuscarDocumento(nombre_base, nombre_coleccion, nombre_documento);
	for (int i = 0; i < contenido_documento.size(); i++) {
		int pos;
		string clave;
		pos = contenido_documento[i].find('"');
		if (pos != string::npos) {
			clave = contenido_documento[i].substr(pos + 1, strlen(contenido_documento[i].c_str()));
			pos = clave.find('"');
			clave = clave.substr(0, pos);
			if (AtributoInherente(clave) == 0) {
				if (ElementoCoincidente(clave, Nombres_Atributos) == 0) {
					Nombres_Atributos.push_back(clave.c_str());
				}
			}
		}
	}
	return Nombres_Atributos;
}


//Función que devuelve el nombre de los atributos comunes de una colección
vector <string> AtributosComunesColeccion(string nombre_base, string nombre_coleccion) {
	vector <string> Nombres_Atributos;
	int numero_documentos = NumeroDeDocumentosColeccion(nombre_base, nombre_coleccion);
	
	//Dividimos los atributos coincidentes en cinco grupos
	double Coincidencia_total = numero_documentos;	
	vector <string> Atributos_Total;	//Todos los documentos tienen este atributo
	double Coincidencia_casi_total = 0.75 * numero_documentos;	
	vector <string> Atributos_casi_total;	//Entre el 75% y el 99% de los documentos tiene este atributo
	double Coincidencia_parcial = 0.5 * numero_documentos;	
	vector <string> Atributos_parcial;	//Entre el 50% y el 74% de los documentos tiene este atributo
	double Coincidencia_casi_nula = 0.25 * numero_documentos;
	vector <string> Atributos_casi_parcial;	//Entre el 25% y el 49% de los documentos tiene este atributo
	vector <string> Atributos_casi_nula;	//Entre el 1% y el 24% de los documentos tiene este atributo
	
	vector <string> NombresDocumentos = ListaDocumentosDisponibles(nombre_base, nombre_coleccion);
	int numero_atributos = 0;
	string documento_con_mas_atributos;

	if (numero_documentos > 1) {
		//Miramos cuál es el documento con más atributos para compararlo con los demás
		for (int i = 0; i < NombresDocumentos.size(); i++) {
			vector <string> AtributosDocumento = ListaAtributosDisponibles(nombre_base, nombre_coleccion, NombresDocumentos[i]);
			if (AtributosDocumento.size() > numero_atributos) {
				numero_atributos = AtributosDocumento.size();
				documento_con_mas_atributos = NombresDocumentos[i];
			}
		}

		vector <string> AtributosMaximoDocumento = ListaAtributosDisponibles(nombre_base, nombre_coleccion, documento_con_mas_atributos);

		for (int j = 0; j < numero_atributos; j++) {
			if (strcmpi(AtributosMaximoDocumento[j].c_str(), "identificador") != 0) {
				double atributo_coincidente = 0;
				for (int k = 0; k < NombresDocumentos.size(); k++) {
					vector <string> NombresAtributos = ListaAtributosDisponibles(nombre_base, nombre_coleccion, NombresDocumentos[k]);
					for (int m = 0; m < NombresAtributos.size(); m++) {
						if (strcmpi(AtributosMaximoDocumento[j].c_str(), NombresAtributos[m].c_str()) == 0) {
							atributo_coincidente++;
							m = NombresAtributos.size();
						}
					}
				}
				if (atributo_coincidente == Coincidencia_total) Atributos_Total.push_back(AtributosMaximoDocumento[j]);
				else if (atributo_coincidente >= Coincidencia_casi_total) Atributos_casi_total.push_back(AtributosMaximoDocumento[j]);
				else if (atributo_coincidente >= Coincidencia_parcial) Atributos_parcial.push_back(AtributosMaximoDocumento[j]);
				else if (atributo_coincidente >= Coincidencia_casi_nula) Atributos_casi_parcial.push_back(AtributosMaximoDocumento[j]);
				else if (atributo_coincidente < Coincidencia_casi_nula) Atributos_casi_nula.push_back(AtributosMaximoDocumento[j]);
			}
		}

		Nombres_Atributos.push_back("100");
		for (int n = 0; n < Atributos_Total.size(); n++) Nombres_Atributos.push_back(Atributos_Total[n]);
		Nombres_Atributos.push_back("fin");
		Nombres_Atributos.push_back("75");
		for (int n = 0; n < Atributos_casi_total.size(); n++) Nombres_Atributos.push_back(Atributos_casi_total[n]);
		Nombres_Atributos.push_back("fin");
		Nombres_Atributos.push_back("50");
		for (int n = 0; n < Atributos_parcial.size(); n++) Nombres_Atributos.push_back(Atributos_parcial[n]);
		Nombres_Atributos.push_back("fin");
		Nombres_Atributos.push_back("25");
		for (int n = 0; n < Atributos_casi_parcial.size(); n++) Nombres_Atributos.push_back(Atributos_casi_parcial[n]);
		Nombres_Atributos.push_back("fin");
		Nombres_Atributos.push_back("0");
		for (int n = 0; n < Atributos_casi_nula.size(); n++) Nombres_Atributos.push_back(Atributos_casi_nula[n]);
		Nombres_Atributos.push_back("fin");
	}
	return Nombres_Atributos;
}


//Función que devuelve el nombre de los atributos presentes en el % indicado
vector <string>	AtributosComunesPorcentaje(double porcentaje, vector <string> atributos) {
	vector <string> Nombres_Atributos;
	if (porcentaje <= 100) {
		string palabra_a_buscar;
		if (porcentaje == 100) palabra_a_buscar = to_string(100);
		else if (porcentaje >= 75) palabra_a_buscar = to_string(75);
		else if (porcentaje >= 50) palabra_a_buscar = to_string(50);
		else if (porcentaje >= 25) palabra_a_buscar = to_string(25);
		else if (porcentaje >= 0) palabra_a_buscar = to_string(0);
		
		for (int i = 0; i < atributos.size(); i++) {
			if (strcmpi(atributos[i].c_str(), palabra_a_buscar.c_str()) == 0) {
				for (int j = i + 1; j < atributos.size(); j++) {
					if (strcmpi(atributos[j].c_str(), "fin") == 0) j = atributos.size();
					else Nombres_Atributos.push_back(atributos[j]);
				}
			}
		}
	}
	return Nombres_Atributos;
}


//Función que devuelve los atributos que le faltan a un documento
vector <string>	AtributosQueFaltan(vector <string> atributos_a_analizar, vector <string> lista_atributos) {
	vector <string> Nombres_Atributos;
	for (int i = 0; i < atributos_a_analizar.size(); i++) {
		for (int j = 0; j < lista_atributos.size(); j++) {
			if (strcmpi(atributos_a_analizar[i].c_str(), lista_atributos[j].c_str()) == 0) j = lista_atributos.size();
			else if (j == (lista_atributos.size() - 1)) {
				Nombres_Atributos.push_back(atributos_a_analizar[i]);
			}
		}
	}
	return Nombres_Atributos;
}



//Función que devuelve el nombre de los atributos comunes de una Base de Datos
vector <string> AtributosComunesBaseDeDatos(string nombre_base) {
	vector <string> Nombres_Atributos;

	return Nombres_Atributos;
}


//Función que devuelve las Bases de Datos que contienen colecciones en las que haya algún documento para curiosidad
vector <string> BasesParaCuriosidad() {
	vector <string> BasesParaUtilizarEnCuriosidad;
	vector <string> Bases = ListaBasesDeDatosDisponibles();
	vector <string> BasesUtiles;
	for (int i = 0; i < Bases.size(); i++) {
		if (BaseDeDatosMultimedia(Bases[i]) == 0) BasesUtiles.push_back(Bases[i]);
	}
	for (int j = 0; j < BasesUtiles.size(); j++) {
		vector <string> Colecciones = ColeccionesParaCuriosidad(BasesUtiles[j]);
		if (Colecciones.empty() == false) BasesParaUtilizarEnCuriosidad.push_back(BasesUtiles[j]);
	}
	return BasesParaUtilizarEnCuriosidad;
}


//Función que devuelve las colecciones que contienen algún documento para curiosidad
vector <string> ColeccionesParaCuriosidad(string nombre_base) {
	vector <string> ColeccionesParaUtilizarEnCuriosidad;
	vector <string> Colecciones = ListaColeccionesDisponibles(nombre_base);
	for (int i = 0; i < Colecciones.size(); i++) {
		vector <string> Documentos = DocumentosParaCuriosidad(nombre_base, Colecciones[i]);
		if (Documentos.size() > 0) ColeccionesParaUtilizarEnCuriosidad.push_back(Colecciones[i]);
	}
	return ColeccionesParaUtilizarEnCuriosidad;
}

//Función que devuelve los documentos a los que les falta algún atributo
vector <string> DocumentosParaCuriosidad(string nombre_base, string nombre_coleccion) {
	vector <string> DocumentosParaUtilizarEnCuriosidad;
	vector <string> Documentos = ListaDocumentosDisponibles(nombre_base, nombre_coleccion);
	//Comprobamos qué atributos le faltan al documento seleccionado
	vector <string> AtributosColeccionSeleccionada = AtributosComunesColeccion(nombre_base, nombre_coleccion);
	for (int i = 0; i < Documentos.size(); i++) {
		vector <string> AtributosDocumentoSeleccionado = ListaAtributosDisponibles(nombre_base, nombre_coleccion, Documentos[i]);
		vector <string> AtributosFaltan;
		vector <string> AtributosAAnalizar = AtributosComunesPorcentaje(75, AtributosColeccionSeleccionada);
		AtributosFaltan = AtributosQueFaltan(AtributosAAnalizar, AtributosDocumentoSeleccionado);
		if (AtributosFaltan.empty()) {
			vector <string> AtributosAAnalizar = AtributosComunesPorcentaje(50, AtributosColeccionSeleccionada);
			AtributosFaltan = AtributosQueFaltan(AtributosAAnalizar, AtributosDocumentoSeleccionado);
		}
		
		if (AtributosFaltan.size() > 0) DocumentosParaUtilizarEnCuriosidad.push_back(Documentos[i]);
	}
	return DocumentosParaUtilizarEnCuriosidad;
}


//Función que organiza la confianza de los datos introducidos
void GuardarConfianza(string nombre_base, string nombre_coleccion, string nombre_documento, vector <string> atributos, string confianza, int modo) {
	base_de_datos = mongoc_client_get_database(cliente, "confianza");
	string coleccion_confianza = nombre_base + " " + nombre_coleccion;
	if (ColeccionPerteneceABase("confianza", coleccion_confianza) == 0) {
		coleccion = mongoc_database_create_collection(base_de_datos, coleccion_confianza.c_str(), NULL, &error);
	}
	else coleccion = mongoc_client_get_collection(cliente, "confianza", coleccion_confianza.c_str());

	if (modo == 0) {
		//Creamos el fichero
		string ubicacion = nombre_documento + ".txt";
		CrearFichero(ubicacion, "identificador", nombre_documento);

		string clave, valor;
		clave = "base de datos";
		valor = "confianza";
		NuevaLinea(clave, valor, ubicacion, nombre_documento);
		clave = "coleccion";
		valor = coleccion_confianza;
		NuevaLinea(clave, valor, ubicacion, nombre_documento);

		//Modificamos el vector atributos (sustituimos valor por confianza)
		vector <string> atributos_confianza;
		for (int j = 0; j < atributos.size(); j = j + 2) {
			atributos_confianza.push_back(atributos[j]);
			atributos_confianza.push_back(confianza);
		}

		for (int i = 0; i < atributos_confianza.size(); i = i + 2) {
			NuevaLinea(atributos_confianza[i], atributos_confianza[i + 1], ubicacion, nombre_documento);
		}

		string contenido_fichero = LeerFichero(ubicacion);
		remove(ubicacion.c_str());

		const char* contenido_documento = contenido_fichero.c_str();

		//	Creamos objeto tipo bson_t
		documento = bson_new_from_json((const uint8_t*)contenido_documento, -1, &error);

		//	Añadimos el documento a la coleccion
		mongoc_collection_insert_one(coleccion, documento, NULL, NULL, &error);

		bson_destroy(documento);
		mongoc_collection_destroy(coleccion);
		/*mongoc_database_destroy(base_de_datos);*/
	}

	else if (modo == 1) {
		//Pasamos los valores que recibimos del programa principal a const char* para poder usar las funciones de MongoDB
		const char* identificador = nombre_documento.c_str();
		const char* key = atributos[0].c_str();
		const char* value = confianza.c_str();

		bson_t consulta = BSON_INITIALIZER;
		bson_t* update;
		mongoc_find_and_modify_opts_t* opts;

		bson_error_t error;

		bool success = false;


		//Creamos un BSON (consulta) con el dato que queremos buscar
		BSON_APPEND_UTF8(&consulta, "identificador", identificador);

		//Creamos un BSON (update) con el dato que queremos añadir
		update = BCON_NEW("$set", "{", key, BCON_UTF8(value), "}");

		//Creamos un mongoc_find_and_modify_opts_t y establecemos las opciones
		opts = mongoc_find_and_modify_opts_new();
		mongoc_find_and_modify_opts_set_update(opts, update);
		mongoc_find_and_modify_opts_set_flags(opts, MONGOC_FIND_AND_MODIFY_RETURN_NEW);


		coleccion = mongoc_client_get_collection(cliente, "confianza", coleccion_confianza.c_str());
		success = mongoc_collection_find_and_modify_with_opts(coleccion, &consulta, opts, documento, &error);
		mongoc_collection_destroy(coleccion);


		bson_destroy(documento);
		bson_destroy(update);
		bson_destroy(&consulta);
		mongoc_find_and_modify_opts_destroy(opts);
	}


}