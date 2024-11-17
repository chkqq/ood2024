#pragma once
#include "ShapeBuilder.h"
#include "Rectangle.h"
#include <sstream>

class RectangleBuilder : public ShapeBuilder {
private:
    std::shared_ptr<Rectangle> rectangle;

public:
    void buildShape(const std::string& data) override;
    std::shared_ptr<Shape> getResult() override;
};
