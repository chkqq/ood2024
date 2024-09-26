#include "line.hpp"
#include <sstream>

namespace shapes 
{
    Line::Line(const std::string& id, double x1, double y1, double x2, double y2, gfx::Color color)
        : Shape(id, color), x1(x1), y1(y1), x2(x2), y2(y2) {}

    void Line::Draw(gfx::ICanvas& canvas)
    {
        canvas.SetColor(color);
        canvas.DrawLine(x1, y1, x2, y2);
    }

    void Line::MoveBy(double dx, double dy)
    {
        x1 += dx; y1 += dy;
        x2 += dx; y2 += dy;
    }

    std::string Line::GetType() const
    {
        return "line";
    }

    std::string Line::GetParameters() const 
    {
        std::ostringstream oss;
        oss << x1 << " " << y1 << " " << x2 << " " << y2;
        return oss.str();
    }
}
