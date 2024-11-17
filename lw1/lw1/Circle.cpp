#include "Circle.h"
#include <sstream>

Circle::Circle(float radius, sf::Vector2f position)
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
}

void Circle::Draw(sf::RenderWindow& window)
{
    window.draw(m_circle);
    if (m_isSelected)
        window.draw(m_frame);
}

std::string Circle::serialize() const
{
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

bool Circle::Contains(const sf::Vector2f& point) const
{
    return m_circle.getGlobalBounds().contains(point);
}

sf::Vector2f Circle::GetPosition() const
{
    return m_circle.getGlobalBounds().getPosition();
}

void Circle::setPosition(const sf::Vector2f& position)
{
    m_circle.setPosition(position);
    m_frame.setPosition(m_circle.getGlobalBounds().left, m_circle.getGlobalBounds().top);
}

sf::Vector2f Circle::GetRightDownCorner() const
{
    return sf::Vector2f(m_circle.getGlobalBounds().getPosition().x + m_circle.getGlobalBounds().width,
        m_circle.getGlobalBounds().getPosition().y + m_circle.getGlobalBounds().height);
}

void Circle::Move(const sf::Vector2f& point)
{
    m_circle.move(point);
    m_frame.move(point);
}

void Circle::Select(const bool select)
{
    m_isSelected = select;
}

bool Circle::IsSelected() const
{
    return m_isSelected;
}

bool Circle::IsGroup() const
{
    return false;
}

std::shared_ptr<Shape> Circle::clone() const
{
    return std::make_shared<Circle>(*this);
}

void Circle::accept(Visitor& visitor)
{
    visitor.visit(*this);
}

sf::CircleShape& Circle::GetCircleShape()
{
    return m_circle;
}
