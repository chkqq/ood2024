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

    float GetPerimeter() const override
    {
        return 2 * (m_rectangle.getSize().x + m_rectangle.getSize().y);
    }

    float GetArea() const override
    {
        return m_rectangle.getSize().x * m_rectangle.getSize().y;
    }

    sf::RectangleShape& GetRectangleShape() { return m_rectangle; }
};

#endif
