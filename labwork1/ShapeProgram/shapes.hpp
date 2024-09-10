#ifndef SHAPES_HPP
#define SHAPES_HPP

#include <memory>
#include <vector>
#include <string>
#include "canvas.hpp"

namespace shapes {
    class Shape {
    protected:
        std::string id;  // Уникальный идентификатор фигуры
    public:
        Shape(const std::string& id) : id(id) {}  // Инициализируем id при создании
        virtual ~Shape() = default;
        virtual void Draw(gfx::ICanvas& canvas) = 0;
        virtual void Move(double dx, double dy) = 0;
        std::string GetID() const { return id; }  // Получить идентификатор фигуры
    };

    class Circle : public Shape {
        double x, y, r;
        gfx::Color color;
    public:
        Circle(const std::string& id, double x, double y, double r, gfx::Color color);
        void Draw(gfx::ICanvas& canvas) override;
        void Move(double dx, double dy) override;
    };

    class Picture {
        std::vector<std::shared_ptr<Shape>> shapes;
    public:
        void AddShape(std::shared_ptr<Shape> shape);
        void Move(double dx, double dy);
        void Draw(gfx::ICanvas& canvas);
        std::shared_ptr<Shape> GetShapeByID(const std::string& id); // Поиск фигуры по ID
        void ListShapes(); // Вывод списка фигур
    };
}

#endif // SHAPES_HPP
