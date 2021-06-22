/*	TFG:	Sistema de conocimiento para robótica cognitiva social
			Grado en Ingeniería en Tecnologías Industriales
			Sofía Hernangómez Flores
			2021

	Tutor:	Daniel Galán Vicente
*/


#include "pch.h"	//Archivo de precompilado
#include "Botones_Coleccion.h"


//Declaración variables globales que se utilizan en este archivo
extern mongoc_client_t* cliente;
extern mongoc_database_t* base_de_datos;
extern mongoc_collection_t* coleccion;
extern bson_error_t error;


//Función equivalente al Botón Añadir Coleccion
void CrearColeccion(string Base, string Nueva_Coleccion) {
	//Comprobamos la existencia de la Base de Datos a la que queremos añadir una colección
	if (ComprobacionExistenciaBase(Base) == 1) {
		//Comprobamos que no se trate de una Base de Datos inherente a MongoDB
		if (BaseInherenteMongoDB(Base) == 0) {
			
			base_de_datos = mongoc_client_get_database(cliente, Base.c_str());
			
			//Comprobamos que no exista una colección con el nombre introducido en la Base de Datos especificada
			if (ColeccionPerteneceABase(Base, Nueva_Coleccion) == 0) {
			
				//Función de MongoDB C que añade una colección a una Base de Datos
				coleccion = mongoc_database_create_collection(base_de_datos, Nueva_Coleccion.c_str(), NULL, &error);

				mongoc_collection_destroy(coleccion);
			}
		}
	}
}


//Función equivalente al Botón Eliminar Coleccion
void EliminarColeccionExistente(string Base, string Coleccion) {
	//Comprobamos la existencia de la Base de Datos en la que se encuentra la colección que se desea eliminar
	if (ComprobacionExistenciaBase(Base) == 1) {
		//Comprobamos que no se trate de una de las bases inherentes a MongoDB
		if (BaseInherenteMongoDB(Base) == 0) {

			const char* nombre_base = Base.c_str();
			base_de_datos = mongoc_client_get_database(cliente, nombre_base);

			//Comprobamos la existencia de la colección que se desea eliminar
			if (ColeccionPerteneceABase(Base, Coleccion) == 1) {

				coleccion = mongoc_client_get_collection(cliente, Base.c_str(), Coleccion.c_str());
				
				//Función de MongoDB C que permite eliminar una colección
				mongoc_collection_drop_with_opts(coleccion, NULL, &error);

				mongoc_collection_destroy(coleccion);
			}
		}
	}
}