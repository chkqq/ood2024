#include "canvas.hpp"

gfx::SVGCanvas::SVGCanvas(const std::string& filename)
    : currentColor("#000000") { // �������������� ���� ������
    file.open(filename);
    file << "<svg xmlns=\"http://www.w3.org/2000/svg\">\n";
}

gfx::SVGCanvas::~SVGCanvas() {
    file << "</svg>";
    file.close();
}

void gfx::SVGCanvas::MoveTo(double x, double y) {
    // SVG moveTo logic (���� �����)
}

void gfx::SVGCanvas::LineTo(double x, double y) {
    // SVG lineTo logic (���� �����)
}

void gfx::SVGCanvas::SetColor(gfx::Color color) {
    currentColor = color; // ������������� ������� ����
}

void gfx::SVGCanvas::DrawEllipse(double cx, double cy, double rx, double ry) {
    // ���������� ������� ���� ��� ������� � ������� �������
    file << "<ellipse cx=\"" << cx << "\" cy=\"" << cy << "\" rx=\"" << rx << "\" ry=\"" << ry
        << "\" style=\"fill:" << currentColor.value << ";stroke:" << currentColor.value << ";stroke-width:2\" />\n";
}

void gfx::SVGCanvas::DrawText(double left, double top, double fontSize, const std::string& text) {
    file << "<text x=\"" << left << "\" y=\"" << top << "\" font-size=\"" << fontSize << "\" fill=\"" << currentColor.value << "\">" << text << "</text>\n";
}
