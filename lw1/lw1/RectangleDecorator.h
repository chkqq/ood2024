#ifndef RECTANGLEDECORATOR_H
#define RECTANGLEDECORATOR_H

#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include <cmath>
#include <fstream>
#include "MathDecorator.h"
#include "Rectangle.h"

class RectangleDecorator : public MathDecorator
{
public:
    explicit RectangleDecorator(std::shared_ptr<Rectangle> shape);

    double GetPerimeter() override;
    double GetArea() override;
    void PrintData(std::ofstream& output) override;

private:
    std::shared_ptr<Rectangle> m_shape;
};

#endif