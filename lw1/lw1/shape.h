#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include "Visitor.h"
class Shape
{
public:
    virtual void Draw(sf::RenderWindow& window) = 0;
    virtual float GetPerimeter() const = 0;
    virtual float GetArea() const = 0;
    virtual std::string GetParams() const = 0;
    virtual bool Contains(const sf::Vector2f& point) const = 0;
    virtual sf::Vector2f GetPosition() const = 0;
    virtual sf::Vector2f GetRightDownCorner() const = 0;
    virtual void Move(const sf::Vector2f& offset) = 0;
    virtual void Select(bool select) = 0;
    virtual bool IsSelected() const = 0;
    virtual bool IsGroup() const { return false; } // По умолчанию фигура не является группой
    virtual void accept(Visitor& visitor) = 0;
    virtual ~Shape() = default;
};
