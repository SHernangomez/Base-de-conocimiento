/*	TFG:	Sistema de conocimiento para rob�tica cognitiva social
			Grado en Ingenier�a en Tecnolog�as Industriales
			Sof�a Hernang�mez Flores
			2021

	Tutor:	Daniel Gal�n Vicente
*/


#include "pch.h"	//Archivo de precompilado
#include "Botones_Coleccion.h"


//Declaraci�n variables globales que se utilizan en este archivo
extern mongoc_client_t* cliente;
extern mongoc_database_t* base_de_datos;
extern mongoc_collection_t* coleccion;
extern bson_error_t error;


//Funci�n equivalente al Bot�n A�adir Coleccion
void CrearColeccion(string Base, string Nueva_Coleccion) {
	//Comprobamos la existencia de la Base de Datos a la que queremos a�adir una colecci�n
	if (ComprobacionExistenciaBase(Base) == 1) {
		//Comprobamos que no se trate de una Base de Datos inherente a MongoDB
		if (BaseInherenteMongoDB(Base) == 0) {
			
			base_de_datos = mongoc_client_get_database(cliente, Base.c_str());
			
			//Comprobamos que no exista una colecci�n con el nombre introducido en la Base de Datos especificada
			if (ColeccionPerteneceABase(Base, Nueva_Coleccion) == 0) {
			
				//Funci�n de MongoDB C que a�ade una colecci�n a una Base de Datos
				coleccion = mongoc_database_create_collection(base_de_datos, Nueva_Coleccion.c_str(), NULL, &error);

				mongoc_collection_destroy(coleccion);
			}
		}
	}
}


//Funci�n equivalente al Bot�n Eliminar Coleccion
void EliminarColeccionExistente(string Base, string Coleccion) {
	//Comprobamos la existencia de la Base de Datos en la que se encuentra la colecci�n que se desea eliminar
	if (ComprobacionExistenciaBase(Base) == 1) {
		//Comprobamos que no se trate de una de las bases inherentes a MongoDB
		if (BaseInherenteMongoDB(Base) == 0) {

			const char* nombre_base = Base.c_str();
			base_de_datos = mongoc_client_get_database(cliente, nombre_base);

			//Comprobamos la existencia de la colecci�n que se desea eliminar
			if (ColeccionPerteneceABase(Base, Coleccion) == 1) {

				coleccion = mongoc_client_get_collection(cliente, Base.c_str(), Coleccion.c_str());
				
				//Funci�n de MongoDB C que permite eliminar una colecci�n
				mongoc_collection_drop_with_opts(coleccion, NULL, &error);

				mongoc_collection_destroy(coleccion);
			}
		}
	}
}