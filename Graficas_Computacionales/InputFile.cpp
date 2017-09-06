/**********************
Materia: Graficas comptacionales

Fecha: 06 de Septiembre del 2017

Autor: Angel Geney Moreno Morales
****************************************/
#include<fstream>
#include <string>
#include<iostream>
#include<sstream>
#include "InputFile.h"

bool InputFile::Read(std::string filename) 
{
	std::ifstream fl; std::stringstream alpha;
	fl.open("Prueba.txt", std::ios::in);
	if (fl.fail()) {
		std::cout<< "No se abrió" << std::endl;
		return false;
	}
	else
	{

		while (!fl.eof()) 
		{
			getline(fl, filename); alpha.str(filename + '\n');
			_contents() = alpha.str();


		}


	}
	fl.close();
}



std::string InputFile::GetContents(){

	return _contents();

}