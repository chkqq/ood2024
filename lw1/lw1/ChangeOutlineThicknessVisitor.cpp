#include "ChangeOutlineThicknessVisitor.h"

ChangeOutlineThicknessVisitor::ChangeOutlineThicknessVisitor(float thickness) : newThickness(thickness) {}

void ChangeOutlineThicknessVisitor::visit(Circle& circle)
{
    circle.GetCircleShape().setOutlineThickness(newThickness);
}

void ChangeOutlineThicknessVisitor::visit(Rectangle& rectangle)
{
    rectangle.GetRectangleShape().setOutlineThickness(newThickness);
}

void ChangeOutlineThicknessVisitor::visit(Triangle& triangle)
{
    triangle.GetTriangleShape().setOutlineThickness(newThickness);
}

void ChangeOutlineThicknessVisitor::visit(Group& group)
{
    for (auto& shape : group.GetShapes())
    {
        shape->accept(*this);
    }
}
