#pragma once
#include "Memento.h"
#include <vector>
#include <memory>

class Caretaker
{
public:
    void Save(const std::shared_ptr<Memento>& state);
    bool CanUndo() const;
    std::shared_ptr<Memento> Undo();

private:
    std::vector<std::shared_ptr<Memento>> m_history;
};
