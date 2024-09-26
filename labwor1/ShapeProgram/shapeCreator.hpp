#ifndef SHAPE_CREATOR_HPP
#define SHAPE_CREATOR_HPP

#include <memory>
#include <string>
#include <sstream>
#include "shape.hpp"
#include "color.hpp"

namespace commands
{
    std::shared_ptr<shapes::Shape> CreateShape(const std::string& shapeType, const std::string& id, std::istringstream& iss, const std::string& color);
}

#endif 
