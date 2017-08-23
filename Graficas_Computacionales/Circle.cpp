/***********************************************
Materia: Graficas Computacionales

Fecha: 23 de Agosto del 2017

Autor: A01376132 Angel Geney Moreno Morales
************************************************/

#include "Circle.h"

Circle::Circle() {
	_radius = 1.0;
	_color = "red";
}

Circle::Circle(double r) {
	_radius = r;
	_color = "red";
}

Circle::Circle(double r, std::string c) {
	_radius = r;
	_color = c;
}

double Circle::GetRadius() {
	return _radius;
}

double Circle::GetArea() {
	return 3.14159 * _radius * _radius;
}

void Circle::SetRadius(double r) {
	_radius = r;
}

void Circle::SetColor(std::string c) {
	_color = c;
}