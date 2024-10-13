#ifndef SHAPEGROUP_H
#define SHAPEGROUP_H

#include <vector>
#include <memory>
#include "Shape.h"

class ShapeGroup : public Shape {  // Наследуем от Shape
private:
    std::vector<std::shared_ptr<Shape>> m_shapes;  // Вектор для хранения фигур в группе
public:
    // Добавление и удаление фигур
    void AddShape(std::shared_ptr<Shape> shape);
    void RemoveShape(std::shared_ptr<Shape> shape);  // Удаление фигуры из группы

    // Групповая отрисовка
    void Draw(sf::RenderWindow& window) override;

    // Получение всех фигур
    std::vector<std::shared_ptr<Shape>> GetShapes();

    // Очистка всех фигур
    void ClearShapes();

    // Переопределяем методы из Shape
    float GetArea() const override;       // Возвращает суммарную площадь всех фигур
    float GetPerimeter() const override;  // Возвращает суммарный периметр всех фигур
    bool Contains(const sf::Vector2f& point) const override;  // Проверяет, содержится ли точка в любой фигуре
    sf::FloatRect GetBounds() const override;  // Возвращает объединенные границы всех фигур
    void Move(const sf::Vector2f& delta) override;  // Перемещает все фигуры в группе

    // Позиция первой фигуры (или группы как целого)
    sf::Vector2f GetPosition() const override;
    void SetPosition(const sf::Vector2f& position) override;

    // Установка цвета и окантовки для всех фигур в группе
    void SetFillColor(const sf::Color& color) override;
    void SetOutlineColor(const sf::Color& color) override;
    void SetOutlineThickness(float thickness) override;
};

#endif  // SHAPEGROUP_H
