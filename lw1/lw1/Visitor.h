#pragma once
#include <memory>

class Circle;
class Rectangle;
class Triangle;
class Group;
class Visitor
{
public:
    virtual void visit(Circle& circle) = 0;
    virtual void visit(Rectangle& rectangle) = 0;
    virtual void visit(Triangle& triangle) = 0;
    virtual void visit(Group& group) = 0;
    virtual ~Visitor() = default;
};