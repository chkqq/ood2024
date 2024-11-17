#pragma once
#include "memento.h"

class Caretaker
{
public:
	void Save(const std::shared_ptr<Memento>& state)
	{
		m_history.push_back(state);
	};

	bool CanUndo() const
	{
		return !m_history.empty();
	};

	std::shared_ptr<Memento> Undo()
	{
		if (!m_history.empty())
		{
			std::shared_ptr<Memento> lastState = m_history.back();
			m_history.pop_back();
			return lastState;
		}
	};

private:
	std::vector<std::shared_ptr<Memento>> m_history;
};