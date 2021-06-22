/*	TFG:	Sistema de conocimiento para rob�tica cognitiva social
			Grado en Ingenier�a en Tecnolog�as Industriales
			Sof�a Hernang�mez Flores
			2021

	Tutor:	Daniel Gal�n Vicente
*/


#pragma once	//	Directiva para asegurar que el c�digo fuente sea incluido una sola vez

#include "pch.h"
#include <vector>

using namespace std;


//Funci�n que comprueba si una Base de Datos existe o no
int ComprobacionExistenciaBase(string);

//Funci�n que comprueba si una colecci�n existe o no
int ComprobacionExistenciaColeccion(string);

//Funci�n que comprueba si estamos intentando modificar una Base de Datos inherente a MongoDB
int BaseInherenteMongoDB(string);

//Funci�n que comprueba si una colecci�n pertenece a una Base de Datos dada o no
int ColeccionPerteneceABase(string, string);

//Funci�n para saber si existe un bson coincidente con la consulta en una Base de Datos y Coleccion dadas
int BuscarBSONCoincidente(string, string, string);

//Funci�n que devuelve el nombre de las colecciones a las que pertenece un documento
vector <string> BuscarBaseColeccionDoc(string);

//Funci�n que devuelve el nombre de las Bases de Datos a las que pertenece una coleccion
vector <string> BuscarBaseColeccion(string);

//Funci�n que devuelve el contenido de un documento
vector <string> ExtraerContenidoDocumento(string, string, string);

//Funci�n que devuelve el n�mero de documentos que hay en una colecci�n
double NumeroDeDocumentosColeccion(string nombre_base, string nombre_coleccion);

//Funci�n que devuelve el n�mero de colecciones que hay en una Base de Datos
double NumeroDeColecciones(string nombre_base);

//Funci�n que devuelve el nombre de las Bases de Datos disponibles
vector <string> ListaBasesDeDatosDisponibles();

//Funci�n que devuelve el nombre de las colecciones disponibles en una Base de Datos
vector <string> ListaColeccionesDisponibles(string nombre_base);

//Funci�n que devuelve el nombre de los documentos disponibles en una colecci�n
vector <string> ListaDocumentosDisponibles(string nombre_base, string nombre_coleccion);

//Funci�n que devuelve el nombre de los archivos multimedia disponibles en una Base De Datos
vector <string> ListaArchivosMultimediaDisponibles(string tipo_documento);

//Funci�n que devuelve el nombre de los atributos (clave) contenidos en un documento
vector <string> ListaAtributosDisponibles(string nombre_base, string nombre_coleccion, string nombre_documento);

//Funci�n que devuelve el nombre de los atributos comunes de una colecci�n
vector <string> AtributosComunesColeccion(string nombre_base, string nombre_coleccion);

//Funci�n que devuelve el nombre de los atributos presentes en el % indicado
vector <string>	AtributosComunesPorcentaje(double porcentaje, vector <string> atributos);

//Funci�n que devuelve los atributos que le faltan a un documento
vector <string>	AtributosQueFaltan(vector <string> atributos_a_analizar, vector <string> lista_atributos);

//Funci�n que devuelve el nombre de los atributos comunes de una Base de Datos
vector <string> AtributosComunesBaseDeDatos(string nombre_base);

//Funci�n que devuelve las Bases de Datos que contienen colecciones en las que haya m�s de un documento
vector <string> BasesParaCuriosidad();

//Funci�n que devuelve las colecciones que contienen m�s de un documento
vector <string> ColeccionesParaCuriosidad(string nombre_base);

//Funci�n que devuelve los documentos a los que les falta alg�n atributo
vector <string> DocumentosParaCuriosidad(string nombre_base, string nombre_coleccion);

//Funci�n que guarda la confianza de los datos introducidos
void GuardarConfianza(string nombre_base, string nombre_coleccion, string nombre_documento, vector <string> atributos, string confianza, int modo);
//modo 0 Nuevo documento; 1 A�adir Atributo o Modificar atributo
