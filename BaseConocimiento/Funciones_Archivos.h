/*	TFG:	Sistema de conocimiento para rob�tica cognitiva social
			Grado en Ingenier�a en Tecnolog�as Industriales
			Sof�a Hernang�mez Flores
			2021

	Tutor:	Daniel Gal�n Vicente
*/


#pragma once	//	Directiva para asegurar que el c�digo fuente sea incluido una sola vez


#include "pch.h"	//Archivo de precompilado

#include <fstream>

using namespace std;

//Funci�n para crear un fichero con el primer atributo del JSON {"identificador": ""}
void CrearFichero(string, string, string);

//Funci�n que devuelve el contenido de un fichero
string LeerFichero(string);

//Funci�n para a�adir una l�nea a un fichero existente (solo si se trata de JSON)
void NuevaLinea(string, string, string, string);
