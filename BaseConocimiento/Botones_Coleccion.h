/*	TFG:	Sistema de conocimiento para rob�tica cognitiva social
			Grado en Ingenier�a en Tecnolog�as Industriales
			Sof�a Hernang�mez Flores
			2021

	Tutor:	Daniel Gal�n Vicente
*/


#pragma once	//	Directiva para asegurar que el c�digo fuente sea incluido una sola vez


#include "pch.h"	//Archivo de precompilado

//Archivo de encabezamiento con funciones generales que se utilizan en el proyecto
#include "Funciones_MongoDB.h"


using namespace std;

//Funci�n equivalente al Bot�n A�adir Coleccion
void CrearColeccion(string, string);

//Funci�n equivalente al Bot�n Eliminar Coleccion
void EliminarColeccionExistente(string, string);
