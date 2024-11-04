#pragma once
#include "Command.h"
#include "Application.h" // Предполагается, что команда знает о приложении или использует синглтон

class UndoCommand : public Command {
public:
    void execute(std::vector<std::shared_ptr<Shape>>& shapes) override {
        auto app = Application::getInstance();
        app->undoLastAction();
    }
};
