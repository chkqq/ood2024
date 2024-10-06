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

    float GetPerimeter() const override
    {
        return 2 * M_PI * m_circle.getRadius();
    }

    float GetArea() const override
    {
        return M_PI * m_circle.getRadius() * m_circle.getRadius();
    }

    sf::CircleShape& GetCircleShape() { return m_circle; }
};

#endif
