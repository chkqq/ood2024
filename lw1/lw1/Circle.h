#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include "shape.h"

class Circle : public Shape
{
private:
    sf::CircleShape m_circle;
    sf::RectangleShape m_frame;
    bool m_isSelected = false;
public:
    Circle(float radius, sf::Vector2f position)
    {
        m_circle.setRadius(radius);
        m_circle.setPosition(position);
        m_circle.setFillColor(sf::Color::Black);
        m_circle.setOutlineThickness(2);
        m_circle.setOutlineColor(sf::Color::Red);

        m_frame.setPosition(m_circle.getGlobalBounds().getPosition());
        m_frame.setSize(sf::Vector2f(m_circle.getGlobalBounds().width, m_circle.getGlobalBounds().height));
        m_frame.setFillColor(sf::Color::Transparent);
        m_frame.setOutlineThickness(2);
        m_frame.setOutlineColor(sf::Color::Magenta);
    };
    void Draw(sf::RenderWindow& window) override
    {
        window.draw(m_circle);
        if (m_isSelected)
            window.draw(m_frame);
    };
    std::string serialize() const override {
        std::ostringstream oss;
        oss << "Circle "
            << m_circle.getRadius() << " "
            << m_circle.getPosition().x << " "
            << m_circle.getPosition().y << " "
            << m_circle.getFillColor().toInteger() << " "
            << m_circle.getOutlineColor().toInteger() << " "
            << m_circle.getOutlineThickness();
        return oss.str();
    }
    bool Contains(const sf::Vector2f& point) const override
    {
        return m_circle.getGlobalBounds().contains(point);
    }
    sf::Vector2f GetPosition() const override
    {
        return m_circle.getGlobalBounds().getPosition();
    };
    sf::Vector2f GetRightDownCorner() const override
    {
        return sf::Vector2f(m_circle.getGlobalBounds().getPosition().x + m_circle.getGlobalBounds().width, m_circle.getGlobalBounds().getPosition().y + m_circle.getGlobalBounds().height);
    };
    void Move(const sf::Vector2f& point) override
    {
        m_circle.move(point);
        m_frame.move(point);
    };
    void Select(const bool select) override
    {
        m_isSelected = select;
    };
    bool IsSelected() const override
    {
        return m_isSelected;
    };
    bool IsGroup() const override
    {
        return false;
    };

    void accept(Visitor& visitor) override
    {
        visitor.visit(*this);
    }
    sf::CircleShape& GetCircleShape() { return m_circle; };

};