#pragma once
#include "Command.h"
#include "ChangeFillColorVisitor.h"

class ChangeFillColorCommand : public Command
{
private:
    sf::Color color;

public:
    ChangeFillColorCommand(sf::Color newColor) : color(newColor) {}

    void execute(std::vector<std::shared_ptr<Shape>>& shapes) override
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
};