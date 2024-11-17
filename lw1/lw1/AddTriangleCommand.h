#pragma once
#include "Command.h"
#include "shapes.h"

class AddTriangleCommand : public Command
{
public:
    void execute(std::vector<std::shared_ptr<Shape>>& shapes) override;
};
