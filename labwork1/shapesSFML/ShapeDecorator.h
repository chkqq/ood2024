#ifndef SHAPEDECORATOR_H
#define SHAPEDECORATOR_H

#include <SFML/Graphics.hpp>

class ShapeDecorator 
{
public:
    virtual void Draw(sf::RenderWindow& window) = 0;
    virtual float GetPerimeter() const = 0;
    virtual float GetArea() const = 0;
    virtual ~ShapeDecorator() = default;
};

#endif
