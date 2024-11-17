#include "TriangleDecorator.h"

TriangleDecorator::TriangleDecorator(std::shared_ptr<Triangle> shape)
    : m_shape(shape)
{
}

double TriangleDecorator::GetPerimeter()
{
    sf::ConvexShape& triangle = m_shape->GetTriangleShape();
    float side1 = Distance(triangle.getPoint(0), triangle.getPoint(1));
    float side2 = Distance(triangle.getPoint(1), triangle.getPoint(2));
    float side3 = Distance(triangle.getPoint(2), triangle.getPoint(0));

    return side1 + side2 + side3;
}

double TriangleDecorator::GetArea()
{
    sf::ConvexShape& triangle = m_shape->GetTriangleShape();
    float x1 = triangle.getPoint(0).x, y1 = triangle.getPoint(0).y;
    float x2 = triangle.getPoint(1).x, y2 = triangle.getPoint(1).y;
    float x3 = triangle.getPoint(2).x, y3 = triangle.getPoint(2).y;

    return std::abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0f);
}

void TriangleDecorator::PrintData(std::ofstream& output)
{
    output << "P = " << GetPerimeter() << "; S = " << GetArea() << std::endl;
}

float TriangleDecorator::Distance(const sf::Vector2f& p1, const sf::Vector2f& p2) const
{
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}
