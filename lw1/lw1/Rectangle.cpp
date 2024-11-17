#include "Rectangle.h"
#include <sstream>

Rectangle::Rectangle(sf::Vector2f size, sf::Vector2f position)
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
}

std::string Rectangle::serialize() const
{
    std::ostringstream oss;
    oss << "Rectangle "
        << m_rectangle.getSize().x << " " << m_rectangle.getSize().y << " "
        << m_rectangle.getPosition().x << " " << m_rectangle.getPosition().y << " "
        << m_rectangle.getFillColor().toInteger() << " "
        << m_rectangle.getOutlineColor().toInteger() << " "
        << m_rectangle.getOutlineThickness();
    return oss.str();
}

void Rectangle::Draw(sf::RenderWindow& window)
{
    window.draw(m_rectangle);
    if (m_isSelected)
        window.draw(m_frame);
}

bool Rectangle::Contains(const sf::Vector2f& point) const
{
    return m_rectangle.getGlobalBounds().contains(point);
}

sf::Vector2f Rectangle::GetPosition() const
{
    return m_rectangle.getGlobalBounds().getPosition();
}

void Rectangle::setPosition(const sf::Vector2f& position)
{
    m_rectangle.setPosition(position);
    m_frame.setPosition(m_rectangle.getGlobalBounds().left, m_rectangle.getGlobalBounds().top);
}

void Rectangle::Move(const sf::Vector2f& point)
{
    m_rectangle.move(point);
    m_frame.move(point);
}

sf::Vector2f Rectangle::GetRightDownCorner() const
{
    return sf::Vector2f(m_rectangle.getGlobalBounds().getPosition().x + m_rectangle.getGlobalBounds().width,
        m_rectangle.getGlobalBounds().getPosition().y + m_rectangle.getGlobalBounds().height);
}

void Rectangle::Select(const bool select)
{
    m_isSelected = select;
}

bool Rectangle::IsSelected() const
{
    return m_isSelected;
}

bool Rectangle::IsGroup() const
{
    return false;
}

void Rectangle::accept(Visitor& visitor)
{
    visitor.visit(*this);
}

std::shared_ptr<Shape> Rectangle::clone() const
{
    return std::make_shared<Rectangle>(*this);
}

sf::RectangleShape& Rectangle::GetRectangleShape()
{
    return m_rectangle;
}
