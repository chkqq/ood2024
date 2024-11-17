#pragma once
#include "Visitor.h"
#include <SFML/Graphics.hpp>
#include "shapes.h"

class ChangeFillColorVisitor : public Visitor
{
private:
    sf::Color newColor;

public:
    ChangeFillColorVisitor(sf::Color color);
    void visit(Circle& circle) override;
    void visit(Rectangle& rectangle) override;
    void visit(Triangle& triangle) override;
    void visit(Group& group) override;
};
