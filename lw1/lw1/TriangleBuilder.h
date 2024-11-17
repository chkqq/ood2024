#pragma once
#include "ShapeBuilder.h"
#include "Triangle.h"
#include <sstream>

class TriangleBuilder : public ShapeBuilder {
private:
    std::shared_ptr<Triangle> triangle;

public:
    void buildShape(const std::string& data) override;
    std::shared_ptr<Shape> getResult() override;
};
