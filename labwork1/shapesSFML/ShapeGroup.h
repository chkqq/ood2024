#ifndef SHAPEGROUP_H
#define SHAPEGROUP_H

#include <vector>
#include <memory>
#include "Shape.h"

class ShapeGroup {
public:
    void AddShape(std::shared_ptr<Shape> shape);
    void Draw(sf::RenderWindow& window);
    std::vector<std::shared_ptr<Shape>> GetShapes(); // Метод для получения фигур
    void ClearShapes(); // Метод для очистки фигур

private:
    std::vector<std::shared_ptr<Shape>> shapes;
};

#endif
