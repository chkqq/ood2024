#pragma once
#include "shape.h"
#include "memory.h"
class Rectangle : public Shape
{
private:
    sf::RectangleShape m_rectangle;
    sf::RectangleShape m_frame;
    bool m_isSelected = false;
public:
    Rectangle(sf::Vector2f size, sf::Vector2f position)
    {
        m_rectangle.setSize(size);
        m_rectangle.setPosition(position);
        m_rectangle.setOutlineThickness(2);
        m_rectangle.setFillColor(sf::Color::Black);
        m_rectangle.setOutlineColor(sf::Color::Red);

        m_frame.setPosition(m_rectangle.getGlobalBounds().getPosition());
        m_frame.setSize(sf::Vector2f(m_rectangle.getGlobalBounds().width, m_rectangle.getGlobalBounds().height));
        m_frame.setFillColor(sf::Color::Transparent);
        m_frame.setOutlineThickness(2);
        m_frame.setOutlineColor(sf::Color::Magenta);
    };

    std::string serialize() const override {
        std::ostringstream oss;
        oss << "Rectangle "
            << m_rectangle.getSize().x << " " << m_rectangle.getSize().y << " "
            << m_rectangle.getPosition().x << " " << m_rectangle.getPosition().y << " "
            << m_rectangle.getFillColor().toInteger() << " "
            << m_rectangle.getOutlineColor().toInteger() << " "
            << m_rectangle.getOutlineThickness();
        return oss.str();
    }
    void Draw(sf::RenderWindow& window) override
    {
        window.draw(m_rectangle);
        if (m_isSelected)
            window.draw(m_frame);
    };
    bool Contains(const sf::Vector2f& point) const override
    {
        return m_rectangle.getGlobalBounds().contains(point);
    }
    sf::Vector2f GetPosition() const override
    {
        return m_rectangle.getGlobalBounds().getPosition();
    };
    void setPosition(const sf::Vector2f& position) override
    {
        m_rectangle.setPosition(position);
        m_frame.setPosition(m_rectangle.getGlobalBounds().left, m_rectangle.getGlobalBounds().top);
    }

    void Move(const sf::Vector2f& point) override
    {
        m_rectangle.move(point);
        m_frame.move(point);
    };
    sf::Vector2f GetRightDownCorner() const override
    {
        return sf::Vector2f(m_rectangle.getGlobalBounds().getPosition().x + m_rectangle.getGlobalBounds().width, m_rectangle.getGlobalBounds().getPosition().y + m_rectangle.getGlobalBounds().height);
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

    std::shared_ptr<Shape> clone() const override {
        return std::make_shared<Rectangle>(*this);  // ��������� �������������
    }

    sf::RectangleShape& GetRectangleShape() { return m_rectangle; }

};