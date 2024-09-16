#ifndef SVG_CANVAS_HPP
#define SVG_CANVAS_HPP

#include "icanvas.hpp"
#include <fstream>

namespace gfx 
{

    class SVGCanvas : public ICanvas
    {
    private:
        std::ofstream file;
        Color currentColor;
        bool isOpen;

    public:
        SVGCanvas(const std::string& filename);
        ~SVGCanvas();

        void SetColor(Color color) override;
        void DrawEllipse(double cx, double cy, double rx, double ry) override;
        void DrawRectangle(double cx, double cy, double width, double height) override;
        void DrawLine(double x1, double y1, double x2, double y2) override;
        void DrawTriangle(double x1, double y1, double x2, double y2, double x3, double y3) override;
        void DrawText(double left, double top, double fontSize, const std::string& text) override;

    private:
        void OpenOrCreateFile(const std::string& filename);
    };

}

#endif 
