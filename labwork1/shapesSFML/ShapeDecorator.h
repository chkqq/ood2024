#ifndef SHAPE_DECORATOR_H
#define SHAPE_DECORATOR_H

#include "Shape.h"
#include <SFML/Graphics.hpp>

class ShapeDecorator : public Shape
{
protected:
    std::shared_ptr<Shape> m_shape;

public:
    ShapeDecorator(std::shared_ptr<Shape> shape) : m_shape(shape) {}

    void Draw(sf::RenderWindow& window) override {
        m_shape->Draw(window);
    }

    bool Contains(const sf::Vector2f& point) const override {
        return m_shape->Contains(point);
    }

    void Move(const sf::Vector2f& delta) override {
        m_shape->Move(delta);
    }

    float GetPerimeter() const override {
        return m_shape->GetPerimeter();
    }

    float GetArea() const override {
        return m_shape->GetArea();
    }

    sf::Vector2f GetPosition() const override {
        return m_shape->GetPosition();
    }

    void SetPosition(const sf::Vector2f& position) override {
        m_shape->SetPosition(position);
    }

    void SetFillColor(const sf::Color& color) override {
        m_shape->SetFillColor(color);
    }

    void SetOutlineColor(const sf::Color& color) override {
        m_shape->SetOutlineColor(color);
    }

    void SetOutlineThickness(float thickness) override {
        m_shape->SetOutlineThickness(thickness);
    }
};

#endif
