#include "CircleDecorator.h"

CircleDecorator::CircleDecorator(std::shared_ptr<Circle> shape)
    : m_shape(shape)
{
}

double CircleDecorator::GetPerimeter()
{
    return 2 * M_PI * m_shape->GetCircleShape().getRadius();
}

double CircleDecorator::GetArea()
{
    return M_PI * std::pow(m_shape->GetCircleShape().getRadius(), 2);
}

void CircleDecorator::PrintData(std::ofstream& output)
{
    output << "P = " << GetPerimeter() << "; S = " << GetArea() << std::endl;
}