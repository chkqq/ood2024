#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <string>
#include "shapes.hpp"

namespace commands {
    bool ExecuteCommand(const std::string& command, shapes::Picture& picture);
}

#endif // COMMANDS_HPP
