#include "RectangleShape.h"

RectangleDecorator::RectangleDecorator(sf::Vector2f size, sf::Vector2f position) 
{
    rectangle.setSize(size);
    rectangle.setPosition(position);
    rectangle.setFillColor(sf::Color::Blue);
    rectangle.setOutlineColor(sf::Color::Blue);
    rectangle.setOutlineThickness(2);
}

void RectangleDecorator::Draw(sf::RenderWindow& window)
{
    window.draw(rectangle);
}

float RectangleDecorator::GetPerimeter() const 
{
    return 2 * (rectangle.getSize().x + rectangle.getSize().y);
}

float RectangleDecorator::GetArea() const
{
    return rectangle.getSize().x * rectangle.getSize().y;
}
