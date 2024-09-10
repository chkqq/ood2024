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

void gfx::SVGCanvas::DrawText(double left, double top, double fontSize, const std::string& text) {
    file << "<text x=\"" << left << "\" y=\"" << top << "\" font-size=\"" << fontSize << "\" fill=\"" << currentColor.value << "\">" << text << "</text>\n";
}
