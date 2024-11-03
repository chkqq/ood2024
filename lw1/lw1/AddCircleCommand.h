#pragma once
#include "Command.h"
#include "shapes.h"
class AddCircleCommand : public Command
{
public:
    void execute(std::vector<std::shared_ptr<Shape>>& shapes) override
    {
        shapes.push_back(std::make_shared<Circle>(50, sf::Vector2f(200, 200)));
    }
};
