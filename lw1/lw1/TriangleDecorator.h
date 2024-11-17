#ifndef TRIANGLEDECORATOR_H
#define TRIANGLEDECORATOR_H

#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include <cmath>
#include <fstream>
#include "MathDecorator.h"
#include "Triangle.h"

class TriangleDecorator : public MathDecorator
{
public:
    explicit TriangleDecorator(std::shared_ptr<Triangle> shape);

    double GetPerimeter() override;
    double GetArea() override;
    void PrintData(std::ofstream& output) override;

private:
    std::shared_ptr<Triangle> m_shape;
    float Distance(const sf::Vector2f& p1, const sf::Vector2f& p2) const;
};

#endif
