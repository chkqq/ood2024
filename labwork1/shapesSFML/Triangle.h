#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape
{
private:
    sf::ConvexShape m_triangle;

public:
    Triangle(sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f point3)
    {
        m_triangle.setPointCount(3);
        m_triangle.setPoint(0, point1);
        m_triangle.setPoint(1, point2);
        m_triangle.setPoint(2, point3);
        m_triangle.setFillColor(sf::Color::White);
    }

    void Draw(sf::RenderWindow& window) override
    {
        window.draw(m_triangle);
    }

    bool Contains(const sf::Vector2f& point) const override
    {
        return m_triangle.getGlobalBounds().contains(point);
    }

    void Move(const sf::Vector2f& delta) override
    {
        m_triangle.move(delta);
    }

    float GetPerimeter() const override
    {
        float side1 = std::sqrt(std::pow(m_triangle.getPoint(1).x - m_triangle.getPoint(0).x, 2) +
            std::pow(m_triangle.getPoint(1).y - m_triangle.getPoint(0).y, 2));
        float side2 = std::sqrt(std::pow(m_triangle.getPoint(2).x - m_triangle.getPoint(1).x, 2) +
            std::pow(m_triangle.getPoint(2).y - m_triangle.getPoint(1).y, 2));
        float side3 = std::sqrt(std::pow(m_triangle.getPoint(0).x - m_triangle.getPoint(2).x, 2) +
            std::pow(m_triangle.getPoint(0).y - m_triangle.getPoint(2).y, 2));
        return side1 + side2 + side3;
    }

    float GetArea() const override
    {
        const sf::Vector2f& p1 = m_triangle.getPoint(0);
        const sf::Vector2f& p2 = m_triangle.getPoint(1);
        const sf::Vector2f& p3 = m_triangle.getPoint(2);
        return std::abs((p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / 2.0f);
    }
    sf::Vector2f GetPosition() const override
    {
        return m_triangle.getPosition();
    }

    void SetPosition(const sf::Vector2f& position) override
    {
        m_triangle.setPosition(position);
    }

    void SetFillColor(const sf::Color& color) override {
        m_triangle.setFillColor(color);
    }

    void SetOutlineColor(const sf::Color& color) override {
        m_triangle.setOutlineColor(color);
    }

    void SetOutlineThickness(float thickness) override {
        m_triangle.setOutlineThickness(thickness);
    }

    sf::Vector2f GetRightDownCorner() const override
    {
        return sf::Vector2f(m_triangle.getGlobalBounds().getPosition().x + m_triangle.getGlobalBounds().width - m_triangle.getOutlineThickness(), m_triangle.getGlobalBounds().getPosition().y + m_triangle.getGlobalBounds().height - m_triangle.getOutlineThickness());
    };

    sf::ConvexShape& GetTriangleShape() { return m_triangle; }
};

#endif
