/*	TFG:	Sistema de conocimiento para robótica cognitiva social
			Grado en Ingeniería en Tecnologías Industriales
			Sofía Hernangómez Flores
			2021

	Tutor:	Daniel Galán Vicente
*/


#include "pch.h"	//Archivo de precompilado
#include "Botones_Documento.h"

#include <stdlib.h>
#include <time.h>



//Declaración variables globales que se utilizan en este archivo
extern mongoc_client_t* cliente;
extern mongoc_database_t* base_de_datos;
extern mongoc_collection_t* coleccion;
extern mongoc_cursor_t* cursor;
extern bson_error_t error;
extern bson_t* query;
extern bson_t* documento;


//Función equivalente al Botón Añadir Documento
void CrearDocumento(string Base, string Coleccion, string nombre, vector <string> atributos, string confianza) {
	
	//Comprobamos la existencia de la Base de Datos introducida
	if (ComprobacionExistenciaBase(Base) == 1) {
		
		//Comprobamos que no se trate de una Base de Datos inherente a MongoDB
		if (BaseInherenteMongoDB(Base) == 0) {

			//Comprobamos que la colección introducida pertenezca a la Base de Datos introducida
			if (ColeccionPerteneceABase(Base, Coleccion) == 1) {
				
				string ubicacion_consulta = "Consulta.txt";
				CrearFichero(ubicacion_consulta, "identificador", nombre);
				string contenido_identificador = LeerFichero(ubicacion_consulta);
				remove(ubicacion_consulta.c_str());

				//Comprobamos que no exista ningún documento sobre el tema propuesto en la colección seleccionada
				if (BuscarBSONCoincidente(Base, Coleccion, contenido_identificador) == 0) {

					GuardarConfianza(Base, Coleccion, nombre, atributos, confianza, 0);

					base_de_datos = mongoc_client_get_database(cliente, Base.c_str());
					coleccion = mongoc_client_get_collection(cliente, Base.c_str(), Coleccion.c_str());

					//	Creamos el fichero
					string ubicacion = nombre + ".txt";
					CrearFichero(ubicacion, "identificador", nombre);

					string clave, valor;
					clave = "base de datos";
					valor = Base;
					NuevaLinea(clave, valor, ubicacion, nombre);
					clave = "coleccion";
					valor = Coleccion;
					NuevaLinea(clave, valor, ubicacion, nombre);

					for (int i = 0; i < atributos.size(); i=i+2) {
						NuevaLinea(atributos[i], atributos[i + 1], ubicacion, nombre);
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
					mongoc_database_destroy(base_de_datos);
				}
			}
		}
	}
}


//Función equivalente al Botón Buscar por colección
vector <string> BuscarDocumentosColeccion(string nombre_base, string nombre_coleccion) {
	
	vector <string> documentos_coleccion;

	//Comprobamos que la Base de Datos exista
	if (ComprobacionExistenciaBase(nombre_base) == 1) {
		//Comprobamos que la coleccion pertenezca a la Base de Datos
		if (ColeccionPerteneceABase(nombre_base, nombre_coleccion) == 1) {
			coleccion = mongoc_client_get_collection(cliente, nombre_base.c_str(), nombre_coleccion.c_str());

			string ubicacion_consulta = "Consulta.txt";
			CrearFichero(ubicacion_consulta, "base de datos", nombre_base);
			NuevaLinea("coleccion", nombre_coleccion, ubicacion_consulta, "Consulta");
			string json_str = LeerFichero(ubicacion_consulta);
			remove(ubicacion_consulta.c_str());

			const char* json = json_str.c_str();
			query = bson_new_from_json((const uint8_t*)json, -1, &error);
			const bson_t* filter = query;
			cursor = mongoc_collection_find_with_opts(coleccion, filter, NULL, NULL);

			const bson_t* doc;
			while (mongoc_cursor_next(cursor, &doc)) {
				//Guardamos el contenido de cada documento de la colección y lo añadimos al vector documentos_coleccion
				string ubicacion = "Consulta.txt";
				ofstream archivo;
				archivo.open(ubicacion);
				archivo << bson_as_canonical_extended_json(doc, NULL);
				archivo.close();
				vector <string> Contenido_Documento = LeerJSON(ubicacion);
				for (int i = 0; i < Contenido_Documento.size(); i++) {
					documentos_coleccion.push_back(Contenido_Documento[i]);
				}
				documentos_coleccion.push_back("findeldocumento");
				remove(ubicacion.c_str());
			}
			mongoc_collection_destroy(coleccion);
			mongoc_cursor_destroy(cursor);
			bson_destroy(query);
		}
	}
	
	return documentos_coleccion;
}


//Función equivalente al Botón Buscar por ID
vector <string> BuscarDocumentoPorID(string id) {

	vector <string> documento_consulta;

	string ubicacion = "Consulta.txt";
	ofstream archivo;
	archivo.open(ubicacion);

	//{ "_id" : { "$oid" : "60a252e5d158000021000df3" }
	archivo << "{\n\t\"_id\" : { \"$oid\" : " << "\"" << id.c_str() << "\"" << "}\n}" << endl;
	archivo.close();

	string contenido_fichero = LeerFichero(ubicacion);
	remove(ubicacion.c_str());

	vector <string> BaseColeccion = BuscarBaseColeccionDoc(contenido_fichero);

	char almohadilla = '#';
	string subcadena;
	int posInit = 0;
	int posFound = BaseColeccion[0].find(almohadilla, posInit);
	string nombre_base = BaseColeccion[0].substr(posInit, posFound - posInit);
	string nombre_coleccion = BaseColeccion[0].substr(posFound + 1, strlen(BaseColeccion[0].c_str()));
	vector <string> contenidoDocumento = ExtraerContenidoDocumento(nombre_base, nombre_coleccion, contenido_fichero);
	for (int i = 0; i < contenidoDocumento.size(); i++) {
		documento_consulta.push_back(contenidoDocumento[i]);
	}
	
	return documento_consulta;
}


//Función equivalente al Botón buscar por nombre
vector <string> BuscarDocumento(string base, string coleccion, string identificador_documento) {

	string ubicacion_consulta = "Consulta.txt";

	CrearFichero(ubicacion_consulta, "identificador", identificador_documento);
	string contenido_fichero = LeerFichero(ubicacion_consulta);
	remove(ubicacion_consulta.c_str());

	vector <string> documentos_consulta;

	if (base.empty() || coleccion.empty()) {
		vector <string> BasesColecciones = BuscarBaseColeccionDoc(contenido_fichero);
		for (int i = 0; i < BasesColecciones.size(); i++) {
			char almohadilla = '#';
			string subcadena;
			int posInit = 0;
			int posFound = BasesColecciones[i].find(almohadilla, posInit);
			string nombre_base = BasesColecciones[i].substr(posInit, posFound - posInit);
			string nombre_coleccion = BasesColecciones[i].substr(posFound + 1, strlen(BasesColecciones[i].c_str()));
			vector <string> contenidoDocumento = ExtraerContenidoDocumento(nombre_base, nombre_coleccion, contenido_fichero);
			for (int j = 0; j < contenidoDocumento.size(); j++) {
				documentos_consulta.push_back(contenidoDocumento[j]);
			}
			documentos_consulta.push_back("findeldocumento");
		}
	}
	else {
		vector <string> contenidoDocumento = ExtraerContenidoDocumento(base, coleccion, contenido_fichero);
		for (int j = 0; j < contenidoDocumento.size(); j++) {
			documentos_consulta.push_back(contenidoDocumento[j]);
		}
		documentos_consulta.push_back("findeldocumento");
	}

	return documentos_consulta;
}


//Función equivalente al Botón buscar por atributos
vector <string> BuscarDocumentoPorAtributos(vector <string> atributos) {

	string ubicacion_consulta = "Consulta.txt";
	CrearFichero(ubicacion_consulta, atributos[0], atributos[1]);

	for (int i = 2; i < (atributos.size()); i = i + 2) {
		NuevaLinea(atributos[i], atributos[i + 1], ubicacion_consulta, "Consulta");
	}

	string consulta_atributos = LeerFichero(ubicacion_consulta);
	remove(ubicacion_consulta.c_str());

	vector <string> BasesColecciones = BuscarBaseColeccionDoc(consulta_atributos);
	vector <string> documentos_atributos;

	const char* json = consulta_atributos.c_str();
	query = bson_new_from_json((const uint8_t*)json, -1, &error);
	const bson_t* filter = query;

	for (int i = 0; i < BasesColecciones.size(); i++) {
		char almohadilla = '#';
		string subcadena;
		int posInit = 0;
		int posFound = BasesColecciones[i].find(almohadilla, posInit);
		string nombre_base = BasesColecciones[i].substr(posInit, posFound - posInit);
		string nombre_coleccion = BasesColecciones[i].substr(posFound + 1, strlen(BasesColecciones[i].c_str()));
		
		coleccion = mongoc_client_get_collection(cliente, nombre_base.c_str(), nombre_coleccion.c_str());
		cursor = mongoc_collection_find_with_opts(coleccion, filter, NULL, NULL);

		const bson_t* doc;
		while (mongoc_cursor_next(cursor, &doc)) {
			//Guardamos el contenido de cada documento de la colección y lo añadimos al vector documentos_coleccion
			string ubicacion = "Consulta.txt";
			ofstream archivo;
			archivo.open(ubicacion);
			archivo << bson_as_canonical_extended_json(doc, NULL);
			archivo.close();
			vector <string> Contenido_Documento = LeerJSON(ubicacion);
			for (int i = 0; i < Contenido_Documento.size(); i++) {
				documentos_atributos.push_back(Contenido_Documento[i]);
			}
			documentos_atributos.push_back("findeldocumento");
			remove(ubicacion.c_str());
		}
		mongoc_collection_destroy(coleccion);
		mongoc_cursor_destroy(cursor);
	}
	bson_destroy(query);

	return documentos_atributos;
}


//Función equivalente al Botón Modificar Documento Añadiento Atributo
bool AñadirAtributoADocumento(string nombre, string clave, string valor, string base_seleccionada, string coleccion_seleccionada, string confianza) {
	
	//Pasamos los valores que recibimos del programa principal a const char* para poder usar las funciones de MongoDB
	const char* identificador = nombre.c_str();
	const char* key = clave.c_str();
	const char* value = valor.c_str();

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
	
	if (base_seleccionada.empty() || coleccion_seleccionada.empty()) {
		char** lista_bases_disponibles;
		lista_bases_disponibles = mongoc_client_get_database_names_with_opts(cliente, NULL, &error);

		if (lista_bases_disponibles) {
			for (unsigned int i = 1; lista_bases_disponibles[i]; i++) {
				const char* nombre_base = lista_bases_disponibles[i];
				base_de_datos = mongoc_client_get_database(cliente, nombre_base);
				char** lista_colecciones_disponibles;
				lista_colecciones_disponibles = mongoc_database_get_collection_names(base_de_datos, &error);
				if (lista_colecciones_disponibles) {
					for (unsigned int j = 0; lista_colecciones_disponibles[j]; j++) {
						const char* nombre_coleccion = lista_colecciones_disponibles[j];
						coleccion = mongoc_client_get_collection(cliente, nombre_base, nombre_coleccion);

						success = mongoc_collection_find_and_modify_with_opts(coleccion, &consulta, opts, documento, &error);
					}
					mongoc_collection_destroy(coleccion);
				}

			}
			mongoc_database_destroy(base_de_datos);
		}

	}
	else {
		coleccion = mongoc_client_get_collection(cliente, base_seleccionada.c_str(), coleccion_seleccionada.c_str());
		success = mongoc_collection_find_and_modify_with_opts(coleccion, &consulta, opts, documento, &error);
		mongoc_collection_destroy(coleccion);
	}
	
	bson_destroy(documento);
	bson_destroy(update);
	bson_destroy(&consulta);
	mongoc_find_and_modify_opts_destroy(opts);

	if (success) {
		vector <string> atributos;
		atributos.push_back(clave);
		GuardarConfianza(base_seleccionada, coleccion_seleccionada, nombre, atributos, confianza, 1);
	}
	
	return success;
}


//Función equivalente al Botón Modificar Documento Modificando Atributo
void ModificarAtributoDocumento(string nombre, string clave, string valor, string base_seleccionada, string coleccion_seleccionada, string confianza) {
	/*	El botón Añadir Atributo hace exactamente lo mismo que el botón Modificar Atributo
		cuando el documento ya tiene un key igual al que hemos introducido por pantalla		*/
	AñadirAtributoADocumento(nombre, clave, valor, base_seleccionada, coleccion_seleccionada, confianza);

}


//Función equivalente al Botón Modificar Documento Eliminando Atributo
void EliminarAtributoDocumento(string nombre, string clave, string base_seleccionada, string coleccion_seleccionada) {
	
	string ubicacion_consulta = "Consulta.txt";
	CrearFichero(ubicacion_consulta, "identificador", nombre);
	string contenido_identificador = LeerFichero(ubicacion_consulta);
	remove(ubicacion_consulta.c_str());

	const char* json = contenido_identificador.c_str();
	//	Creamos un documento bson con el dato que queremos buscar
	query = bson_new_from_json((const uint8_t*)json, -1, &error);

	if (base_seleccionada.empty() || coleccion_seleccionada.empty()) {
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
						const bson_t* doc;

						while (mongoc_cursor_next(cursor, &doc)) {
							bson_t documento_nuevo;
							bson_init(&documento_nuevo);
							bson_copy_to_excluding_noinit(doc, &documento_nuevo, clave.c_str(), NULL);
							mongoc_collection_delete_many(coleccion, query, NULL, NULL, &error);
							mongoc_collection_insert_one(coleccion, &documento_nuevo, NULL, NULL, &error);
							bson_destroy(&documento_nuevo);
						}
						mongoc_cursor_destroy(cursor);
						mongoc_collection_destroy(coleccion);
					}

				}
				mongoc_database_destroy(base_de_datos);
			}

		}
	}
	else {
		coleccion = mongoc_client_get_collection(cliente, base_seleccionada.c_str(), coleccion_seleccionada.c_str());

		//	Función de MongoDB que comprueba si algún documento de la colección contiene la consulta realizada
		cursor = mongoc_collection_find_with_opts(coleccion, query, NULL, NULL);

		//	Creación de objeto de tipo bson_t para guardar el contenido del documento que coincida
		const bson_t* doc;

		while (mongoc_cursor_next(cursor, &doc)) {
			bson_t documento_nuevo;
			bson_init(&documento_nuevo);
			//Copiamos el contenido de doc (menos el dato que queremos elimianr) a un nuevo documento
			bson_copy_to_excluding_noinit(doc, &documento_nuevo, clave.c_str(), NULL);
			//Eliminamos el documento que vamos a modificar
			mongoc_collection_delete_many(coleccion, query, NULL, NULL, &error);
			//Añadimos el nuevo documento modificado
			mongoc_collection_insert_one(coleccion, &documento_nuevo, NULL, NULL, &error);
			bson_destroy(&documento_nuevo);
		}
		mongoc_cursor_destroy(cursor);
		mongoc_collection_destroy(coleccion);
	}
	bson_destroy(query);

}


