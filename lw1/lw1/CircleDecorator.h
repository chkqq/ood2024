#ifndef CIRCLEDECORATOR_H
#define CIRCLEDECORATOR_H

#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include <cmath>
#include <fstream>
#include "MathDecorator.h"
#include "shapes.h"

class CircleDecorator : public MathDecorator
{
public:
    explicit CircleDecorator(std::shared_ptr<Circle> shape);

    double GetPerimeter() override;
    double GetArea() override;
    void PrintData(std::ofstream& output) override;

private:
    std::shared_ptr<Circle> m_shape;
};

#endif