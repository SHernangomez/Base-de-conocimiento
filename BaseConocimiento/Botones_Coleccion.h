/*	TFG:	Sistema de conocimiento para robótica cognitiva social
			Grado en Ingeniería en Tecnologías Industriales
			Sofía Hernangómez Flores
			2021

	Tutor:	Daniel Galán Vicente
*/


#pragma once	//	Directiva para asegurar que el código fuente sea incluido una sola vez


#include "pch.h"	//Archivo de precompilado

//Archivo de encabezamiento con funciones generales que se utilizan en el proyecto
#include "Funciones_MongoDB.h"


using namespace std;

//Función equivalente al Botón Añadir Coleccion
void CrearColeccion(string, string);

//Función equivalente al Botón Eliminar Coleccion
void EliminarColeccionExistente(string, string);
