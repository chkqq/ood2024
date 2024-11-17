#include "RectangleDecorator.h"

RectangleDecorator::RectangleDecorator(std::shared_ptr<Rectangle> shape)
    : m_shape(shape)
{
}

double RectangleDecorator::GetPerimeter()
{
    float side = m_shape->GetRectangleShape().getSize().x;
    return 4 * side;
}

double RectangleDecorator::GetArea()
{
    float side = m_shape->GetRectangleShape().getSize().x;
    return side * side;
}

void RectangleDecorator::PrintData(std::ofstream& output)
{
    output << "P = " << GetPerimeter() << "; S = " << GetArea() << std::endl;
}

