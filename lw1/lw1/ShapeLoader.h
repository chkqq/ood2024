#pragma once
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "builders.h"

class ShapeLoader {
public:

    // Пример использования в ShapeLoader
    std::vector<std::shared_ptr<Shape>> loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file for loading");
        }

        std::vector<std::shared_ptr<Shape>> shapes;
        std::string line;

        // Создаем все доступные билдеры
        std::vector<std::unique_ptr<ShapeBuilder>> builders;
        builders.push_back(std::make_unique<CircleBuilder>());
        builders.push_back(std::make_unique<RectangleBuilder>());
        builders.push_back(std::make_unique<TriangleBuilder>());

        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string type;
            iss >> type;

            std::unique_ptr<ShapeBuilder> builder;

            if (type == "Circle") {
                builder = std::make_unique<CircleBuilder>();
            }
            else if (type == "Rectangle") {
                builder = std::make_unique<RectangleBuilder>();
            }
            else if (type == "Triangle") {
                builder = std::make_unique<TriangleBuilder>();
            }
            else if (type == "Group") {
                // Для группы передаем список билдов
                builder = std::make_unique<GroupBuilder>(builders);
            }

            if (builder) {
                builder->buildShape(line);
                auto shape = builder->getResult();
                if (shape) {
                    shapes.push_back(shape);
                }
            }
        }

        file.close();
        return shapes;
    }

};
