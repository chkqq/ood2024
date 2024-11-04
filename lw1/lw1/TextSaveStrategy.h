#pragma once
#include "SaveStrategy.h"
#include <fstream>

class TextSaveStrategy : public SaveStrategy {
public:
    void saveToFile(const std::string& filename, const std::vector<std::shared_ptr<Shape>>& shapes) override {
        std::ofstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file for text saving");
        }
        for (const auto& shape : shapes) {
            file << shape->serialize() << std::endl;
        }
        file.close();
    }
};
