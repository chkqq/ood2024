#include <iomanip> 
#include "shapes.hpp"
#include <iostream>
#include <sstream>

using namespace shapes;

void Picture::AddShape(std::shared_ptr<Shape> shape) {
    if (shapeNames.count(shape->GetID()) > 0) {
        std::cout << "Shape with id '" << shape->GetID() << "' already exists!" << std::endl;
        return;
    }
    shapes.push_back(shape);
    shapeNames.insert(shape->GetID());
}

void Picture::ChangeShape(const std::string& id, std::shared_ptr<Shape> newShape) {
    auto it = std::find_if(shapes.begin(), shapes.end(),
        [&id](const std::shared_ptr<Shape>& shape) { return shape->GetID() == id; });

    if (it != shapes.end()) {
        *it = newShape;
    }
    else {
        std::cout << "Shape with id '" << id << "' not found!" << std::endl;
    }
}

void Picture::Draw(gfx::ICanvas& canvas) {
    for (auto& shape : shapes) {
        shape->Draw(canvas);
    }
}

void Picture::Move(double dx, double dy) {
    for (auto& shape : shapes) {
        shape->Move(dx, dy);
    }
}
bool Picture::DeleteShape(const std::string& id) {
    auto it = std::remove_if(shapes.begin(), shapes.end(),
        [&id](const std::shared_ptr<Shape>& shape) { return shape->GetID() == id; });
    if (it != shapes.end()) {
        shapeNames.erase(id); // Удаляем имя из контейнера
        shapes.erase(it, shapes.end());
        return true;
    }
    return false;
}

// Поиск фигуры по ID
std::shared_ptr<Shape> Picture::GetShapeByID(const std::string& id) {
    for (const auto& shape : shapes) {
        if (shape->GetID() == id) {
            return shape;
        }
    }
    return nullptr;
}

// Вывод списка фигур

void Picture::ListShapes() {
    int index = 1;
    for (const auto& shape : shapes) {
        std::cout << index << " " << shape->GetType() << " " << shape->GetID() << " "
            << shape->GetColor().value << " " << shape->GetParameters() << std::endl;
        index++;
    }
}

Circle::Circle(const std::string& id, double x, double y, double r, gfx::Color color)
    : Shape(id, color), x(x), y(y), r(r) {}

void Circle::Draw(gfx::ICanvas& canvas) {
    canvas.SetColor(color);
    canvas.DrawEllipse(x, y, r, r);
}

void Circle::Move(double dx, double dy) {
    x += dx;
    y += dy;
}

std::string Circle::GetType() const {
    return "circle";
}

std::string Circle::GetParameters() const {
    std::ostringstream oss;
    oss << x << " " << y << " " << r;
    return oss.str();
}

Rectangle::Rectangle(const std::string& id, double left, double top, double width, double height, gfx::Color color)
    : Shape(id, color), left(left), top(top), width(width), height(height) {}

void Rectangle::Draw(gfx::ICanvas& canvas) {
    canvas.SetColor(color);
    canvas.DrawRectangle(left, top, width, height);
}

void Rectangle::Move(double dx, double dy) {
    left += dx;
    top += dy;
}

std::string Rectangle::GetType() const {
    return "rectangle";
}

std::string Rectangle::GetParameters() const {
    std::ostringstream oss;
    oss << left << " " << top << " " << width << " " << height;
    return oss.str();
}

Triangle::Triangle(const std::string& id, double x1, double y1, double x2, double y2, double x3, double y3, gfx::Color color)
    : Shape(id, color), x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {}

void Triangle::Draw(gfx::ICanvas& canvas) {
    canvas.SetColor(color);
    canvas.DrawTriangle(x1, y1, x2, y2, x3, y3);
}

void Triangle::Move(double dx, double dy) {
    x1 += dx; y1 += dy;
    x2 += dx; y2 += dy;
    x3 += dx; y3 += dy;
}

std::string Triangle::GetType() const {
    return "triangle";
}

std::string Triangle::GetParameters() const {
    std::ostringstream oss;
    oss << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3;
    return oss.str();
}

Line::Line(const std::string& id, double x1, double y1, double x2, double y2, gfx::Color color)
    : Shape(id, color), x1(x1), y1(y1), x2(x2), y2(y2) {}

void Line::Draw(gfx::ICanvas& canvas) {
    canvas.SetColor(color);
    canvas.DrawLine(x1, y1, x2, y2);
}

void Line::Move(double dx, double dy) {
    x1 += dx; y1 += dy;
    x2 += dx; y2 += dy;
}

std::string Line::GetType() const {
    return "line";
}

std::string Line::GetParameters() const {
    std::ostringstream oss;
    oss << x1 << " " << y1 << " " << x2 << " " << y2;
    return oss.str();
}

Text::Text(const std::string& id, double left, double top, double fontSize, const std::string& content, gfx::Color color)
    : Shape(id, color), left(left), top(top), fontSize(fontSize), content(content) {}

void Text::Draw(gfx::ICanvas& canvas) {
    canvas.SetColor(color);
    canvas.DrawText(left, top, fontSize, content);
}

void Text::Move(double dx, double dy) {
    left += dx;
    top += dy;
}

std::string Text::GetType() const {
    return "text";
}

std::string Text::GetParameters() const {
    std::ostringstream oss;
    oss << left << " " << top << " " << fontSize << " " << content;
    return oss.str();
}


