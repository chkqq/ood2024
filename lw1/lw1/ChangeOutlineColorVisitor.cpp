#include "ChangeOutlineColorVisitor.h"

ChangeOutlineColorVisitor::ChangeOutlineColorVisitor(sf::Color color) : newColor(color) {}

void ChangeOutlineColorVisitor::visit(Circle& circle)
{
    circle.GetCircleShape().setOutlineColor(newColor);
}

void ChangeOutlineColorVisitor::visit(Rectangle& rectangle)
{
    rectangle.GetRectangleShape().setOutlineColor(newColor);
}

void ChangeOutlineColorVisitor::visit(Triangle& triangle)
{
    triangle.GetTriangleShape().setOutlineColor(newColor);
}

void ChangeOutlineColorVisitor::visit(Group& group)
{
    for (auto& shape : group.GetShapes())
    {
        shape->accept(*this);
    }
}
