#pragma once
#include "Command.h"
#include "ShapeLoader.h"
#include <memory>
#include <vector>

class LoadCommand : public Command {
private:
    ShapeLoader& loader;

public:
    LoadCommand(ShapeLoader& l);
    void execute(std::vector<std::shared_ptr<Shape>>& shapes) override;
};
