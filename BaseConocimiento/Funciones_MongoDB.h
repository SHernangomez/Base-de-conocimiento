/*	TFG:	Sistema de conocimiento para robótica cognitiva social
			Grado en Ingeniería en Tecnologías Industriales
			Sofía Hernangómez Flores
			2021

	Tutor:	Daniel Galán Vicente
*/


#pragma once	//	Directiva para asegurar que el código fuente sea incluido una sola vez

#include "pch.h"
#include <vector>

using namespace std;


//Función que comprueba si una Base de Datos existe o no
int ComprobacionExistenciaBase(string);

//Función que comprueba si una colección existe o no
int ComprobacionExistenciaColeccion(string);

//Función que comprueba si estamos intentando modificar una Base de Datos inherente a MongoDB
int BaseInherenteMongoDB(string);

//Función que comprueba si una colección pertenece a una Base de Datos dada o no
int ColeccionPerteneceABase(string, string);

//Función para saber si existe un bson coincidente con la consulta en una Base de Datos y Coleccion dadas
int BuscarBSONCoincidente(string, string, string);

//Función que devuelve el nombre de las colecciones a las que pertenece un documento
vector <string> BuscarBaseColeccionDoc(string);

//Función que devuelve el nombre de las Bases de Datos a las que pertenece una coleccion
vector <string> BuscarBaseColeccion(string);

//Función que devuelve el contenido de un documento
vector <string> ExtraerContenidoDocumento(string, string, string);

//Función que devuelve el número de documentos que hay en una colección
double NumeroDeDocumentosColeccion(string nombre_base, string nombre_coleccion);

//Función que devuelve el número de colecciones que hay en una Base de Datos
double NumeroDeColecciones(string nombre_base);

//Función que devuelve el nombre de las Bases de Datos disponibles
vector <string> ListaBasesDeDatosDisponibles();

//Función que devuelve el nombre de las colecciones disponibles en una Base de Datos
vector <string> ListaColeccionesDisponibles(string nombre_base);

//Función que devuelve el nombre de los documentos disponibles en una colección
vector <string> ListaDocumentosDisponibles(string nombre_base, string nombre_coleccion);

//Función que devuelve el nombre de los archivos multimedia disponibles en una Base De Datos
vector <string> ListaArchivosMultimediaDisponibles(string tipo_documento);

//Función que devuelve el nombre de los atributos (clave) contenidos en un documento
vector <string> ListaAtributosDisponibles(string nombre_base, string nombre_coleccion, string nombre_documento);

//Función que devuelve el nombre de los atributos comunes de una colección
vector <string> AtributosComunesColeccion(string nombre_base, string nombre_coleccion);

//Función que devuelve el nombre de los atributos presentes en el % indicado
vector <string>	AtributosComunesPorcentaje(double porcentaje, vector <string> atributos);

//Función que devuelve los atributos que le faltan a un documento
vector <string>	AtributosQueFaltan(vector <string> atributos_a_analizar, vector <string> lista_atributos);

//Función que devuelve el nombre de los atributos comunes de una Base de Datos
vector <string> AtributosComunesBaseDeDatos(string nombre_base);

//Función que devuelve las Bases de Datos que contienen colecciones en las que haya más de un documento
vector <string> BasesParaCuriosidad();

//Función que devuelve las colecciones que contienen más de un documento
vector <string> ColeccionesParaCuriosidad(string nombre_base);

//Función que devuelve los documentos a los que les falta algún atributo
vector <string> DocumentosParaCuriosidad(string nombre_base, string nombre_coleccion);

//Función que guarda la confianza de los datos introducidos
void GuardarConfianza(string nombre_base, string nombre_coleccion, string nombre_documento, vector <string> atributos, string confianza, int modo);
//modo 0 Nuevo documento; 1 Añadir Atributo o Modificar atributo
