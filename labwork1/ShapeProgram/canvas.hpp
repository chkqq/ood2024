#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <string>
#include <fstream>

namespace gfx {
    class Color {
    public:
        std::string value;
        Color(const std::string& val = "#000000") : value(val) {}
    };

    class ICanvas {
    public:
        virtual ~ICanvas() = default;
        virtual void MoveTo(double x, double y) = 0;
        virtual void LineTo(double x, double y) = 0;
        virtual void SetColor(Color color) = 0;
        virtual void DrawEllipse(double cx, double cy, double rx, double ry) = 0;
        virtual void DrawText(double left, double top, double fontSize, const std::string& text) = 0;
    };

    class SVGCanvas : public ICanvas {
    private:
        std::ofstream file;
        Color currentColor; // Добавляем текущий цвет
    public:
        SVGCanvas(const std::string& filename);
        ~SVGCanvas();
        void MoveTo(double x, double y) override;
        void LineTo(double x, double y) override;
        void SetColor(Color color) override;
        void DrawEllipse(double cx, double cy, double rx, double ry) override;
        void DrawText(double left, double top, double fontSize, const std::string& text) override;
    };
}

#endif // CANVAS_HPP
