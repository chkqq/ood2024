#include "ShapeGroup.h"

void ShapeGroup::AddShape(std::shared_ptr<Shape> shape) {
    shapes.push_back(shape);
}

void ShapeGroup::Draw(sf::RenderWindow& window) {
    for (const auto& shape : shapes) {
        shape->Draw(window);
    }
}

std::vector<std::shared_ptr<Shape>> ShapeGroup::GetShapes() {
    return shapes;
}

void ShapeGroup::ClearShapes() {
    shapes.clear();
}
