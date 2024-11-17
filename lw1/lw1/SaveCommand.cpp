#include "SaveCommand.h"

SaveCommand::SaveCommand(SaveStrategy& strat) : strategy(strat) {}

void SaveCommand::execute(std::vector<std::shared_ptr<Shape>>& shapes)
{
    strategy.saveToFile("out.txt", shapes);
}
