/***********************************************
Materia: Graficas Computacionales

Fecha: 23 de Agosto del 2017

Autor: A01376132 Angel Geney Moreno Morales
************************************************/
#include "Rectangle.h"

Rectangle::Rectangle() {
	_width = 1.0;
	_height = 1.0;
}

Rectangle::Rectangle(float w, float h) {
	_width = w;
	_height = h;
}

float Rectangle::GetWidth() {
	return _width;
}

void Rectangle::SetWidth(float w) {
	_width = w;
}

float Rectangle::GetHeight() {
	return _height;
}

void Rectangle::SetHeight(float h) {
	_height = h;
}

float Rectangle::GetArea() {
	return _width * _height;
}

float Rectangle::GetPerimetro() {
	return (2 * _width) + (2 * _height);
}