/*	TFG:	Sistema de conocimiento para robótica cognitiva social
			Grado en Ingeniería en Tecnologías Industriales
			Sofía Hernangómez Flores
			2021

	Tutor:	Daniel Galán Vicente
*/


/*	IMPORTANTE:	Para que la parte de la aplicación que utiliza MongoDB funcione,
				debemos tener ejecutándose en todo momento mongod.exe				*/


#include "pch.h"	//Archivo de precompilado
#include "PanelDeInicio.h"	//Panel principal de la aplicación


using namespace System::Windows::Forms;


//Variables GLOBALES necesarias para utilizar la base de datos MongoDB

	//Cliente	
	mongoc_client_t* cliente;

	//Base de Datos
	mongoc_database_t* base_de_datos;

	//Colección
	mongoc_collection_t* coleccion;

	//Cursor
	mongoc_cursor_t* cursor;

	//Estructura con dominio de error, código de error y mensaje
	bson_error_t error;

	//Documento BSON
	bson_t* documento;
	bson_t* query;

	//Documento GridFS
	mongoc_stream_t* archivo_stream;
	mongoc_gridfs_bucket_t* documento_gridfs;
	bson_value_t id_archivo;
		

	string Base_Sel;
	string Coleccion_Sel;
	string id_introducido;
	
	string ruta;
	string extension_archivo;
	string ruta_descarga;
	const char* tipo_de_archivo;

	string clave_curiosidad;
	string documento_curiosidad;

	string confianza_info = "alta";



[STAThread]
int main() {
	
//Cadena de conexión URI
	//Variable char* con el esquema de conexión URI que utilizaremos en la aplicación
	const char* uri_string = "mongodb://localhost:27017";
	//Abstracción sobre el formato URI de conexión MongoDB
	mongoc_uri_t* uri;


//Inicialización controlador MongoDB C
	mongoc_init();


//Conexión con la base de conocimiento mediante la creación de URI y Cliente	
	//Creación segura de un objeto MongoDB URI
	uri = mongoc_uri_new_with_error(uri_string, &error);
		if (!uri) return EXIT_FAILURE;

	//Creación segura de una instancia MongoDB Cliente
	cliente = mongoc_client_new_from_uri(uri);
		if (!cliente) return EXIT_FAILURE;


//Apertura formulario principal de la aplicación																  	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew CppCLRWinformsProjekt::PanelDeInicio());

}