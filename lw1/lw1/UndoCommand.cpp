#include "UndoCommand.h"

void UndoCommand::execute(std::vector<std::shared_ptr<Shape>>& shapes)
{
    auto app = Application::getInstance();
    app->Undo();
}
