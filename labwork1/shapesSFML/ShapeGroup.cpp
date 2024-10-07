#include "ShapeGroup.h"

void ShapeGroup::AddShape(std::shared_ptr<Shape> shape)
{
    m_shapes.push_back(shape);
}

void ShapeGroup::Draw(sf::RenderWindow& window)
{
    for (auto& shape : m_shapes)
    {
        shape->Draw(window);
    }
}

bool ShapeGroup::Contains(const sf::Vector2f& point) const
{
    for (auto& shape : m_shapes)
    {
        if (shape->Contains(point))
        {
            return true;
        }
    }
    return false;
}

void ShapeGroup::Move(const sf::Vector2f& delta)
{
    for (auto& shape : m_shapes)
    {
        shape->Move(delta);
    }
}

sf::FloatRect ShapeGroup::GetBounds() const
{
    if (m_shapes.empty())
    {
        return sf::FloatRect();
    }

    sf::FloatRect bounds = m_shapes.front()->GetBounds();

    for (auto& shape : m_shapes)
    {
        sf::FloatRect shapeBounds = shape->GetBounds();

        float left = std::min(bounds.left, shapeBounds.left);
        float top = std::min(bounds.top, shapeBounds.top);
        float right = std::max(bounds.left + bounds.width, shapeBounds.left + shapeBounds.width);
        float bottom = std::max(bounds.top + bounds.height, shapeBounds.top + shapeBounds.height);

        bounds = sf::FloatRect(left, top, right - left, bottom - top);
    }

    return bounds;
}

float ShapeGroup::GetPerimeter() const
{
    float perimeter = 0;
    for (auto& shape : m_shapes)
    {
        perimeter += shape->GetPerimeter();
    }
    return perimeter;
}

float ShapeGroup::GetArea() const
{
    float area = 0;
    for (auto& shape : m_shapes)
    {
        area += shape->GetArea();
    }
    return area;
}