//Función equivalente al Botón Eliminar Documento
void EliminarTema(string nombre_base, string nombre_coleccion, string nombre_tema) {
	string ubicacion = "Consulta.txt";
	CrearFichero(ubicacion, "identificador", nombre_tema);
	string contenido_fichero = LeerFichero(ubicacion);
	remove(ubicacion.c_str());

	const char* contenido_documento = contenido_fichero.c_str();

	//	Creamos un documento bson con el dato que queremos buscar
	query = bson_new_from_json((const uint8_t*)contenido_documento, -1, &error);

	if (nombre_base.empty() || nombre_coleccion.empty()) {

		vector <string> Bases_Colecciones = BuscarBaseColeccionDoc(contenido_fichero);
		for (int i = 0; i < Bases_Colecciones.size(); i++) {
			char almohadilla = '#';
			string subcadena;
			int posInit = 0;
			int posFound = Bases_Colecciones[i].find(almohadilla, posInit);
			string base_nombre = Bases_Colecciones[i].substr(posInit, posFound - posInit);
			string coleccion_nombre = Bases_Colecciones[i].substr(posFound + 1, strlen(Bases_Colecciones[i].c_str()));
			coleccion = mongoc_client_get_collection(cliente, base_nombre.c_str(), coleccion_nombre.c_str());
			//Función MongoDB C que elimina todos los documentos de la colección que coincidan con la consulta
			mongoc_collection_delete_many(coleccion, query, NULL, NULL, &error);
			mongoc_collection_destroy(coleccion);
		}
	}
	else {
		coleccion = mongoc_client_get_collection(cliente, nombre_base.c_str(), nombre_coleccion.c_str());
		//Función MongoDB C que elimina todos los documentos de la colección que coincidan con la consulta
		mongoc_collection_delete_many(coleccion, query, NULL, NULL, &error);
		mongoc_collection_destroy(coleccion);
	}
	bson_destroy(query);
}


