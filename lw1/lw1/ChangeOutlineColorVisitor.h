#pragma once
#include "Visitor.h"
#include <SFML/Graphics.hpp>
#include "shapes.h"
class ChangeOutlineColorVisitor : public Visitor
{
private:
    sf::Color newColor;

public:
    ChangeOutlineColorVisitor(sf::Color color) : newColor(color) {}

    void visit(Circle& circle)
    {
        circle.GetCircleShape().setOutlineColor(newColor);
    }

    void visit(Rectangle& rectangle)
    {
        rectangle.GetRectangleShape().setOutlineColor(newColor);
    }

    void visit(Triangle& triangle)
    {
        triangle.GetTriangleShape().setOutlineColor(newColor);
    }
    void visit(Group& group)
    {
        for (auto& shape : group.GetShapes())
        {
            shape->accept(*this); 
        }
    }
};
