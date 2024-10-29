#ifndef SHAPE_H
#define SHAPE_H

#include <SFML/Graphics.hpp>

class Shape
{
public:
    virtual ~Shape() = default;
    virtual void Draw(sf::RenderWindow& window) = 0;
    virtual bool Contains(const sf::Vector2f& point) const = 0;
    virtual void Move(const sf::Vector2f& delta) = 0;

    virtual sf::Vector2f GetPosition() const = 0;
    virtual void SetPosition(const sf::Vector2f& position) = 0;

    virtual void SetFillColor(const sf::Color& color) = 0;
    virtual void SetOutlineColor(const sf::Color& color) = 0;
    virtual void SetOutlineThickness(float thickness) = 0;

    virtual float GetPerimeter() const = 0;
    virtual float GetArea() const = 0;

    virtual sf::Vector2f GetRightDownCorner() const = 0;
};

#endif