//Función equivalente al Botón Establecer Relación
void EstablecerRelacion(string nombre_doc, string base_doc, string coleccion_doc, string nombre_doc_atributo, string base_doc_atributo, string coleccion_doc_atributo, string confianza) {
	string ubicacion_consulta = "Consulta.txt";
	CrearFichero(ubicacion_consulta, "identificador", nombre_doc_atributo);
	string contenido_fichero = LeerFichero(ubicacion_consulta);
	remove(ubicacion_consulta.c_str());
	vector <string> contenido_doc_atributo = ExtraerContenidoDocumento(base_doc_atributo, coleccion_doc_atributo, contenido_fichero);

	//{ "_id" : { "$oid" : "60a252e5d158000021000df3" }
	string id;
	int pos;

	pos = contenido_doc_atributo[0].find(':');
	id = contenido_doc_atributo[0].substr(pos + 1, strlen(contenido_doc_atributo[0].c_str()));
	pos = id.find(':');
	id = id.substr(pos + 1, strlen(id.c_str()));
	pos = id.find('"');
	id = id.substr(pos + 1, strlen(id.c_str()));
	pos = id.find('"');
	id = id.substr(0, pos);

	string clave = base_doc_atributo + " " + coleccion_doc_atributo;
	AñadirAtributoADocumento(nombre_doc, clave, id, base_doc, coleccion_doc, confianza);
}


