#pragma once
#include <memory>
#include "Shape.h"

class ShapeBuilder {
public:
    virtual void buildShape(const std::string& data) = 0;
    virtual std::shared_ptr<Shape> getResult() = 0;
    virtual ~ShapeBuilder() = default;
};
