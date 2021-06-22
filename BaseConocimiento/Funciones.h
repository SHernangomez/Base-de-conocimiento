/*	TFG:	Sistema de conocimiento para robótica cognitiva social
			Grado en Ingeniería en Tecnologías Industriales
			Sofía Hernangómez Flores
			2021

	Tutor:	Daniel Galán Vicente
*/


#pragma once	//	Directiva para asegurar que el código fuente sea incluido una sola vez

#include "pch.h"
#include <fstream>
#include <vector>

using namespace std;

using namespace System;

//Función para pasar de system string a std basic string
//Necesaria en los formularios al introducir datos por pantalla
string toStandardString(System::String^ string);

//Función que separa los atributos de un string JSON
vector <string> SepararLineasJSON(string);

//Función que lee un archivo JSON
vector <string> LeerJSON(string);


//Función que comprueba si se trata de una Base de Datos que contiene archivos multimedia
int BaseDeDatosMultimedia(string nombre_base);


//Función que comprueba si se trata de un atributo inherente (_id, base de datos, coleccion)
int AtributoInherente(string nombre_atributo);


//Funcion que comprueba si existe un elemento coincidente en un vector <string>
int ElementoCoincidente(string elemento, vector <string> vector_de_elementos);

