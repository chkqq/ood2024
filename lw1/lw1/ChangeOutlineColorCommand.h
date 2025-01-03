#pragma once
#include "Command.h"
#include "ChangeOutlineColorVisitor.h"

class ChangeOutlineColorCommand : public Command
{
private:
    sf::Color color;

public:
    ChangeOutlineColorCommand(sf::Color newColor);
    void execute(std::vector<std::shared_ptr<Shape>>& shapes) override;
};
