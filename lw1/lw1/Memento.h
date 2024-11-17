#pragma once
#include <vector>
#include <memory>
#include "Shape.h"

class Memento {
private:
    std::vector<std::shared_ptr<Shape>> state;

public:
    Memento(const std::vector<std::shared_ptr<Shape>>& shapes) {
        for (const auto& shape : shapes) {
            state.push_back(shape->clone());  
        }
    }

    std::vector<std::shared_ptr<Shape>> getState() const {
        return state;
    }
};
