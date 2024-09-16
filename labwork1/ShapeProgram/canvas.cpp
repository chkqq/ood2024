#include "svgCanvas.hpp"
#include <iostream>

namespace gfx
{
    SVGCanvas::SVGCanvas(const std::string& filename) : isOpen(false) 
    {
        OpenOrCreateFile(filename);
    }

    SVGCanvas::~SVGCanvas() 
    {
        if (isOpen) 
        {
            file << "</svg>\n";
            file.close();
        }
    }

    void SVGCanvas::OpenOrCreateFile(const std::string& filename) 
    {
        if (!isOpen) 
        {
            file.open(filename, std::ios::app);
            if (!file.is_open()) 
            {
                std::cerr << "Error opening file: " << filename << std::endl;
                return;
            }
            if (file.tellp() == 0)
            {
                file << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">\n";
            }
            isOpen = true;
        }
    }

    void SVGCanvas::SetColor(Color color) 
    {
        currentColor = color;
    }

    void SVGCanvas::DrawEllipse(double cx, double cy, double rx, double ry) 
    {
        file << "<ellipse cx=\"" << cx << "\" cy=\"" << cy << "\" rx=\"" << rx << "\" ry=\"" << ry
            << "\" style=\"fill:" << currentColor.value << ";\" />\n";
    }

    void SVGCanvas::DrawRectangle(double cx, double cy, double width, double height) 
    {
        file << "<rect x=\"" << cx << "\" y=\"" << cy << "\" width=\"" << width << "\" height=\"" << height
            << "\" style=\"fill:" << currentColor.value << ";\" />\n";
    }

    void SVGCanvas::DrawLine(double x1, double y1, double x2, double y2) 
    {
        file << "<line x1=\"" << x1 << "\" y1=\"" << y1 << "\" x2=\"" << x2 << "\" y2=\"" << y2
            << "\" style=\"stroke:" << currentColor.value << ";\" />\n";
    }

    void SVGCanvas::DrawTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
    {
        file << "<polygon points=\"" << x1 << "," << y1 << " " << x2 << "," << y2 << " " << x3 << "," << y3
            << "\" style=\"fill:" << currentColor.value << ";\" />\n";
    }

    void SVGCanvas::DrawText(double left, double top, double fontSize, const std::string& text) 
    {
        file << "<text x=\"" << left << "\" y=\"" << top << "\" font-size=\"" << fontSize << "\" fill=\"" << currentColor.value
            << "\">" << text << "</text>\n";
    }

}