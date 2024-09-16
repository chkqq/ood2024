#ifndef ICANVAS_HPP
#define ICANVAS_HPP

#include "color.hpp"
#include <string>

namespace gfx 
{
    class ICanvas
    {
    public:
        virtual ~ICanvas() = default;
        virtual void SetColor(Color color) = 0;

        virtual void DrawEllipse(double cx, double cy, double rx, double ry) = 0;
        virtual void DrawRectangle(double cx, double cy, double width, double height) = 0;
        virtual void DrawLine(double x1, double y1, double x2, double y2) = 0;
        virtual void DrawTriangle(double x1, double y1, double x2, double y2, double x3, double y3) = 0;
        virtual void DrawText(double left, double top, double fontSize, const std::string& text) = 0;
    };

}

#endif 