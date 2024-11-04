#pragma once
#include <vector>
#include <memory>
#include "Shape.h"

class SaveStrategy {
public:
    virtual void saveToFile(const std::string& filename, const std::vector<std::shared_ptr<Shape>>& shapes) = 0;
    virtual ~SaveStrategy() = default;
};
