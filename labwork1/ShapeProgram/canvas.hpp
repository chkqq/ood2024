#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <string>
#include <fstream>

namespace gfx {

    // Класс для хранения цвета в SVG формате
    class Color {
    public:
        std::string value;
        Color(const std::string& val = "#000000") : value(val) {}
    };

    // Интерфейс для Canvas
    class ICanvas {
    public:
        virtual ~ICanvas() = default;

        // Методы для перемещения, рисования линий и установки цвета
        virtual void MoveTo(double x, double y) = 0;
        virtual void LineTo(double x, double y) = 0;
        virtual void SetColor(Color color) = 0;

        // Методы для рисования эллипсов, прямоугольников, линий, треугольников и текста
        virtual void DrawEllipse(double cx, double cy, double rx, double ry) = 0;
        virtual void DrawRectangle(double cx, double cy, double width, double height) = 0;
        virtual void DrawLine(double x1, double y1, double x2, double y2) = 0;
        virtual void DrawTriangle(double x1, double y1, double x2, double y2, double x3, double y3) = 0;
        virtual void DrawText(double left, double top, double fontSize, const std::string& text) = 0;
    };

    // Реализация Canvas для создания SVG файлов
    class SVGCanvas : public ICanvas {
    private:
        std::ofstream file;  // Файл для записи SVG
        Color currentColor;   // Текущий цвет для рисования

    public:
        // Конструктор, открывающий файл для записи
        SVGCanvas(const std::string& filename);
        // Деструктор, закрывающий тег SVG и файл
        ~SVGCanvas();

        // Переопределенные методы интерфейса ICanvas
        void MoveTo(double x, double y) override;
        void LineTo(double x, double y) override;
        void SetColor(Color color) override;
        void DrawEllipse(double cx, double cy, double rx, double ry) override;
        void DrawRectangle(double cx, double cy, double width, double height) override;
        void DrawLine(double x1, double y1, double x2, double y2) override;
        void DrawTriangle(double x1, double y1, double x2, double y2, double x3, double y3) override;
        void DrawText(double left, double top, double fontSize, const std::string& text) override;
    };

} // namespace gfx

#endif // CANVAS_HPP
