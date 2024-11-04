#pragma once
#include <stack>
#include "Memento.h"

class Caretaker {
private:
    std::stack<Memento> history;

public:
    void save(const Memento& memento) {
        history.push(memento);
    }

    bool hasUndo() const {
        return !history.empty();
    }

    Memento undo() {
        if (!history.empty()) {
            Memento memento = history.top();
            history.pop();
            return memento;
        }
        throw std::runtime_error("No state to undo");
    }
};
