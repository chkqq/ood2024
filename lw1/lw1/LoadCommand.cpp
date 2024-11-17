#include "LoadCommand.h"

LoadCommand::LoadCommand(ShapeLoader& l) : loader(l) {}

void LoadCommand::execute(std::vector<std::shared_ptr<Shape>>& shapes)
{
    shapes = loader.loadFromFile("out.txt");
}
