#ifndef SHAPE_DECORATOR_H
#define SHAPE_DECORATOR_H

#include "Shape.h"
#include <SFML/Graphics.hpp>

class ShapeDecorator : public Shape
{
protected:
    std::shared_ptr<Shape> m_shape;

public:
    ShapeDecorator(std::shared_ptr<Shape> shape);
    void Draw(sf::RenderWindow& window) override;
    bool Contains(const sf::Vector2f& point) const override;

    void Move(const sf::Vector2f& delta) override;
    sf::FloatRect GetBounds() const override;

    sf::Vector2f GetPosition() const  override;
    void SetPosition(const sf::Vector2f& position)override;

    void SetFillColor(const sf::Color& color)override;
    void SetOutlineColor(const sf::Color& color)override;
    void SetOutlineThickness(float thickness)override;

    float GetPerimeter() const override;
    float GetArea() const override;
};

#endif
