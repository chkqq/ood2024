#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
private:
    sf::RectangleShape m_rectangle;

public:
    Rectangle(sf::Vector2f size, sf::Vector2f position)
    {
        m_rectangle.setSize(size);
        m_rectangle.setPosition(position);
    }

    void Draw(sf::RenderWindow& window) override
    {
        window.draw(m_rectangle);
    }

    bool Contains(const sf::Vector2f& point) const override
    {
        return m_rectangle.getGlobalBounds().contains(point);
    }

    void Move(const sf::Vector2f& delta) override
    {
        m_rectangle.move(delta);
    }

    float GetPerimeter() const override
    {
        return 2 * (m_rectangle.getSize().x + m_rectangle.getSize().y);
    }

    float GetArea() const override
    {
        return m_rectangle.getSize().x * m_rectangle.getSize().y;
    }
    sf::Vector2f GetPosition() const override
    {
        return m_rectangle.getPosition();
    }

    void SetPosition(const sf::Vector2f& position) override
    {
        m_rectangle.setPosition(position);
    }

    void SetFillColor(const sf::Color& color) override {
        m_rectangle.setFillColor(color);
    }

    void SetOutlineColor(const sf::Color& color) override {
        m_rectangle.setOutlineColor(color);
    }

    void SetOutlineThickness(float thickness) override {
        m_rectangle.setOutlineThickness(thickness);
    }

    sf::Vector2f GetRightDownCorner() const override
    {
        return sf::Vector2f(m_rectangle.getGlobalBounds().getPosition().x + m_rectangle.getGlobalBounds().width, m_rectangle.getGlobalBounds().getPosition().y + m_rectangle.getGlobalBounds().height);
    };


    sf::RectangleShape& GetRectangleShape() { return m_rectangle; }
};

#endif
