#include "Triangle.h"
#include <sstream>

Triangle::Triangle(const sf::Vector2f& point1, const sf::Vector2f& point2, const sf::Vector2f& point3)
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

void Triangle::UpdateFrame()
{
    auto bounds = m_triangle.getGlobalBounds();
    m_frame.setPosition(bounds.left, bounds.top);
    m_frame.setSize(sf::Vector2f(bounds.width, bounds.height));
    m_frame.setFillColor(sf::Color::Transparent);
    m_frame.setOutlineThickness(2);
    m_frame.setOutlineColor(sf::Color::Magenta);
}

void Triangle::Draw(sf::RenderWindow& window)
{
    window.draw(m_triangle);
    if (m_isSelected)
        window.draw(m_frame);
}

std::string Triangle::serialize() const
{
    std::ostringstream oss;
    oss << "Triangle ";
    for (size_t i = 0; i < m_triangle.getPointCount(); ++i) {
        oss << m_triangle.getPoint(i).x << " " << m_triangle.getPoint(i).y << " ";
    }
    oss << m_triangle.getFillColor().toInteger() << " "
        << m_triangle.getOutlineColor().toInteger() << " "
        << m_triangle.getOutlineThickness();
    return oss.str();
}

bool Triangle::Contains(const sf::Vector2f& point) const
{
    return m_triangle.getGlobalBounds().contains(point);
}

sf::Vector2f Triangle::GetPosition() const
{
    return m_triangle.getGlobalBounds().getPosition();
}

void Triangle::setPosition(const sf::Vector2f& position)
{
    auto bounds = m_triangle.getGlobalBounds();
    sf::Vector2f offset = position - sf::Vector2f(bounds.left, bounds.top);
    m_triangle.move(offset);
    UpdateFrame();
}

void Triangle::Move(const sf::Vector2f& offset)
{
    m_triangle.move(offset);
    m_frame.move(offset);
}

sf::Vector2f Triangle::GetRightDownCorner() const
{
    auto bounds = m_triangle.getGlobalBounds();
    return sf::Vector2f(bounds.left + bounds.width - m_triangle.getOutlineThickness(),
        bounds.top + bounds.height - m_triangle.getOutlineThickness());
}

std::shared_ptr<Shape> Triangle::clone() const
{
    return std::make_shared<Triangle>(*this);
}

void Triangle::Select(bool select)
{
    m_isSelected = select;
}

bool Triangle::IsSelected() const
{
    return m_isSelected;
}

bool Triangle::IsGroup() const
{
    return false;
}

void Triangle::accept(Visitor& visitor)
{
    visitor.visit(*this);
}

sf::ConvexShape& Triangle::GetTriangleShape()
{
    return m_triangle;
}
