#ifndef SHAPEGROUP_H
#define SHAPEGROUP_H

#include <vector>
#include <memory>
#include "Shape.h"

class ShapeGroup : public Shape {  // ��������� �� Shape
private:
    std::vector<std::shared_ptr<Shape>> m_shapes;  // ������ ��� �������� ����� � ������
public:
    // ���������� � �������� �����
    void AddShape(std::shared_ptr<Shape> shape);
    void RemoveShape(std::shared_ptr<Shape> shape);  // �������� ������ �� ������

    // ��������� ���������
    void Draw(sf::RenderWindow& window) override;

    // ��������� ���� �����
    std::vector<std::shared_ptr<Shape>> GetShapes();

    // ������� ���� �����
    void ClearShapes();

    // �������������� ������ �� Shape
    float GetArea() const override;       // ���������� ��������� ������� ���� �����
    float GetPerimeter() const override;  // ���������� ��������� �������� ���� �����
    bool Contains(const sf::Vector2f& point) const override;  // ���������, ���������� �� ����� � ����� ������
    sf::FloatRect GetBounds() const override;  // ���������� ������������ ������� ���� �����
    void Move(const sf::Vector2f& delta) override;  // ���������� ��� ������ � ������

    // ������� ������ ������ (��� ������ ��� ������)
    sf::Vector2f GetPosition() const override;
    void SetPosition(const sf::Vector2f& position) override;

    // ��������� ����� � ��������� ��� ���� ����� � ������
    void SetFillColor(const sf::Color& color) override;
    void SetOutlineColor(const sf::Color& color) override;
    void SetOutlineThickness(float thickness) override;
};

#endif  // SHAPEGROUP_H
