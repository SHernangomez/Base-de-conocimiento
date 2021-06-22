/*	TFG:	Sistema de conocimiento para rob�tica cognitiva social
			Grado en Ingenier�a en Tecnolog�as Industriales
			Sof�a Hernang�mez Flores
			2021

	Tutor:	Daniel Gal�n Vicente
*/


/*	IMPORTANTE:	Para que la parte de la aplicaci�n que utiliza MongoDB funcione,
				debemos tener ejecut�ndose en todo momento mongod.exe				*/


#include "pch.h"	//Archivo de precompilado
#include "PanelDeInicio.h"	//Panel principal de la aplicaci�n


using namespace System::Windows::Forms;


//Variables GLOBALES necesarias para utilizar la base de datos MongoDB

	//Cliente	
	mongoc_client_t* cliente;

	//Base de Datos
	mongoc_database_t* base_de_datos;

	//Colecci�n
	mongoc_collection_t* coleccion;

	//Cursor
	mongoc_cursor_t* cursor;

	//Estructura con dominio de error, c�digo de error y mensaje
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
	
//Cadena de conexi�n URI
	//Variable char* con el esquema de conexi�n URI que utilizaremos en la aplicaci�n
	const char* uri_string = "mongodb://localhost:27017";
	//Abstracci�n sobre el formato URI de conexi�n MongoDB
	mongoc_uri_t* uri;


//Inicializaci�n controlador MongoDB C
	mongoc_init();


//Conexi�n con la base de conocimiento mediante la creaci�n de URI y Cliente	
	//Creaci�n segura de un objeto MongoDB URI
	uri = mongoc_uri_new_with_error(uri_string, &error);
		if (!uri) return EXIT_FAILURE;

	//Creaci�n segura de una instancia MongoDB Cliente
	cliente = mongoc_client_new_from_uri(uri);
		if (!cliente) return EXIT_FAILURE;


//Apertura formulario principal de la aplicaci�n																  	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew CppCLRWinformsProjekt::PanelDeInicio());

}