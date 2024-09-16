#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <string>
#include "shape.hpp"
#include "picture.hpp"
#include "svgCanvas.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "line.hpp"
#include "text.hpp"

namespace commands {
    bool ExecuteCommand(const std::string& command, shapes::Picture& picture);
}

#endif