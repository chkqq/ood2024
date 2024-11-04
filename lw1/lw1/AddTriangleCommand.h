#pragma once
#include "Command.h"
#include "shapes.h"

class AddTriangleCommand : public Command
{
public:
    void execute(std::vector<std::shared_ptr<Shape>>& shapes) override
    {
        shapes.push_back(std::make_shared<Triangle>(sf::Vector2f(100, 200), sf::Vector2f(200, 200), sf::Vector2f(150, 75)));
    }
};