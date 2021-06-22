/*	TFG:	Sistema de conocimiento para rob�tica cognitiva social
			Grado en Ingenier�a en Tecnolog�as Industriales
			Sof�a Hernang�mez Flores
			2021

	Tutor:	Daniel Gal�n Vicente
*/


#include "pch.h"	//Archivo de precompilado
#include "Funciones_Archivos.h"


//Funci�n para crear un fichero con el primer atributo del JSON {"identificador": ""}
void CrearFichero(string ubicacion_fichero, string nombre_clave, string nombre_valor) {

	ofstream archivo;
	archivo.open(ubicacion_fichero);

	archivo << "{\n\t\"" << nombre_clave.c_str() << "\"" << ": " << "\"" << nombre_valor.c_str() << "\"" << "\n}" << endl;
	archivo.close();
}


//Funci�n que devuelve el contenido de un fichero
string LeerFichero(string ubicacion_fichero) {
	ifstream fichero;
	string linea = "";
	string contenido = "";

	fichero.open(ubicacion_fichero);

	while (!fichero.eof()) {
		getline(fichero, linea);
		contenido += linea + "\n";
	}

	fichero.close();

	return contenido;
}


//Funci�n para a�adir una l�nea a un fichero existente (solo si se trata de JSON)
void NuevaLinea(string clave, string valor, string ubicacion, string nombre_fichero) {
	//	Creamos un file de lectura para poder leer el fichero existente
	ifstream fichero;
	fichero.open(ubicacion);

	//	Creamos un file de escritura para a�adir texto (posteriormente este fichero sustituir� al original)
	ofstream fichero_temporal;
	string ubicacion_temporal = nombre_fichero + "temp.txt";
	fichero_temporal.open(ubicacion_temporal);

	string linea = "";
	string linea_anterior = "";
	string coma = ",";
	string buscar_linea = "}";
	string buscar_linea_despues = "";

	//  A�adimos l�nea con el nuevo atributo y movemos } al final del documento
	while (!fichero.eof()) {
		getline(fichero, linea);

		if (strcmp(linea.c_str(), buscar_linea.c_str()) == 0) {
			fichero_temporal << "\t\"" << clave.c_str() << "\"" << ": " << "\"" << valor.c_str() << "\"" << "\n}" << endl;
			buscar_linea_despues = linea_anterior;
		}
		else fichero_temporal << linea << endl;
		linea_anterior = linea;
	}

	fichero.close();
	fichero_temporal.close();

	remove(ubicacion.c_str());

	//	Creamos un file de lectura para poder leer el fichero existente
	ifstream fich_temp;
	fich_temp.open(ubicacion_temporal);

	//	Creamos un file de escritura para a�adir texto (posteriormente este fichero sustituir� al original)
	ofstream fichero_final;
	string ubicacion_final = nombre_fichero + "final.txt";
	fichero_final.open(ubicacion_final);

	//  A�adimos la , a la linea anterior a la que hemos a�adido en el fichero
	while (!fich_temp.eof()) {
		getline(fich_temp, linea);
		if (strcmp(linea.c_str(), buscar_linea_despues.c_str()) == 0) {
			fichero_final << linea << "," << endl;
		}
		else fichero_final << linea << endl;
	}

	fich_temp.close();
	fichero_final.close();

	remove(ubicacion_temporal.c_str());
	rename(ubicacion_final.c_str(), ubicacion.c_str());
}