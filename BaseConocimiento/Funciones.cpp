/*	TFG:	Sistema de conocimiento para robótica cognitiva social
			Grado en Ingeniería en Tecnologías Industriales
			Sofía Hernangómez Flores
			2021

	Tutor:	Daniel Galán Vicente
*/


//Archivo con las funciones necesarias para el correcto funcionamiento del programa


#include "pch.h"	//	Archivo de precompilado
#include "Funciones.h"


extern bson_error_t error;
extern mongoc_client_t* cliente;
extern mongoc_database_t* base_de_datos;
extern mongoc_collection_t* coleccion;
extern bson_t* query;
extern mongoc_cursor_t* cursor;


extern mongoc_gridfs_bucket_t* documento_gridfs;


//Función para pasar de system string a std basic string
//Necesaria en los formularios al introducir datos por pantalla
string toStandardString(System::String^ string) {
	using System::Runtime::InteropServices::Marshal;
	System::IntPtr pointer = Marshal::StringToHGlobalAnsi(string);
	char* charPointer = reinterpret_cast<char*>(pointer.ToPointer());
	std::string returnString(charPointer, string->Length);
	Marshal::FreeHGlobal(pointer);
	return returnString;
}




//Función que separa los atributos de un string JSON
vector <string> SepararLineasJSON(string documento_json) {
	char coma = ',';
	string subcadena;
	vector <string> atributos;
	int posInit = 0;
	int posFound = 0;
	while (posFound >= 0) {
		posFound = documento_json.find(coma, posInit);
		subcadena = documento_json.substr(posInit, posFound + 1 - posInit);
		posInit = posFound + 1;
		atributos.push_back(subcadena);
	}
	return atributos;
}


//Función que lee un archivo JSON
vector <string> LeerJSON(string ubicacion){
	ifstream fichero;
	char letra;
	char coma_c = ',';
	string lineaFichero;
	vector <string> datos_fichero;

	fichero.open(ubicacion, ios::in);
	while (!fichero.eof()) {
		getline(fichero, lineaFichero, coma_c);
		datos_fichero.push_back(lineaFichero);
	}
	fichero.close();

	return datos_fichero;
}


//Función que comprueba si se trata de una Base de Datos que contiene archivos multimedia
int BaseDeDatosMultimedia(string nombre_base) {
	if (strcmpi(nombre_base.c_str(), "imagen") == 0) return 1;
	else if (strcmpi(nombre_base.c_str(), "video") == 0) return 1;
	else if (strcmpi(nombre_base.c_str(), "audio") == 0) return 1;
	else if (strcmpi(nombre_base.c_str(), "texto") == 0) return 1;
	else return 0;
}


//Función que comprueba si se trata de un atributo inherente (_id, base de datos, coleccion)
int AtributoInherente(string nombre_atributo) {
	if (strcmpi(nombre_atributo.c_str(), "_id") == 0) return 1;
	else if (strcmpi(nombre_atributo.c_str(), "base de datos") == 0) return 1;
	else if (strcmpi(nombre_atributo.c_str(), "coleccion") == 0) return 1;
	else return 0;
}


//Funcion que comprueba si existe un elemento coincidente en un vector <string>
int ElementoCoincidente(string elemento, vector <string> vector_de_elementos) {
	for (int i = 0; i < vector_de_elementos.size(); i++) {
		if (strcmpi(vector_de_elementos[i].c_str(), elemento.c_str()) == 0) return 1;
	}
	return 0;
}



