#pragma once
#include "Visitor.h"
#include "shapes.h"
class ChangeOutlineThicknessVisitor : public Visitor
{
private:
    float newThickness;

public:
    ChangeOutlineThicknessVisitor(float thickness) : newThickness(thickness) {}

    void visit(Circle& circle)
    {
        circle.GetCircleShape().setOutlineThickness(newThickness);
    }

    void visit(Rectangle& rectangle)
    {
        rectangle.GetRectangleShape().setOutlineThickness(newThickness);
    }

    void visit(Triangle& triangle)
    {
        triangle.GetTriangleShape().setOutlineThickness(newThickness);
    }
    void visit(Group& group)
    {
        for (auto& shape : group.GetShapes())
        {
            shape->accept(*this);
        }
    }
};