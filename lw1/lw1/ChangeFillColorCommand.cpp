#include "ChangeFillColorCommand.h"

ChangeFillColorCommand::ChangeFillColorCommand(sf::Color newColor)
    : color(newColor) {}

void ChangeFillColorCommand::execute(std::vector<std::shared_ptr<Shape>>& shapes)
{
    ChangeFillColorVisitor visitor(color);
    for (auto& shape : shapes)
    {
        if (shape->IsSelected())
        {
            shape->accept(visitor);
        }
    }
}
