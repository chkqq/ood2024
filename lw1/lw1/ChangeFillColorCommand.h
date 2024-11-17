#pragma once
#include "Command.h"
#include "ChangeFillColorVisitor.h"

class ChangeFillColorCommand : public Command
{
private:
    sf::Color color;

public:
    ChangeFillColorCommand(sf::Color newColor);
    void execute(std::vector<std::shared_ptr<Shape>>& shapes) override;
};
