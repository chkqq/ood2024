#pragma once
#include <vector>
#include <memory>
#include <fstream>
#include <stdexcept>
#include "ShapeBuilder.h"

class ShapeLoader {
public:
    std::vector<std::shared_ptr<Shape>> loadFromFile(const std::string& filename, std::vector<std::unique_ptr<ShapeBuilder>>& builders) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file for loading");
        }

        std::vector<std::shared_ptr<Shape>> shapes;
        std::string line;

        while (std::getline(file, line)) {
            for (auto& builder : builders) {
                builder->buildShape(line);
                auto shape = builder->getResult();
                if (shape) {
                    shapes.push_back(shape);
                    break;
                }
            }
        }

        file.close();
        return shapes;
    }
};
