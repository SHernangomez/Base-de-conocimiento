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
#include "Funciones_Archivos.h"
#include "Funciones_MongoDB.h"


//Funci�n equivalente al bot�n A�adir archivo multimedia
void A�adirArchivoMultimedia(string ruta, const char* tipo_de_archivo, string nombre_doc);



void A�adirAtributoMultimedia(const char* tipo_de_archivo, string nombre_doc, string clave, string valor);



//Funci�n equivalente al bot�n Eliminar archivo multimedia
void EliminarArchivoMultimedia(string base, string nombre);


//Funci�n equivalente al bot�n Consultar Multimedia por ID
void ConsultarArchivoMultimedia(string id_consulta, string ruta);

//Funci�n equivalente al bot�n Consultar Multimedia por Nombre
void ConsultarArchivoMultimediaPorNombre(string base, string nombre, string ruta);


string DescargarArchivoMultimedia(string base, string id_consulta, string ruta);

//Funci�n equivalente al bot�n Establecer relaci�n
void EstablecerRelacionMultimedia(string nombre_doc, string base_doc, string coleccion_doc, string clave_atributo, string nombre_doc_atributo, string base_doc_atributo, string coleccion_doc_atributo, string confianza);