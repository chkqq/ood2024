#pragma once
#include "ShapeBuilder.h"
#include "Circle.h"
#include <sstream>

class CircleBuilder : public ShapeBuilder {
private:
    std::shared_ptr<Circle> circle;

public:
    void buildShape(const std::string& data) override;
    std::shared_ptr<Shape> getResult() override;
};
