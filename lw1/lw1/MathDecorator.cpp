#include "MathDecorator.h"

void MathDecorator::Draw(sf::RenderWindow& window)
{
    m_shape->Draw(window);
}

std::string MathDecorator::serialize() const
{
    return "";
}

bool MathDecorator::Contains(const sf::Vector2f& point) const
{
    return m_shape->Contains(point);
}

sf::Vector2f MathDecorator::GetPosition() const
{
    return m_shape->GetPosition();
}

void MathDecorator::setPosition(const sf::Vector2f& position)
{
    m_shape->setPosition(position);
}

sf::Vector2f MathDecorator::GetRightDownCorner() const
{
    return m_shape->GetRightDownCorner();
}

void MathDecorator::Move(const sf::Vector2f& point)
{
    m_shape->Move(point);
}

void MathDecorator::Select(bool select)
{
    m_shape->Select(select);
}

bool MathDecorator::IsSelected() const
{
    return m_shape->IsSelected();
}

bool MathDecorator::IsGroup() const
{
    return m_shape->IsGroup();
}

void MathDecorator::accept(Visitor& visitor)
{
    m_shape->accept(visitor);
}

std::shared_ptr<Shape> MathDecorator::clone() const
{
    return m_shape->clone();
}
