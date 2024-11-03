#pragma once
#include "Command.h"
#include "shapes.h"
class AddRectangleCommand : public Command
{
public:
    void execute(std::vector<std::shared_ptr<Shape>>& shapes) override
    {
        shapes.push_back(std::make_shared<Rectangle>(sf::Vector2f(200 - 100, 200 - 100), sf::Vector2f(100, 100)));
    }
};