#pragma once
#include "Visitor.h"
#include <SFML/Graphics.hpp>
#include "shapes.h"
class ChangeFillColorVisitor : public Visitor
{
private:
    sf::Color newColor;

public:
    ChangeFillColorVisitor(sf::Color color) : newColor(color) {}

    void visit(Circle& circle)
    {
        circle.GetCircleShape().setFillColor(newColor);
    }

    void visit(Rectangle& rectangle)
    {
        rectangle.GetRectangleShape().setFillColor(newColor);
    }

    void visit(Triangle& triangle)
    {
        triangle.GetTriangleShape().setFillColor(newColor);
    }
    void visit(Group& group)
    {
        for (auto& shape : group.GetShapes())
        {
            shape->accept(*this);
        }
    }
};
