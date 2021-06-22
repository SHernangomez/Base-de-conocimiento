/*	TFG:	Sistema de conocimiento para robótica cognitiva social
			Grado en Ingeniería en Tecnologías Industriales
			Sofía Hernangómez Flores
			2021

	Tutor:	Daniel Galán Vicente
*/


#include "pch.h"	//Archivo de precompilado
#include "Botones_ArchivoMultimedia.h"
#include "Botones_Documento.h"


#include "json/json.h"
#include <windows.h>
#include <ShellAPI.h>
#pragma comment (lib, "shell32.lib")


using namespace Json;


//Declaración variables globales que se utilizan en este archivo
extern mongoc_client_t* cliente;
extern mongoc_database_t* base_de_datos;
extern mongoc_collection_t* coleccion;
extern bson_t* documento;
extern bson_error_t error;
extern bson_t* query;
extern mongoc_cursor_t* cursor;
extern mongoc_stream_t* archivo_stream;
extern mongoc_gridfs_bucket_t* documento_gridfs;
extern bson_value_t id_archivo;


//Función equivalente al botón Añadir archivo multimedia
void AñadirArchivoMultimedia(string ruta, const char* tipo_de_archivo, string nombre_doc) {
	base_de_datos = mongoc_client_get_database(cliente, tipo_de_archivo);
	
	//Creamos nuevo gridfs
	documento_gridfs = mongoc_gridfs_bucket_new(base_de_datos, NULL, NULL, &error);
	archivo_stream = mongoc_stream_file_new_for_path(ruta.c_str(), O_RDONLY, 0);
	
	//Añadimos el documento gridfs a la base de datos correspondiente
	mongoc_gridfs_bucket_upload_from_stream(documento_gridfs, nombre_doc.c_str(), archivo_stream, NULL, &id_archivo, &error);
	
	mongoc_stream_close(archivo_stream);
	mongoc_stream_destroy(archivo_stream);
	mongoc_gridfs_bucket_destroy(documento_gridfs);
	mongoc_database_destroy(base_de_datos);

	string tipo_archivo_str = tipo_de_archivo;
	AñadirAtributoMultimedia(tipo_de_archivo, nombre_doc, "tipo de archivo", tipo_archivo_str);
}


//Función que añade la extensión del archivo al documento que se encuentra en fs.files
//Necesario para cuando queramos descargar el archivo
void AñadirAtributoMultimedia(const char* tipo_de_archivo, string nombre_doc, string clave, string valor) {
	
	//Pasamos los valores que recibimos del programa principal a const char* para poder usar las funciones de MongoDB
	const char* filename = nombre_doc.c_str();
	const char* key = clave.c_str();
	const char* value = valor.c_str();

	bson_t consulta = BSON_INITIALIZER;
	bson_t* update;
	mongoc_find_and_modify_opts_t* opts;

	bson_error_t error;

	bool success = false;


	//Creamos un BSON (consulta) con el dato que queremos buscar
	BSON_APPEND_UTF8(&consulta, "filename", filename);

	//Creamos un BSON (update) con el dato que queremos añadir
	update = BCON_NEW("$set", "{", key, BCON_UTF8(value), "}");

	//Creamos un mongoc_find_and_modify_opts_t y establecemos las opciones
	opts = mongoc_find_and_modify_opts_new();
	mongoc_find_and_modify_opts_set_update(opts, update);
	mongoc_find_and_modify_opts_set_flags(opts, MONGOC_FIND_AND_MODIFY_RETURN_NEW);

	
	coleccion = mongoc_client_get_collection(cliente, tipo_de_archivo, "fs.files");
	success = mongoc_collection_find_and_modify_with_opts(coleccion, &consulta, opts, documento, &error);
	mongoc_collection_destroy(coleccion);

	bson_destroy(documento);
	bson_destroy(update);
	bson_destroy(&consulta);
	mongoc_find_and_modify_opts_destroy(opts);
}


