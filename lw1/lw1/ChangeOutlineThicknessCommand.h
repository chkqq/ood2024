#pragma once
#include "Command.h"
#include "ChangeOutlineThicknessVisitor.h"

class ChangeOutlineThicknessCommand : public Command
{
private:
    float outlineThickness;

public:
    ChangeOutlineThicknessCommand(float thickness);
    void execute(std::vector<std::shared_ptr<Shape>>& shapes) override;
};
