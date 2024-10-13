#include "ShapeDecorator.h"

ShapeDecorator::ShapeDecorator(std::shared_ptr<Shape> shape) : m_shape(shape) {}

void ShapeDecorator::Draw(sf::RenderWindow& window)
{
    m_shape->Draw(window);
}

bool ShapeDecorator::Contains(const sf::Vector2f& point) const
{
    return m_shape->Contains(point);
}

void ShapeDecorator::Move(const sf::Vector2f& delta)
{
    m_shape->Move(delta);
}

sf::FloatRect ShapeDecorator::GetBounds() const
{
    return m_shape->GetBounds();
}

float ShapeDecorator::GetPerimeter() const
{
    return m_shape->GetPerimeter();
}

float ShapeDecorator::GetArea() const
{
    return m_shape->GetArea();
}
sf::Vector2f ShapeDecorator::GetPosition() const
{
    return m_shape->GetPosition();
}

void ShapeDecorator::SetPosition(const sf::Vector2f& position)
{
    m_shape->SetPosition(position);
}

void ShapeDecorator::SetFillColor(const sf::Color& color)  {
    m_shape->SetFillColor(color);
}

void ShapeDecorator::SetOutlineColor(const sf::Color& color)  {
    m_shape->SetOutlineColor(color);
}

void ShapeDecorator::SetOutlineThickness(float thickness)  {
    m_shape->SetOutlineThickness(thickness);
}