//Función equivalente al Botón Buscar Multimedia
vector <string> BuscarDocumentosMultimedia(string nombre_base) {

	vector <string> documentos_coleccion;

	//Comprobamos que la Base de Datos exista
	if (ComprobacionExistenciaBase(nombre_base) == 1) {
		//Comprobamos que la coleccion pertenezca a la Base de Datos
		if (ColeccionPerteneceABase(nombre_base, "fs.files") == 1) {
			coleccion = mongoc_client_get_collection(cliente, nombre_base.c_str(), "fs.files");

			string ubicacion_consulta = "Consulta.txt";
			CrearFichero(ubicacion_consulta, "tipo de archivo", nombre_base);
			string json_str = LeerFichero(ubicacion_consulta);
			remove(ubicacion_consulta.c_str());

			const char* json = json_str.c_str();
			query = bson_new_from_json((const uint8_t*)json, -1, &error);
			const bson_t* filter = query;
			cursor = mongoc_collection_find_with_opts(coleccion, filter, NULL, NULL);

			const bson_t* doc;
			while (mongoc_cursor_next(cursor, &doc)) {
				//Guardamos el contenido de cada documento de la colección y lo añadimos al vector documentos_coleccion
				string ubicacion = "Consulta.txt";
				ofstream archivo;
				archivo.open(ubicacion);
				archivo << bson_as_canonical_extended_json(doc, NULL);
				archivo.close();
				vector <string> Contenido_Documento = LeerJSON(ubicacion);
				for (int i = 0; i < Contenido_Documento.size(); i++) {
					documentos_coleccion.push_back(Contenido_Documento[i]);
				}
				documentos_coleccion.push_back("findeldocumento");
				remove(ubicacion.c_str());
			}
			mongoc_collection_destroy(coleccion);
			mongoc_cursor_destroy(cursor);
			bson_destroy(query);
		}
	}

	return documentos_coleccion;
}