//Función equivalente al botón Eliminar archivo multimedia
void EliminarArchivoMultimedia(string base, string nombre) {

	base_de_datos = mongoc_client_get_database(cliente, base.c_str());
	documento_gridfs = mongoc_gridfs_bucket_new(base_de_datos, NULL, NULL, &error);

	string ubicacion = "Consulta.txt";
	CrearFichero(ubicacion, "filename", nombre);
	string contenido_fichero = LeerFichero(ubicacion);
	remove(ubicacion.c_str());
	const char* contenido_documento = contenido_fichero.c_str();
	query = bson_new_from_json((const uint8_t*)contenido_documento, -1, &error);

	coleccion = mongoc_client_get_collection(cliente, base.c_str(), "fs.files");
	cursor = mongoc_collection_find_with_opts(coleccion, query, NULL, NULL);

	//Copiamos el contenido para saber el id de fs.files
	vector <string> docu;
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

	//{ "_id" : { "$oid" : "60a252e5d158000021000df3" }
	string id;
	int pos;

	pos = docu[0].find(':');
	id = docu[0].substr(pos + 1, strlen(docu[0].c_str()));
	pos = id.find(':');
	id = id.substr(pos + 1, strlen(id.c_str()));
	pos = id.find('"');
	id = id.substr(pos + 1, strlen(id.c_str()));
	pos = id.find('"');
	id = id.substr(0, pos);

	const char* cadena = id.c_str();

	bson_oid_t oid_id_a_eliminar;
	bson_oid_init_from_string(&oid_id_a_eliminar, cadena);

	bson_value_t id_a_eliminar;
	id_a_eliminar.value_type = BSON_TYPE_OID;
	id_a_eliminar.value.v_oid = oid_id_a_eliminar;

	mongoc_gridfs_bucket_delete_by_id(documento_gridfs, &id_a_eliminar, &error);

	bson_destroy(query);
	mongoc_cursor_destroy(cursor);
	mongoc_gridfs_bucket_destroy(documento_gridfs);
	mongoc_collection_destroy(coleccion);
	mongoc_database_destroy(base_de_datos);

}


//Función equivalente al botón Consultar Multimedia por ID
void ConsultarArchivoMultimedia(string id_consulta, string ruta) {

	//Buscamos la Base de Datos (tipo de documento)
	string ubicacion = "Consulta.txt";
	ofstream archivo;
	archivo.open(ubicacion);

	//{ "_id" : { "$oid" : "60a252e5d158000021000df3" }
	archivo << "{\n\t\"_id\" : { \"$oid\" : " << "\"" << id_consulta.c_str() << "\"" << "}\n}" << endl;
	archivo.close();

	string contenido_fichero = LeerFichero(ubicacion);
	remove(ubicacion.c_str());

	vector <string> BaseColeccion = BuscarBaseColeccionDoc(contenido_fichero);

	char almohadilla = '#';
	string subcadena;
	int posInit = 0;
	int posFound = BaseColeccion[0].find(almohadilla, posInit);
	string nombre_base = BaseColeccion[0].substr(posInit, posFound - posInit);

	string ruta_str = DescargarArchivoMultimedia(nombre_base, id_consulta, ruta);

	std::wstring ruta_w = std::wstring(ruta_str.begin(), ruta_str.end());

	ShellExecute(NULL, L"open", (LPCWSTR) ruta_w.c_str(), NULL, NULL, SW_MAXIMIZE);
}


//Función equivalente al botón Consultar Multimedia por Nombre
void ConsultarArchivoMultimediaPorNombre(string base, string nombre, string ruta) {
	//Buscamos el id
	base_de_datos = mongoc_client_get_database(cliente, base.c_str());
	documento_gridfs = mongoc_gridfs_bucket_new(base_de_datos, NULL, NULL, &error);
	string ubicacion = "Consulta.txt";
	ofstream archivo;
	archivo.open(ubicacion);
	archivo << "{\n\t\"filename\" : " << "\"" << nombre.c_str() << "\"" << "\n}" << endl;
	archivo.close();
	string contenido_fichero = LeerFichero(ubicacion);
	remove(ubicacion.c_str());
	
	vector <string> contenido = ExtraerContenidoDocumento(base, "fs.files", contenido_fichero);

	//{ "_id" : { "$oid" : "60a252e5d158000021000df3" }
	string id;
	int pos;

	pos = contenido[0].find(':');
	id = contenido[0].substr(pos + 1, strlen(contenido[0].c_str()));
	pos = id.find(':');
	id = id.substr(pos + 1, strlen(id.c_str()));
	pos = id.find('"');
	id = id.substr(pos + 1, strlen(id.c_str()));
	pos = id.find('"');
	id = id.substr(0, pos);

	string ruta_str = DescargarArchivoMultimedia(base, id, ruta);

	std::wstring ruta_w = std::wstring(ruta_str.begin(), ruta_str.end());

	ShellExecute(NULL, L"open", (LPCWSTR)ruta_w.c_str(), NULL, NULL, SW_MAXIMIZE);

}


