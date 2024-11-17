#pragma once
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "builders.h"
#include "group.h"

class ShapeLoader {
public:
    std::vector<std::shared_ptr<Shape>> loadFromFile(const std::string& filename);

private:
    std::unique_ptr<ShapeBuilder> createBuilder(const std::string& type);
};
