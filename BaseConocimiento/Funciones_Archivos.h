/*	TFG:	Sistema de conocimiento para robótica cognitiva social
			Grado en Ingeniería en Tecnologías Industriales
			Sofía Hernangómez Flores
			2021

	Tutor:	Daniel Galán Vicente
*/


#pragma once	//	Directiva para asegurar que el código fuente sea incluido una sola vez


#include "pch.h"	//Archivo de precompilado

#include <fstream>

using namespace std;

//Función para crear un fichero con el primer atributo del JSON {"identificador": ""}
void CrearFichero(string, string, string);

//Función que devuelve el contenido de un fichero
string LeerFichero(string);

//Función para añadir una línea a un fichero existente (solo si se trata de JSON)
void NuevaLinea(string, string, string, string);
