#include "ChangeFillColorVisitor.h"

ChangeFillColorVisitor::ChangeFillColorVisitor(sf::Color color) : newColor(color) {}

void ChangeFillColorVisitor::visit(Circle& circle)
{
    circle.GetCircleShape().setFillColor(newColor);
}

void ChangeFillColorVisitor::visit(Rectangle& rectangle)
{
    rectangle.GetRectangleShape().setFillColor(newColor);
}

void ChangeFillColorVisitor::visit(Triangle& triangle)
{
    triangle.GetTriangleShape().setFillColor(newColor);
}

void ChangeFillColorVisitor::visit(Group& group)
{
    for (auto& shape : group.GetShapes())
    {
        shape->accept(*this);
    }
}
