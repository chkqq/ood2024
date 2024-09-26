#include "CircleShape.h"
#include <cmath>

CircleDecorator::CircleDecorator(float radius, sf::Vector2f position) 
{
    circle.setRadius(radius);
    circle.setPosition(position);
    circle.setFillColor(sf::Color::Red);
    circle.setOutlineColor(sf::Color::Red);
    circle.setOutlineThickness(2);
}

void CircleDecorator::Draw(sf::RenderWindow& window)
{
    window.draw(circle);
}

float CircleDecorator::GetPerimeter() const
{
    return 2 * 3.14159f * circle.getRadius();
}

float CircleDecorator::GetArea() const
{
    return 3.14159f * std::pow(circle.getRadius(), 2);
}
