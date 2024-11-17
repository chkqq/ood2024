#include "ChangeOutlineThicknessCommand.h"

ChangeOutlineThicknessCommand::ChangeOutlineThicknessCommand(float thickness)
    : outlineThickness(thickness) {}

void ChangeOutlineThicknessCommand::execute(std::vector<std::shared_ptr<Shape>>& shapes)
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
