#pragma once
#include "shape.h"
#include "ShapeDecorator.h"
#include <vector>
#include <memory>
#include <algorithm>
#include "decorators.h"
class Group : public Shape
{
protected:
    std::vector<std::shared_ptr<ShapeDecorator>> m_group;
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
        auto decoratedShape = std::make_shared<ShapeDecorator>(shape);
        m_group.push_back(decoratedShape);
    }

    void DeleteShape(std::shared_ptr<ShapeDecorator> shape)
    {
        m_group.erase(std::remove(m_group.begin(), m_group.end(), shape), m_group.end());
    }

    std::vector<std::shared_ptr<ShapeDecorator>> GetShapes() { return m_group; }

    bool IsEmpty() const { return m_group.empty(); }

    void Draw(sf::RenderWindow& window) override
    {
        for (const auto& shape : m_group)
            shape->Draw(window);
        if (m_isSelected)
            window.draw(m_frame);
    }

    void SetGroupColor(const sf::Color& color, const sf::Color& outlineColor, float outlineThickness)
    {
        for (auto& decoratedShape : m_group)
        {
            auto circle = std::dynamic_pointer_cast<CircleDecorator>(decoratedShape);
            if (circle)
            {
                circle->SetColor(color, outlineColor, outlineThickness);
            }
            auto rectangle = std::dynamic_pointer_cast<RectangleDecorator>(decoratedShape);
            if (rectangle)
            {
                rectangle->SetColor(color, outlineColor, outlineThickness);
            }
            auto triangle = std::dynamic_pointer_cast<TriangleDecorator>(decoratedShape);
            if (triangle)
            {
                triangle->SetColor(color, outlineColor, outlineThickness);
            }
        }
    }

    float GetPerimeter() const override { return 0; }
    float GetArea() const override { return 0; }
    std::string GetParams() const override { return ""; }

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

    void Select(bool select) override { m_isSelected = select; }
    bool IsSelected() const override { return m_isSelected; }
    bool IsGroup() const override { return true; }
};

