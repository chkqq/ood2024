#include "picture.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "line.hpp"
#include "text.hpp"
#include <iostream>
#include <algorithm>

namespace shapes 
{
    void Picture::AddShape(std::shared_ptr<Shape> shape)
    {
        if (shapeNames.count(shape->GetID()) > 0)
        {
            std::cout << "Shape with id '" << shape->GetID() << "' already exists!" << std::endl;
            return;
        }
        shapes.push_back(shape);
        shapeNames.insert(shape->GetID());
    }

    void Picture::ChangeShape(const std::string& id, std::shared_ptr<Shape> newShape)
    {
        auto it = std::find_if(shapes.begin(), shapes.end(),
            [&id](const std::shared_ptr<Shape>& shape) { return shape->GetID() == id; });

        if (it != shapes.end()) 
        {
            *it = newShape;
            shapeNames.erase(id);
            shapeNames.insert(newShape->GetID());
        }
        else 
        {
            std::cout << "Shape with id '" << id << "' not found!" << std::endl;
        }
    }

    void Picture::Draw(gfx::ICanvas& canvas)
    {
        for (auto& shape : shapes)
        {
            shape->Draw(canvas);
        }
    }

    void Picture::Move(double dx, double dy)
    {
        for (auto& shape : shapes) 
        {
            shape->Move(dx, dy);
        }
    }

    bool Picture::DeleteShape(const std::string& id)
    {
        auto it = std::remove_if(shapes.begin(), shapes.end(),
            [&id](const std::shared_ptr<Shape>& shape) { return shape->GetID() == id; });
        if (it != shapes.end())
        {
            shapeNames.erase(id);
            shapes.erase(it, shapes.end());
            return true;
        }
        return false;
    }

    std::shared_ptr<Shape> Picture::GetShapeByID(const std::string& id) 
    {
        for (const auto& shape : shapes) 
        {
            if (shape->GetID() == id) 
            {
                return shape;
            }
        }
        return nullptr;
    }

    void Picture::ListShapes() 
    {
        int index = 1;
        for (const auto& shape : shapes) 
        {
            std::cout << index << " " << shape->GetType() << " " << shape->GetID() << " "
                << shape->GetColor().value << " " << shape->GetParameters() << std::endl;
            index++;
        }
    }
}
