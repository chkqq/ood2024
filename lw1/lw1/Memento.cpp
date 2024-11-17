#include "Memento.h"

Memento::Memento(const std::vector<std::shared_ptr<Shape>>& shapes)
{
    for (const auto& shape : shapes) {
        state.push_back(shape->clone());
    }
}

std::vector<std::shared_ptr<Shape>> Memento::getState() const
{
    return state;
}
