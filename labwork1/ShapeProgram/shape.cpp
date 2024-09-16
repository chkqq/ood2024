#include "shape.hpp"

namespace shapes
{
    Shape::Shape(const std::string& id, gfx::Color color) : id(id), color(color) {}

    gfx::Color Shape::GetColor() const 
    {
        return color;
    }

    std::string Shape::GetID() const
    {
        return id;
    }
}
