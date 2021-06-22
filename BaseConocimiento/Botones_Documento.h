/*	TFG:	Sistema de conocimiento para robótica cognitiva social
			Grado en Ingeniería en Tecnologías Industriales
			Sofía Hernangómez Flores
			2021

	Tutor:	Daniel Galán Vicente
*/


#pragma once	//	Directiva para asegurar que el código fuente sea incluido una sola vez


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

//Función equivalente al Botón Añadir Documento
void CrearDocumento(string Base, string Coleccion, string nombre, vector <string> atributos, string confianza);

//Función equivalente al Botón Buscar por colección
vector <string> BuscarDocumentosColeccion(string, string);

//Función equivalente al Botón Buscar por ID
vector <string> BuscarDocumentoPorID(string);

//Función equivalente al Botón buscar por nombre
vector <string> BuscarDocumento(string, string, string);

//Función equivalente al Botón buscar por atributos
vector <string> BuscarDocumentoPorAtributos(vector <string>);

//Función equivalente al Botón Modificar Documento
bool AñadirAtributoADocumento(string nombre, string clave, string valor, string base_seleccionada, string coleccion_seleccionada, string confianza);

//Función equivalente al Botón Modificar Documento Modificando Atributo
void ModificarAtributoDocumento(string nombre, string clave, string valor, string base_seleccionada, string coleccion_seleccionada, string confianza);

//Función equivalente al Botón Modificar Documento Eliminando Atributo
void EliminarAtributoDocumento(string, string, string, string);

//Función equivalente al Botón Eliminar tema
void EliminarTema(string, string, string);

//Función equivalente al Botón Establecer Relación
void EstablecerRelacion(string nombre_doc, string base_doc, string coleccion_doc, string nombre_doc_atributo, string base_doc_atributo, string coleccion_doc_atributo, string confianza);

//Función equivalente al Botón Buscar Multimedia
vector <string> BuscarDocumentosMultimedia(string nombre_base);

//Función equivalente al Botón Preguntar Curiosidad
string PreguntarCuriosidad();
