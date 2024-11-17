    #pragma once
    #include "ShapeLoader.h"
    #include "Command.h"

    class LoadCommand : public Command {
    private:
        ShapeLoader& loader;

    public:
        LoadCommand(ShapeLoader& l) : loader(l) {}

        void execute(std::vector<std::shared_ptr<Shape>>& shapes) override {
            shapes = loader.loadFromFile("out.txt");
        }
    };
