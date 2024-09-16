#ifndef SHAPES_HPP
#define SHAPES_HPP

#include <memory>
#include <vector>
#include <string>
#include "canvas.hpp"
#include <unordered_set>
#include <stdexcept>

namespace shapes {
    class Shape {
    protected:
        std::string id;  
        gfx::Color color;// Уникальный идентификатор фигуры
    public:
        Shape(const std::string& id, gfx::Color color) : id(id), color(color) {}  // Инициализируем id при создании
        virtual ~Shape() = default;
        virtual void Draw(gfx::ICanvas& canvas) = 0;
        virtual void Move(double dx, double dy) = 0;
        gfx::Color GetColor() const { return color; }
        virtual std::string GetType() const = 0;
        virtual std::string GetParameters() const = 0;
        std::string GetID() const { return id; }  // Получить идентификатор фигуры
    };

    class Picture {
        std::vector<std::shared_ptr<Shape>> shapes;
        std::unordered_set<std::string> shapeNames;
    public:
        void AddShape(std::shared_ptr<Shape> shape);
        void ChangeShape(const std::string& id, std::shared_ptr<Shape> newShape);
        void Move(double dx, double dy);
        void Draw(gfx::ICanvas& canvas);
        std::shared_ptr<Shape> GetShapeByID(const std::string& id); // Поиск фигуры по ID
        void ListShapes(); // Вывод списка фигур

        bool DeleteShape(const std::string& id);
    };

    class Circle : public Shape {
        double x, y, r;
    public:
        Circle(const std::string& id, double x, double y, double r, gfx::Color color);
        void Draw(gfx::ICanvas& canvas) override;
        void Move(double dx, double dy) override;
        std::string GetParameters() const;
        std::string GetType() const;
    };

    // Прямоугольник
    class Rectangle : public Shape {
        double left, top, width, height;
    public:
        Rectangle(const std::string& id, double left, double top, double width, double height, gfx::Color color);
        void Draw(gfx::ICanvas& canvas) override;
        void Move(double dx, double dy) override;
        std::string GetParameters() const;
        std::string GetType() const;
    };

    // Треугольник
    class Triangle : public Shape {
        double x1, y1, x2, y2, x3, y3;
    public:
        Triangle(const std::string& id, double x1, double y1, double x2, double y2, double x3, double y3, gfx::Color color);
        void Draw(gfx::ICanvas& canvas) override;
        void Move(double dx, double dy) override;

        std::string GetParameters() const;
        std::string GetType() const;
    };

    // Линия
    class Line : public Shape {
        double x1, y1, x2, y2;
    public:
        Line(const std::string& id, double x1, double y1, double x2, double y2, gfx::Color color);
        void Draw(gfx::ICanvas& canvas) override;
        void Move(double dx, double dy) override;

        std::string GetParameters() const;
        std::string GetType() const;
    };

    // Текст
    class Text : public Shape {
        double left, top, fontSize;
        std::string content;
    public:
        Text(const std::string& id, double left, double top, double fontSize, const std::string& content, gfx::Color color);
        void Draw(gfx::ICanvas& canvas) override;
        void Move(double dx, double dy) override;

        std::string GetParameters() const;
        std::string GetType() const;
    };

}

#endif // SHAPES_HPP
