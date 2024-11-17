#pragma once
#include "Visitor.h"
#include "shapes.h"

class ChangeOutlineThicknessVisitor : public Visitor
{
private:
    float newThickness;

public:
    ChangeOutlineThicknessVisitor(float thickness);
    void visit(Circle& circle) override;
    void visit(Rectangle& rectangle) override;
    void visit(Triangle& triangle) override;
    void visit(Group& group) override;
};
