/*	TFG:	Sistema de conocimiento para rob�tica cognitiva social
			Grado en Ingenier�a en Tecnolog�as Industriales
			Sof�a Hernang�mez Flores
			2021

	Tutor:	Daniel Gal�n Vicente
*/


#include "pch.h"	//Archivo de precompilado
#include "Botones_BaseDeDatos.h"


//Declaraci�n variables globales que se utilizan en este archivo
extern mongoc_client_t* cliente;
extern mongoc_database_t* base_de_datos;
extern mongoc_collection_t* coleccion;
extern bson_error_t error;


//Funci�n equivalente al bot�n A�adir Base de Datos
void CrearBaseDeDatos(string N_Base, string N_Coleccion) {
	//Comprobamos que no exista una Base de Datos con el mismo nombre que la que queremos crear
	if (ComprobacionExistenciaBase(N_Base) == 0) {
		
		//Creaci�n Base de Datos
		base_de_datos = mongoc_client_get_database(cliente, N_Base.c_str());
		mongoc_database_drop_with_opts(base_de_datos, NULL, &error);
		
		//Creaci�n colecci�n
		coleccion = mongoc_database_create_collection(base_de_datos, N_Coleccion.c_str(), NULL, &error);
		
		//Liberaci�n de memoria
		mongoc_collection_destroy(coleccion);
		mongoc_database_destroy(base_de_datos);
	}
}


//Funci�n equivalente al bot�n Eliminar Base de Datos
void EliminarBaseDeDatosExistente(string Base) {
	//Comprobamos la existencia de la Base de Datos que el usuario desea eliminar
	if (ComprobacionExistenciaBase(Base) == 1) {
		//Comprobamos que no se trate de una de las Bases de Datos inherentes a MongoDB
		if (BaseInherenteMongoDB(Base) == 0) {
			
			//Para eliminar una base de datos basta con eliminar todas las colecciones que contiene
			base_de_datos = mongoc_client_get_database(cliente, Base.c_str());
			char** lista_colecciones; //Variable para guardar la lista de colecciones de cada base de datos
			
			//	Funci�n MongoDB C que obtiene el nombre de las colecciones disponibles en la base de datos
			lista_colecciones = mongoc_database_get_collection_names(base_de_datos, &error);

			if (lista_colecciones) {
				//	Bucle para eliminar las colecciones de la base de datos seleccionada
				for (unsigned int i = 0; lista_colecciones[i]; i++) {
					coleccion = mongoc_client_get_collection(cliente, Base.c_str(), lista_colecciones[i]);

					//	Funci�n de MongoDB C que elimina una colecci�n
					mongoc_collection_drop_with_opts(coleccion, NULL, &error);

					mongoc_collection_destroy(coleccion);
				}
				bson_strfreev(lista_colecciones);
			}
			mongoc_database_destroy(base_de_datos);
		}
	}
}