#ifndef SHAPEGROUP_H
#define SHAPEGROUP_H

#include <vector>
#include <memory>
#include <algorithm>
#include "Shape.h"

class ShapeGroup : public Shape {
private:
    std::vector<std::shared_ptr<Shape>> m_shapes;

public:
    void AddShape(std::shared_ptr<Shape> shape) {
        m_shapes.push_back(shape);
    }

    void RemoveShape(std::shared_ptr<Shape> shape) {
        m_shapes.erase(std::remove(m_shapes.begin(), m_shapes.end(), shape), m_shapes.end());
    }

    void Draw(sf::RenderWindow& window) override {
        for (auto& shape : m_shapes) {
            shape->Draw(window);
        }
    }

    std::vector<std::shared_ptr<Shape>> GetShapes() {
        return m_shapes;
    }

    void ClearShapes() {
        m_shapes.clear();
    }

    float GetArea() const override {
        float totalArea = 0.0f;
        for (const auto& shape : m_shapes) {
            totalArea += shape->GetArea();
        }
        return totalArea;
    }

    float GetPerimeter() const override {
        float totalPerimeter = 0.0f;
        for (const auto& shape : m_shapes) {
            totalPerimeter += shape->GetPerimeter();
        }
        return totalPerimeter;
    }

    bool Contains(const sf::Vector2f& point) const override {
        for (const auto& shape : m_shapes) {
            if (shape->Contains(point)) {
                return true;
            }
        }
        return false;
    }

    void Move(const sf::Vector2f& delta) override {
        for (auto& shape : m_shapes) {
            shape->Move(delta);
        }
    }

    sf::Vector2f GetPosition() const override {
        if (!m_shapes.empty()) {
            return m_shapes[0]->GetPosition();
        }
        return sf::Vector2f(0.0f, 0.0f);
    }

    void SetPosition(const sf::Vector2f& position) override {
        if (!m_shapes.empty()) {
            sf::Vector2f offset = position - m_shapes[0]->GetPosition();
            Move(offset);
        }
    }

    void SetFillColor(const sf::Color& color) override {
        for (auto& shape : m_shapes) {
            shape->SetFillColor(color);
        }
    }

    void SetOutlineColor(const sf::Color& color) override {
        for (auto& shape : m_shapes) {
            shape->SetOutlineColor(color);
        }
    }

    void SetOutlineThickness(float thickness) override {
        for (auto& shape : m_shapes) {
            shape->SetOutlineThickness(thickness);
        }
    }
};

#endif
