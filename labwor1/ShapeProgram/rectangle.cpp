#include "rectangle.hpp"
#include <sstream>

namespace shapes
{
    Rectangle::Rectangle(const std::string& id, double left, double top, double width, double height, gfx::Color color)
        : Shape(id, color), left(left), top(top), width(width), height(height) {}

    void Rectangle::Draw(gfx::ICanvas& canvas) 
    {
        canvas.SetColor(color);
        canvas.DrawRectangle(left, top, width, height);
    }

    void Rectangle::MoveBy(double dx, double dy) 
    {
        left += dx; 
        top += dy;
    }
    std::string Rectangle::GetType() const
    {
        return "rectangle";
    }

    std::string Rectangle::GetParameters() const 
    {
        std::ostringstream oss;
        oss << left << " " << top << " " << width << " " << height;
        return oss.str();
    }
}