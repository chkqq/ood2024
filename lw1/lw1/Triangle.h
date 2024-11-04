#pragma once
#include "shape.h"
#include <cmath>

class Triangle : public Shape
{
private:
    sf::ConvexShape m_triangle;
    sf::RectangleShape m_frame;
    bool m_isSelected = false;

public:
    Triangle(const sf::Vector2f& point1, const sf::Vector2f& point2, const sf::Vector2f& point3)
    {
        m_triangle.setPointCount(3);
        m_triangle.setPoint(0, point1);
        m_triangle.setPoint(1, point2);
        m_triangle.setPoint(2, point3);

        m_triangle.setFillColor(sf::Color::Black);
        m_triangle.setOutlineThickness(2);
        m_triangle.setOutlineColor(sf::Color::Red);

        UpdateFrame();
    }

    void UpdateFrame()
    {
        auto bounds = m_triangle.getGlobalBounds();
        m_frame.setPosition(bounds.left, bounds.top);
        m_frame.setSize(sf::Vector2f(bounds.width, bounds.height));
        m_frame.setFillColor(sf::Color::Transparent);
        m_frame.setOutlineThickness(2);
        m_frame.setOutlineColor(sf::Color::Magenta);
    }

    void Draw(sf::RenderWindow& window) override
    {
        window.draw(m_triangle);
        if (m_isSelected)
            window.draw(m_frame);
    }

    bool Contains(const sf::Vector2f& point) const override
    {
        return m_triangle.getGlobalBounds().contains(point);
    }

    sf::Vector2f GetPosition() const override
    {
        return m_triangle.getGlobalBounds().getPosition();
    }

    void Move(const sf::Vector2f& offset) override
    {
        m_triangle.move(offset);
        m_frame.move(offset);
    }

    sf::Vector2f GetRightDownCorner() const override
    {
        auto bounds = m_triangle.getGlobalBounds();
        return sf::Vector2f(bounds.left + bounds.width - m_triangle.getOutlineThickness(),
            bounds.top + bounds.height - m_triangle.getOutlineThickness());
    }

    void Select(bool select) override
    {
        m_isSelected = select;
    }

    bool IsSelected() const override
    {
        return m_isSelected;
    }

    bool IsGroup() const override
    {
        return false;
    }
    void accept(Visitor& visitor) override
    {
        visitor.visit(*this);
    }
    sf::ConvexShape& GetTriangleShape() { return m_triangle; }
};
