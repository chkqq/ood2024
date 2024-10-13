#ifndef CIRCLE_H
#define CIRCLE_H

#define _USE_MATH_DEFINES
#include <math.h>
#include "Shape.h"

class Circle : public Shape
{
private:
    sf::CircleShape m_circle;

public:
    Circle(float radius, sf::Vector2f position)
    {
        m_circle.setRadius(radius);
        m_circle.setPosition(position);
    }

    void Draw(sf::RenderWindow& window) override
    {
        window.draw(m_circle);
    }

    bool Contains(const sf::Vector2f& point) const override
    {
        return m_circle.getGlobalBounds().contains(point);
    }


    float GetPerimeter() const override
    {
        return 2 * M_PI * m_circle.getRadius();
    }

    float GetArea() const override
    {
        return M_PI * m_circle.getRadius() * m_circle.getRadius();
    }

    void Move(const sf::Vector2f& delta) override
    {
        m_circle.move(delta);
    }

    sf::FloatRect GetBounds() const override
    {
        return m_circle.getGlobalBounds();
    }

    sf::Vector2f GetPosition() const override
    {
        return m_circle.getPosition();
    }

    void SetPosition(const sf::Vector2f& position) override
    {
        m_circle.setPosition(position);
    }

    void SetFillColor(const sf::Color& color) override {
        m_circle.setFillColor(color);
    }

    void SetOutlineColor(const sf::Color& color) override {
        m_circle.setOutlineColor(color);
    }

    void SetOutlineThickness(float thickness) override {
        m_circle.setOutlineThickness(thickness);
    }


    sf::CircleShape& GetCircleShape() { return m_circle; }
};

#endif
