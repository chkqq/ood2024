#include "ShapeGroup.h"

// ���������� ������ � ������
void ShapeGroup::AddShape(std::shared_ptr<Shape> shape) {
    m_shapes.push_back(shape);
}

// �������� ������ �� ������
void ShapeGroup::RemoveShape(std::shared_ptr<Shape> shape) {
    m_shapes.erase(std::remove(m_shapes.begin(), m_shapes.end(), shape), m_shapes.end());
}

// ��������� ���� ����� � ������
void ShapeGroup::Draw(sf::RenderWindow& window) {
    for (auto& shape : m_shapes) {
        shape->Draw(window);  // �������� ����� Draw ������ ������
    }
}

// ��������� ���� ����� � ������
std::vector<std::shared_ptr<Shape>> ShapeGroup::GetShapes() {
    return m_shapes;
}

// ������� ������ �� ���� �����
void ShapeGroup::ClearShapes() {
    m_shapes.clear();
}

// ���������� ��������� ������� ���� ����� � ������
float ShapeGroup::GetArea() const {
    float totalArea = 0.0f;
    for (const auto& shape : m_shapes) {
        totalArea += shape->GetArea();
    }
    return totalArea;
}

// ���������� ��������� �������� ���� ����� � ������
float ShapeGroup::GetPerimeter() const {
    float totalPerimeter = 0.0f;
    for (const auto& shape : m_shapes) {
        totalPerimeter += shape->GetPerimeter();
    }
    return totalPerimeter;
}

// ���������, ���������� �� ����� ������ ����� ������ ������
bool ShapeGroup::Contains(const sf::Vector2f& point) const {
    for (const auto& shape : m_shapes) {
        if (shape->Contains(point)) {
            return true;  // ���� ����� ���������� ���� �� � ����� ������, ���������� true
        }
    }
    return false;
}

// ���������� ������������ ������� ���� �����
sf::FloatRect ShapeGroup::GetBounds() const {
        return sf::FloatRect(); 
}

// ����������� ���� ����� �� �������� ��������
void ShapeGroup::Move(const sf::Vector2f& delta) {
    for (auto& shape : m_shapes) {
        shape->Move(delta);  // ���������� ������ ������
    }
}

// ���������� ������� ������ ������ � ������
sf::Vector2f ShapeGroup::GetPosition() const {
    if (!m_shapes.empty()) {
        return m_shapes[0]->GetPosition();
    }
    return sf::Vector2f(0.0f, 0.0f);  // ���� ����� ���, ���������� (0, 0)
}

// ������������� ������� ������ ������ � ������ (������ ��� ������)
void ShapeGroup::SetPosition(const sf::Vector2f& position) {
    if (!m_shapes.empty()) {
        sf::Vector2f offset = position - m_shapes[0]->GetPosition();
        Move(offset);  // ����������� ��� ������ �� ������� ����� ������ � ������� ������������
    }
}

// ������������� ���� ������� ��� ���� ����� � ������
void ShapeGroup::SetFillColor(const sf::Color& color) {
    for (auto& shape : m_shapes) {
        shape->SetFillColor(color);
    }
}

// ������������� ���� ��������� ��� ���� ����� � ������
void ShapeGroup::SetOutlineColor(const sf::Color& color) {
    for (auto& shape : m_shapes) {
        shape->SetOutlineColor(color);
    }
}

// ������������� ������� ��������� ��� ���� ����� � ������
void ShapeGroup::SetOutlineThickness(float thickness) {
    for (auto& shape : m_shapes) {
        shape->SetOutlineThickness(thickness);
    }
}
