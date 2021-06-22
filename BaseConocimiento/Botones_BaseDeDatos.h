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


//Función equivalente al botón Añadir Base de Datos
void CrearBaseDeDatos(string N_Base, string N_Coleccion);

//Función equivalente al botón Eliminar Base de Datos
void EliminarBaseDeDatosExistente(string Base);