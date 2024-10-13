#include "ShapeGroup.h"

// Добавление фигуры в группу
void ShapeGroup::AddShape(std::shared_ptr<Shape> shape) {
    m_shapes.push_back(shape);
}

// Удаление фигуры из группы
void ShapeGroup::RemoveShape(std::shared_ptr<Shape> shape) {
    m_shapes.erase(std::remove(m_shapes.begin(), m_shapes.end(), shape), m_shapes.end());
}

// Отрисовка всех фигур в группе
void ShapeGroup::Draw(sf::RenderWindow& window) {
    for (auto& shape : m_shapes) {
        shape->Draw(window);  // Вызываем метод Draw каждой фигуры
    }
}

// Получение всех фигур в группе
std::vector<std::shared_ptr<Shape>> ShapeGroup::GetShapes() {
    return m_shapes;
}

// Очистка группы от всех фигур
void ShapeGroup::ClearShapes() {
    m_shapes.clear();
}

// Возвращает суммарную площадь всех фигур в группе
float ShapeGroup::GetArea() const {
    float totalArea = 0.0f;
    for (const auto& shape : m_shapes) {
        totalArea += shape->GetArea();
    }
    return totalArea;
}

// Возвращает суммарный периметр всех фигур в группе
float ShapeGroup::GetPerimeter() const {
    float totalPerimeter = 0.0f;
    for (const auto& shape : m_shapes) {
        totalPerimeter += shape->GetPerimeter();
    }
    return totalPerimeter;
}

// Проверяет, содержится ли точка внутри любой фигуры группы
bool ShapeGroup::Contains(const sf::Vector2f& point) const {
    for (const auto& shape : m_shapes) {
        if (shape->Contains(point)) {
            return true;  // Если точка содержится хотя бы в одной фигуре, возвращаем true
        }
    }
    return false;
}

// Возвращает объединенные границы всех фигур
sf::FloatRect ShapeGroup::GetBounds() const {
        return sf::FloatRect(); 
}

// Перемещение всех фигур на заданное смещение
void ShapeGroup::Move(const sf::Vector2f& delta) {
    for (auto& shape : m_shapes) {
        shape->Move(delta);  // Перемещаем каждую фигуру
    }
}

// Возвращает позицию первой фигуры в группе
sf::Vector2f ShapeGroup::GetPosition() const {
    if (!m_shapes.empty()) {
        return m_shapes[0]->GetPosition();
    }
    return sf::Vector2f(0.0f, 0.0f);  // Если фигур нет, возвращаем (0, 0)
}

// Устанавливает позицию первой фигуры в группе (группы как целого)
void ShapeGroup::SetPosition(const sf::Vector2f& position) {
    if (!m_shapes.empty()) {
        sf::Vector2f offset = position - m_shapes[0]->GetPosition();
        Move(offset);  // Передвигаем всю группу на разницу между новыми и старыми координатами
    }
}

// Устанавливает цвет заливки для всех фигур в группе
void ShapeGroup::SetFillColor(const sf::Color& color) {
    for (auto& shape : m_shapes) {
        shape->SetFillColor(color);
    }
}

// Устанавливает цвет окантовки для всех фигур в группе
void ShapeGroup::SetOutlineColor(const sf::Color& color) {
    for (auto& shape : m_shapes) {
        shape->SetOutlineColor(color);
    }
}

// Устанавливает толщину окантовки для всех фигур в группе
void ShapeGroup::SetOutlineThickness(float thickness) {
    for (auto& shape : m_shapes) {
        shape->SetOutlineThickness(thickness);
    }
}
