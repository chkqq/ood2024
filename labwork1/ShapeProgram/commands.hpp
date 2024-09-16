#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <string>
#include "shape.hpp"
#include "picture.hpp"

namespace commands {
    bool ExecuteCommand(const std::string& command, shapes::Picture& picture);
}

#endif