#include "ShapeLoader.h"
#include "ShapeBuilder.h"
#include "Command.h"
#include "Builders.h"

class LoadCommand : public Command {
private:
    ShapeLoader& loader;

public:
    LoadCommand(ShapeLoader& l) : loader(l) {}

    void execute(std::vector<std::shared_ptr<Shape>>& shapes) override {
        std::vector<std::unique_ptr<ShapeBuilder>> builders;
        builders.push_back(std::make_unique<CircleBuilder>());
        builders.push_back(std::make_unique<RectangleBuilder>());
        builders.push_back(std::make_unique<TriangleBuilder>());
        builders.push_back(std::make_unique<GroupBuilder>(builders));

        shapes = loader.loadFromFile("in.txt", builders);
    }
};