//Función equivalente al Botón Preguntar Curiosidad
string PreguntarCuriosidad() {
	string pregunta;
	
	//Seleccionamos al azar una Base de Datos
	vector <string> Bases = BasesParaCuriosidad();
	if (Bases.empty()) pregunta = "Todos los documentos están completos";
	else {
		srand(time(NULL));
		int aleatorio;
		aleatorio = rand() % Bases.size();
		string Base_Seleccionada = Bases[aleatorio];

		//Seleccionamos al azar una coleccion
		vector <string> Colecciones = ColeccionesParaCuriosidad(Base_Seleccionada);
		aleatorio = rand() % Colecciones.size();
		string Coleccion_Seleccionada = Colecciones[aleatorio];

		//Seleccionamos al azar un documento
		vector <string> Documentos = DocumentosParaCuriosidad(Base_Seleccionada, Coleccion_Seleccionada);
		aleatorio = rand() % Documentos.size();
		string Documento_Seleccionado = Documentos[aleatorio];

		//Comprobamos qué atributos le faltan al documento seleccionado
		vector <string> AtributosColeccionSeleccionada = AtributosComunesColeccion(Base_Seleccionada, Coleccion_Seleccionada);
		vector <string> AtributosDocumentoSeleccionado = ListaAtributosDisponibles(Base_Seleccionada, Coleccion_Seleccionada, Documento_Seleccionado);
		vector <string> AtributosFaltan;
		vector <string> AtributosAAnalizar = AtributosComunesPorcentaje(75, AtributosColeccionSeleccionada);
		AtributosFaltan = AtributosQueFaltan(AtributosAAnalizar, AtributosDocumentoSeleccionado);
		if (AtributosFaltan.empty()) {
			AtributosAAnalizar = AtributosComunesPorcentaje(50, AtributosColeccionSeleccionada);
			AtributosFaltan = AtributosQueFaltan(AtributosAAnalizar, AtributosDocumentoSeleccionado);
		}

		aleatorio = rand() % AtributosFaltan.size();
		string atributo_Seleccionado = AtributosFaltan[aleatorio];
		pregunta = "¿Cuál es el/la " + atributo_Seleccionado + " de " + Documento_Seleccionado + "?";
		pregunta = pregunta + '#' + atributo_Seleccionado + '#' + Documento_Seleccionado + '#' + Coleccion_Seleccionada + '#' + Base_Seleccionada;
	}
	return pregunta;
}