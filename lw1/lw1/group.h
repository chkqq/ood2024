#pragma once
#include "shape.h"
#include <vector>
#include <memory>
#include <algorithm>

class Group : public Shape
{
protected:
    std::vector<std::shared_ptr<Shape>> m_group;
    sf::RectangleShape m_frame;
    bool m_isSelected = true;

public:
    void MakeFrame()
    {
        m_frame.setPosition(GetPosition());
        m_frame.setSize(sf::Vector2f(GetRightDownCorner().x - GetPosition().x, GetRightDownCorner().y - GetPosition().y));
        m_frame.setFillColor(sf::Color::Transparent);
        m_frame.setOutlineThickness(2);
        m_frame.setOutlineColor(sf::Color::Green);
    }

    void AddShape(std::shared_ptr<Shape> shape)
    {
        m_group.push_back(shape);
    }

    void DeleteShape(std::shared_ptr<Shape> shape)
    {
        m_group.erase(std::remove(m_group.begin(), m_group.end(), shape), m_group.end());
    }

    std::vector<std::shared_ptr<Shape>> GetShapes() { return m_group; }

    bool IsEmpty() const { return m_group.empty(); }

    void Draw(sf::RenderWindow& window) override
    {
        for (const auto& shape : m_group)
            shape->Draw(window);
        if (m_isSelected)
            window.draw(m_frame);
    }

    bool Contains(const sf::Vector2f& point) const override
    {
        for (const auto& shape : m_group)
            if (shape->Contains(point))
                return true;
        return false;
    }

    sf::Vector2f GetPosition() const override
    {
        if (!m_group.empty())
        {
            float minX = m_group[0]->GetPosition().x;
            float minY = m_group[0]->GetPosition().y;
            for (const auto& shape : m_group)
            {
                minX = std::min(minX, shape->GetPosition().x);
                minY = std::min(minY, shape->GetPosition().y);
            }
            return sf::Vector2f(minX, minY);
        }
        return sf::Vector2f(0, 0);
    }

    sf::Vector2f GetRightDownCorner() const override
    {
        if (!m_group.empty())
        {
            float maxX = m_group[0]->GetRightDownCorner().x;
            float maxY = m_group[0]->GetRightDownCorner().y;
            for (const auto& shape : m_group)
            {
                maxX = std::max(maxX, shape->GetRightDownCorner().x);
                maxY = std::max(maxY, shape->GetRightDownCorner().y);
            }
            return sf::Vector2f(maxX, maxY);
        }
        return sf::Vector2f(0, 0);
    }

    void Move(const sf::Vector2f& offset) override
    {
        for (auto& shape : m_group)
            shape->Move(offset);
        m_frame.move(offset);
    }
    void accept(Visitor& visitor) override
    {
        visitor.visit(*this);
    }
    void Select(bool select) override { m_isSelected = select; }
    bool IsSelected() const override { return m_isSelected; }
    bool IsGroup() const override { return true; }
};
