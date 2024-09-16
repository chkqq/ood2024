#include "canvas.hpp"

gfx::SVGCanvas::SVGCanvas(const std::string& filename)
    : currentColor("#000000") { // Инициализируем цвет черным
    file.open(filename);
    file << "<svg xmlns=\"http://www.w3.org/2000/svg\">\n";
}

gfx::SVGCanvas::~SVGCanvas() {
    file << "</svg>";
    file.close();
}

void gfx::SVGCanvas::MoveTo(double x, double y) {
    // SVG moveTo logic (если нужно)
}

void gfx::SVGCanvas::LineTo(double x, double y) {
    // SVG lineTo logic (если нужно)
}

void gfx::SVGCanvas::SetColor(gfx::Color color) {
    currentColor = color; // Устанавливаем текущий цвет
}

void gfx::SVGCanvas::DrawEllipse(double cx, double cy, double rx, double ry) {
    // Используем текущий цвет для заливки и обводки эллипса
    file << "<ellipse cx=\"" << cx << "\" cy=\"" << cy << "\" rx=\"" << rx << "\" ry=\"" << ry
        << "\" style=\"fill:" << currentColor.value << ";stroke:" << currentColor.value << ";stroke-width:2\" />\n";
}

void gfx::SVGCanvas::DrawRectangle(double left, double top, double width, double height) {
    file << "<rect x=\"" << left << "\" y=\"" << top << "\" width=\"" << width << "\" height=\"" << height
        << "\" style=\"fill:" << currentColor.value << ";stroke:" << currentColor.value << ";stroke-width:2\" />\n";
}

void gfx::SVGCanvas::DrawTriangle(double x1, double y1, double x2, double y2, double x3, double y3) {
    file << "<polygon points=\""
        << x1 << "," << y1 << " "
        << x2 << "," << y2 << " "
        << x3 << "," << y3
        << "\" style=\"fill:" << currentColor.value
        << ";stroke:" << currentColor.value
        << ";stroke-width:2\" />\n";
}
    

void gfx::SVGCanvas::DrawLine(double x1, double y1, double x2, double y2) {
    file << "<line x1=\"" << x1 << "\" y1=\"" << y1 << "\" x2=\"" << x2 << "\" y2=\"" << y2
        << "\" style=\"stroke:" << currentColor.value << ";stroke-width:2\" />\n";
}


void gfx::SVGCanvas::DrawText(double left, double top, double fontSize, const std::string& text) {
    file << "<text x=\"" << left << "\" y=\"" << top << "\" font-size=\"" << fontSize << "\" fill=\"" << currentColor.value << "\">" << text << "</text>\n";
}
