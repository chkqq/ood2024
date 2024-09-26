#include "circle.hpp"
#include <sstream>

namespace shapes
{
    Circle::Circle(const std::string& id, double x, double y, double r, gfx::Color color)
        : Shape(id, color), x(x), y(y), r(r) {}

    void Circle::Draw(gfx::ICanvas& canvas)
    {
        canvas.SetColor(color);
        canvas.DrawEllipse(x, y, r, r);
    }

    void Circle::MoveBy(double dx, double dy)
    {
        x += dx;
        y += dy;
    }

    std::string Circle::GetType() const
    {
        return "circle";
    }

    std::string Circle::GetParameters() const
    {
        std::ostringstream oss;
        oss << x << " " << y << " " << r;
        return oss.str();
    }
}
