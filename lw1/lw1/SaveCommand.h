#pragma once
#include "Command.h"
#include "SaveStrategy.h"
#include <memory>
#include <vector>

class SaveCommand : public Command {
private:
    SaveStrategy& strategy;

public:
    SaveCommand(SaveStrategy& strat);
    void execute(std::vector<std::shared_ptr<Shape>>& shapes) override;
};
