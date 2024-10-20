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

        auto shapeGroup = dynamic_cast<ShapeGroup*>(m_shape.get());
        if (shapeGroup) {
            for (auto& shape : shapeGroup->GetShapes()) {
                shape->SetFillColor(fillColor);
                shape->SetOutlineColor(outlineColor); 
                shape->SetOutlineThickness(outlineThickness); 
            }
        }
        ShapeDecorator::Draw(window);
    }
};

#endif
