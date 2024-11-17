#ifndef MATHDECORATOR_H
#define MATHDECORATOR_H

#include <SFML/Graphics.hpp>
#include "Shape.h"
#include <fstream>
class MathDecorator : public Shape
{
public:
	virtual double GetPerimeter() = 0;
	virtual double GetArea() = 0;
	virtual void PrintData(std::ofstream& output) = 0;
	
};

#endif