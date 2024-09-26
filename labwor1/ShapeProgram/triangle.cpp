#include "triangle.hpp"
#include <sstream>

namespace shapes
{
    Triangle::Triangle(const std::string& id, double x1, double y1, double x2, double y2, double x3, double y3, gfx::Color color)
        : Shape(id, color), x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {}

    void Triangle::Draw(gfx::ICanvas& canvas)
    {
        canvas.SetColor(color);
        canvas.DrawTriangle(x1, y1, x2, y2, x3, y3);
    }

    void Triangle::MoveBy(double dx, double dy) 
    {
        x1 += dx; y1 += dy;
        x2 += dx; y2 += dy;
        x3 += dx; y3 += dy;
    }

    std::string Triangle::GetType() const
    {
        return "triangle";
    }

    std::string Triangle::GetParameters() const
    {
        std::ostringstream oss;
        oss << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3;
        return oss.str();
    }
}