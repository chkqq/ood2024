#pragma once
#include "Command.h"
#include "ChangeOutlineThicknessVisitor.h"

class ChangeOutlineThicknessCommand : public Command
{
private:
    float outlineThickness;

public:
    ChangeOutlineThicknessCommand(float thickness) : outlineThickness(thickness) {}

    void execute(std::vector<std::shared_ptr<Shape>>& shapes) override
    {
        ChangeOutlineThicknessVisitor visitor(outlineThickness);
        for (auto& shape : shapes)
        {
            if (shape->IsSelected())
            {
                shape->accept(visitor);
            }
        }
    }
};