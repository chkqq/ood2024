#pragma once
#include "Command.h"
#include "SaveStrategy.h"

class SaveCommand : public Command {
private:
    SaveStrategy& strategy;

public:
    SaveCommand(SaveStrategy& strat) : strategy(strat) {}

    void execute(std::vector<std::shared_ptr<Shape>>& shapes) override {
        strategy.saveToFile("out.txt", shapes);
    }
};