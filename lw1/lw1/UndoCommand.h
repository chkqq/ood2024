#pragma once
#include "Command.h"
#include "Application.h"

class UndoCommand : public Command {
public:
    void execute(std::vector<std::shared_ptr<Shape>>& shapes) override {
        auto app = Application::getInstance();
        app->Undo();
    }
};
