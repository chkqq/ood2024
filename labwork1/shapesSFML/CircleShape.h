#ifndef CIRCLESHAPE_H
#define CIRCLESHAPE_H

#include "ShapeDecorator.h"

class CircleDecorator : public ShapeDecorator 
{
private:
    sf::CircleShape circle;
public:
    CircleDecorator(float radius, sf::Vector2f position);
    void Draw(sf::RenderWindow& window) override;
    float GetPerimeter() const override;
    float GetArea() const override;
};

#endif
