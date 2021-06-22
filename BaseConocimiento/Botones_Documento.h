/*	TFG:	Sistema de conocimiento para rob�tica cognitiva social
			Grado en Ingenier�a en Tecnolog�as Industriales
			Sof�a Hernang�mez Flores
			2021

	Tutor:	Daniel Gal�n Vicente
*/


#pragma once	//	Directiva para asegurar que el c�digo fuente sea incluido una sola vez


#include "pch.h"	//Archivo de precompilado

//Archivo de encabezamiento con funciones generales que se utilizan en el proyecto
#include "Funciones.h"
#include "Funciones_MongoDB.h"

#include <bson/bson.h>

//Archivo de encabezamiento con funciones relativas a files que se utilizan en el proyecto
#include "Funciones_Archivos.h"

#include <vector>


#include <json/json.h>



using namespace std;

//Funci�n equivalente al Bot�n A�adir Documento
void CrearDocumento(string Base, string Coleccion, string nombre, vector <string> atributos, string confianza);

//Funci�n equivalente al Bot�n Buscar por colecci�n
vector <string> BuscarDocumentosColeccion(string, string);

//Funci�n equivalente al Bot�n Buscar por ID
vector <string> BuscarDocumentoPorID(string);

//Funci�n equivalente al Bot�n buscar por nombre
vector <string> BuscarDocumento(string, string, string);

//Funci�n equivalente al Bot�n buscar por atributos
vector <string> BuscarDocumentoPorAtributos(vector <string>);

//Funci�n equivalente al Bot�n Modificar Documento
bool A�adirAtributoADocumento(string nombre, string clave, string valor, string base_seleccionada, string coleccion_seleccionada, string confianza);

//Funci�n equivalente al Bot�n Modificar Documento Modificando Atributo
void ModificarAtributoDocumento(string nombre, string clave, string valor, string base_seleccionada, string coleccion_seleccionada, string confianza);

//Funci�n equivalente al Bot�n Modificar Documento Eliminando Atributo
void EliminarAtributoDocumento(string, string, string, string);

//Funci�n equivalente al Bot�n Eliminar tema
void EliminarTema(string, string, string);

//Funci�n equivalente al Bot�n Establecer Relaci�n
void EstablecerRelacion(string nombre_doc, string base_doc, string coleccion_doc, string nombre_doc_atributo, string base_doc_atributo, string coleccion_doc_atributo, string confianza);

//Funci�n equivalente al Bot�n Buscar Multimedia
vector <string> BuscarDocumentosMultimedia(string nombre_base);

//Funci�n equivalente al Bot�n Preguntar Curiosidad
string PreguntarCuriosidad();
