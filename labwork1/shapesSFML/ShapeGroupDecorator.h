#ifndef SHAPEGROUPDECORATOR_H
#define SHAPEGROUPDECORATOR_H

#include "ShapeDecorator.h"
#include "ShapeGroup.h"

class ShapeGroupDecorator : public ShapeDecorator {
private:
    sf::Color fillColor;
    sf::Color outlineColor;
    float outlineThickness;
public:
    ShapeGroupDecorator(std::shared_ptr<ShapeGroup> group, sf::Color fillColor, sf::Color outlineColor, float outlineThickness)
        : ShapeDecorator(group), fillColor(fillColor), outlineColor(outlineColor), outlineThickness(outlineThickness) {}

    void Draw(sf::RenderWindow& window) {
        // Применяем изменения цвета, окантовки ко всей группе
        auto shapeGroup = dynamic_cast<ShapeGroup*>(m_shape.get());
        if (shapeGroup) {
            for (auto& shape : shapeGroup->GetShapes()) {
                shape->SetFillColor(fillColor);            // Меняем цвет заливки
                shape->SetOutlineColor(outlineColor);      // Меняем цвет окантовки
                shape->SetOutlineThickness(outlineThickness); // Меняем толщину окантовки
            }
        }
        ShapeDecorator::Draw(window);
    }
};

#endif
