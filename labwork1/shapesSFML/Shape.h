#ifndef SHAPE_H
#define SHAPE_H

#include <SFML/Graphics.hpp>

class Shape
{
public:
    virtual void Draw(sf::RenderWindow& window) = 0;
    virtual float GetPerimeter() const = 0;
    virtual float GetArea() const = 0;
    virtual ~Shape() = default;
};

#endif
