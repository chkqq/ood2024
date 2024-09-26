#include "CircleShape.h"
#define _USE_MATH_DEFINES
#include <math.h>

CircleDecorator::CircleDecorator(float radius, sf::Vector2f position) 
{
    circle.setRadius(radius);
    circle.setPosition(position);
    circle.setFillColor(sf::Color::Cyan);
    circle.setOutlineColor(sf::Color::Black);
    circle.setOutlineThickness(1);
}

void CircleDecorator::Draw(sf::RenderWindow& window)
{
    window.draw(circle);
}

float CircleDecorator::GetPerimeter() const
{
    return 2 * M_PI * circle.getRadius();
}

float CircleDecorator::GetArea() const
{
    return M_PI * std::pow(circle.getRadius(), 2);
}
