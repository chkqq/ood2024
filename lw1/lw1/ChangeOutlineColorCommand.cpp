#include "ChangeOutlineColorCommand.h"

ChangeOutlineColorCommand::ChangeOutlineColorCommand(sf::Color newColor)
    : color(newColor) {}

void ChangeOutlineColorCommand::execute(std::vector<std::shared_ptr<Shape>>& shapes)
{
    ChangeOutlineColorVisitor visitor(color);
    for (auto& shape : shapes)
    {
        if (shape->IsSelected())
        {
            shape->accept(visitor);
        }
    }
}
