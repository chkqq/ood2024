#include "Caretaker.h"

void Caretaker::Save(const std::shared_ptr<Memento>& state)
{
    m_history.push_back(state);
}

bool Caretaker::CanUndo() const
{
    return !m_history.empty();
}

std::shared_ptr<Memento> Caretaker::Undo()
{
    if (!m_history.empty())
    {
        std::shared_ptr<Memento> lastState = m_history.back();
        m_history.pop_back();
        return lastState;
    }
}