//Función que descarga al ordenador un archivo multimedia de la Base de Datos (para poder abrirlo y visualizarlo)
string DescargarArchivoMultimedia(string base, string id_consulta, string ruta) {
	
	base_de_datos = mongoc_client_get_database(cliente, base.c_str());
	documento_gridfs = mongoc_gridfs_bucket_new(base_de_datos, NULL, NULL, &error);
	
	const char* cadena = id_consulta.c_str();
	bson_oid_t oid_id_consulta;
	bson_oid_init_from_string(&oid_id_consulta, cadena);

	bson_value_t id_a_consultar;
	id_a_consultar.value_type = BSON_TYPE_OID;
	id_a_consultar.value.v_oid = oid_id_consulta;


	string ubicacion = "Consulta.txt";
	ofstream archivo;
	archivo.open(ubicacion);
	archivo << "{\n\t\"_id\" : { \"$oid\" : " << "\"" << id_consulta.c_str() << "\"" << "}\n}" << endl;
	archivo.close();
	string contenido_fichero = LeerFichero(ubicacion);
	remove(ubicacion.c_str());

	const char* json = contenido_fichero.c_str();
	query = bson_new_from_json((const uint8_t*)json, -1, &error);
	coleccion = mongoc_client_get_collection(cliente, base.c_str(), "fs.files");
	cursor = mongoc_collection_find_with_opts(coleccion, query, NULL, NULL);
	
	const bson_t* doc;
	string ubicacion_json = "Consulta.json";

	while (mongoc_cursor_next(cursor, &doc)) {
		ofstream archivo;
		archivo.open(ubicacion_json);
		archivo << "[" << bson_as_canonical_extended_json(doc, NULL) << "]";
		archivo.close();
	}

	string documento_json;

	ifstream fichero;
	string linea = "";
	fichero.open(ubicacion_json);
	while (!fichero.eof()) {
		getline(fichero, linea);
		documento_json += linea;
	}

	fichero.close();
	remove(ubicacion.c_str());

	Reader reader;
	Value atributo;

	string nombre;
	string extension;
	
	if (reader.parse(documento_json, atributo)) {
		nombre = atributo[0]["filename"].asString();
		extension = atributo[0]["extension"].asString();
	}
	
	ruta = ruta + "\\" + nombre + extension;

	WIN32_FIND_DATA fd;
	wstring ruta_busqueda_w(ruta.begin(), ruta.end());
	HANDLE hFind = ::FindFirstFile((LPCWSTR)ruta_busqueda_w.c_str(), &fd);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			// read all (real) files in current folder
			// , delete '!' read other 2 default folder . and ..
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				ifstream archivo(ruta.c_str());
				if (archivo.is_open()) {
					archivo.close();
				}
				DeleteFile((LPCWSTR)ruta_busqueda_w.c_str());
			}
		} while (::FindNextFile(hFind, &fd));
		::FindClose(hFind);
	}


	archivo_stream = mongoc_stream_file_new_for_path(ruta.c_str(), O_CREAT | O_RDWR, 0);
	mongoc_gridfs_bucket_download_to_stream(documento_gridfs, &id_a_consultar, archivo_stream, &error);
	mongoc_stream_close(archivo_stream);
	mongoc_stream_destroy(archivo_stream);

	return ruta;
}


//Función equivalente al botón Establecer relación
void EstablecerRelacionMultimedia(string nombre_doc, string base_doc, string coleccion_doc, string clave_atributo, string nombre_doc_atributo, string base_doc_atributo, string coleccion_doc_atributo, string confianza) {
	string ubicacion_consulta = "Consulta.txt";
	CrearFichero(ubicacion_consulta, "filename", nombre_doc_atributo);
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

	AñadirAtributoADocumento(nombre_doc, clave_atributo, nombre_doc_atributo, base_doc, coleccion_doc, confianza);
	AñadirAtributoADocumento(nombre_doc, nombre_doc_atributo, id, base_doc, coleccion_doc, confianza);
}