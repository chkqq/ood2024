#include "commands.hpp"
#include <sstream>
#include <iostream>
#include "shapeCreator.hpp"

namespace commands 
{

    bool HandleAddShape(std::istringstream& iss, shapes::Picture& picture)
    {
        std::string id, shapeType, color;
        iss >> id >> color >> shapeType;

        if (picture.GetShapeByID(id) != nullptr) 
        {
            std::cout << "Shape with id '" << id << "' already exists. Use ChangeShape to modify the existing shape." << std::endl;
            return false;
        }

        auto shape = CreateShape(shapeType, id, iss, color);
        if (shape)
        {
            picture.AddShape(shape);
            return true;
        }
        else 
        {
            std::cout << "Unknown shape type: " << shapeType << std::endl;
            return false;
        }
    }

    bool HandleChangeShape(std::istringstream& iss, shapes::Picture& picture)
    {
        std::string id, shapeType, color;
        iss >> id >> color >> shapeType;

        auto oldShape = picture.GetShapeByID(id);
        if (!oldShape)
        {
            std::cout << "Shape with id '" << id << "' not found!" << std::endl;
            return false;
        }

        auto newShape = CreateShape(shapeType, id, iss, color);
        if (newShape)
        {
            picture.ChangeShape(id, newShape);
            return true;
        }
        else
        {
            std::cout << "Unknown shape type: " << shapeType << std::endl;
            return false;
        }
    }
    
    void Menu()
    {
        std::cout << "Available commands:\n";
        std::cout << "  AddShape <id> <color> <shapeType> [<params>]  - Add a new shape (circle, rectangle, triangle, line, text).\n";
        std::cout << "  ChangeShape <id> <color> <shapeType> [<params>] - Modify an existing shape.\n";
        std::cout << "  MovePicture <dx> <dy> - Move the entire picture by dx, dy.\n";
        std::cout << "  DrawPicture - Generate an SVG file of the picture.\n";
        std::cout << "  MoveShape <id> <dx> <dy> - Move a specific shape by id.\n";
        std::cout << "  DeleteShape <id> - Delete a shape by id.\n";
        std::cout << "  List - List all shapes in the picture.\n";
        std::cout << "  Exit - Exit the program.\n";
    }

    bool ExecuteCommand(const std::string& command, shapes::Picture& picture) 
    {
        std::istringstream iss(command);
        std::string cmd;
        iss >> cmd;
        if (cmd == "Menu")
        {
            Menu();
            return true;
        } 
        else if (cmd == "AddShape") 
        {
            return HandleAddShape(iss, picture);
        }
        else if (cmd == "ChangeShape") 
        {
            return HandleChangeShape(iss, picture);
        }
        else if (cmd == "MovePicture")
        {
            double dx, dy;
            iss >> dx >> dy;
            picture.Move(dx, dy);
            return true;
        }
        else if (cmd == "DrawPicture")
        {
            gfx::SVGCanvas canvas("output.svg");
            picture.Draw(canvas);
            return true;
        }
        else if (cmd == "DrawShape")
        {
            std::string id;
            iss >> id;

            auto shape = picture.GetShapeByID(id);
            if (shape)
            {
                gfx::SVGCanvas canvas("shape_" + id + ".svg");
                shape->Draw(canvas); 
                return true;
            }
            else
            {
                std::cout << "Shape with id " << id << " not found." << std::endl;
                return false;
            }
        }
        else if (cmd == "MoveShape")
        {
            std::string id;
            double dx, dy;
            iss >> id >> dx >> dy;

            auto shape = picture.GetShapeByID(id);
            if (shape)
            {
                shape->Move(dx, dy);
                return true;
            }
            else 
            {
                std::cout << "Shape with id " << id << " not found." << std::endl;
                return false;
            }
        }
        else if (cmd == "DeleteShape") 
        {
            std::string id;
            iss >> id;

            if (picture.DeleteShape(id)) 
            {
                std::cout << "Shape with id " << id << " deleted successfully." << std::endl;
                return true;
            }
            else 
            {
                std::cout << "Shape with id " << id << " not found." << std::endl;
                return false;
            }
        }
        else if (cmd == "DrawShape")
        {
            std::string id;
            iss >> id;

            auto shape = picture.GetShapeByID(id);
            if (shape)
            {
                gfx::SVGCanvas canvas("output.svg");
                shape->Draw(canvas);
                return true;
            }
            else
            {
                std::cout << "Shape with id " << id << " not found." << std::endl;
                return false;
            }
        }
        else if (cmd == "List")
        {
            picture.ListShapes();
            return true;
        }

        return false;
    }
}
