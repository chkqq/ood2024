#include "text.hpp"
#include <sstream>

namespace shapes 
{
    Text::Text(const std::string& id, double left, double top, double fontSize, const std::string& content, gfx::Color color)
        : Shape(id, color), left(left), top(top), fontSize(fontSize), content(content) {}

    void Text::Draw(gfx::ICanvas& canvas)
    {
        canvas.SetColor(color);
        canvas.DrawText(left, top, fontSize, content);
    }

    void Text::Move(double dx, double dy)
    {
        left += dx;
        top += dy;
    }

    std::string Text::GetType() const 
    {
        return "text";
    }

    std::string Text::GetParameters() const
    {
        std::ostringstream oss;
        oss << left << " " << top << " " << fontSize << " " << content;
        return oss.str();
    }
}
