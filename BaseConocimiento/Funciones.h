/*	TFG:	Sistema de conocimiento para rob�tica cognitiva social
			Grado en Ingenier�a en Tecnolog�as Industriales
			Sof�a Hernang�mez Flores
			2021

	Tutor:	Daniel Gal�n Vicente
*/


#pragma once	//	Directiva para asegurar que el c�digo fuente sea incluido una sola vez

#include "pch.h"
#include <fstream>
#include <vector>

using namespace std;

using namespace System;

//Funci�n para pasar de system string a std basic string
//Necesaria en los formularios al introducir datos por pantalla
string toStandardString(System::String^ string);

//Funci�n que separa los atributos de un string JSON
vector <string> SepararLineasJSON(string);

//Funci�n que lee un archivo JSON
vector <string> LeerJSON(string);


//Funci�n que comprueba si se trata de una Base de Datos que contiene archivos multimedia
int BaseDeDatosMultimedia(string nombre_base);


//Funci�n que comprueba si se trata de un atributo inherente (_id, base de datos, coleccion)
int AtributoInherente(string nombre_atributo);


//Funcion que comprueba si existe un elemento coincidente en un vector <string>
int ElementoCoincidente(string elemento, vector <string> vector_de_elementos);

