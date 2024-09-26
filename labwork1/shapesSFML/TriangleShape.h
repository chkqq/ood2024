#ifndef TRIANGLESHAPE_H
#define TRIANGLESHAPE_H

#include "ShapeDecorator.h"

class TriangleDecorator : public ShapeDecorator 
{
private:
    sf::ConvexShape triangle;
public:
    TriangleDecorator(sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f point3);
    void Draw(sf::RenderWindow& window) override;
    float GetPerimeter() const override;
    float GetArea() const override;
};

#endif
