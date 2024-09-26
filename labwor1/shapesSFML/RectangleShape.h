#ifndef RECTANGLESHAPE_H
#define RECTANGLESHAPE_H

#include "ShapeDecorator.h"

class RectangleDecorator : public ShapeDecorator
{
private:
    sf::RectangleShape rectangle;
public:
    RectangleDecorator(sf::Vector2f size, sf::Vector2f position);
    void Draw(sf::RenderWindow& window) override;
    float GetPerimeter() const override;
    float GetArea() const override;
};

#endif
