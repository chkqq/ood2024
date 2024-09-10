#include "shapes.hpp"
#include <iostream>

using namespace shapes;

Circle::Circle(const std::string& id, double x, double y, double r, gfx::Color color)
    : Shape(id), x(x), y(y), r(r), color(color) {}

void Circle::Draw(gfx::ICanvas& canvas) {
    canvas.SetColor(color);
    canvas.DrawEllipse(x, y, r, r);
}

void Circle::Move(double dx, double dy) {
    x += dx;
    y += dy;
}

void Picture::AddShape(std::shared_ptr<Shape> shape) {
    shapes.push_back(shape);
}

void Picture::Move(double dx, double dy) {
    for (auto& shape : shapes) {
        shape->Move(dx, dy);
    }
}


void Picture::Draw(gfx::ICanvas& canvas) {
    for (auto& shape : shapes) {
        shape->Draw(canvas);
    }
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
        std::cout << index << " " << shape->GetID() << std::endl;
        index++;
    }
}
