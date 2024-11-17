#pragma once
#include "Command.h"
#include "Application.h"
#include <memory>
#include <vector>

class UndoCommand : public Command {
public:
    void execute(std::vector<std::shared_ptr<Shape>>& shapes) override;
};
