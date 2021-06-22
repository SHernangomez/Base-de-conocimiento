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
#include "Funciones_Archivos.h"
#include "Funciones_MongoDB.h"


//Función equivalente al botón Añadir archivo multimedia
void AñadirArchivoMultimedia(string ruta, const char* tipo_de_archivo, string nombre_doc);



void AñadirAtributoMultimedia(const char* tipo_de_archivo, string nombre_doc, string clave, string valor);



//Función equivalente al botón Eliminar archivo multimedia
void EliminarArchivoMultimedia(string base, string nombre);


//Función equivalente al botón Consultar Multimedia por ID
void ConsultarArchivoMultimedia(string id_consulta, string ruta);

//Función equivalente al botón Consultar Multimedia por Nombre
void ConsultarArchivoMultimediaPorNombre(string base, string nombre, string ruta);


string DescargarArchivoMultimedia(string base, string id_consulta, string ruta);

//Función equivalente al botón Establecer relación
void EstablecerRelacionMultimedia(string nombre_doc, string base_doc, string coleccion_doc, string clave_atributo, string nombre_doc_atributo, string base_doc_atributo, string coleccion_doc_atributo, string confianza);