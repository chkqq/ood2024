#include "ShapeLoader.h"

std::vector<std::shared_ptr<Shape>> ShapeLoader::loadFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for loading");
    }

    std::vector<std::shared_ptr<Shape>> shapes;
    std::string line;

    std::vector<std::unique_ptr<ShapeBuilder>> builders;
    builders.push_back(std::make_unique<CircleBuilder>());
    builders.push_back(std::make_unique<RectangleBuilder>());
    builders.push_back(std::make_unique<TriangleBuilder>());

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string type;
        iss >> type;

        if (type == "{") {
            auto group = std::make_shared<Group>();
            while (std::getline(file, line) && line != "}") {
                std::istringstream groupIss(line);
                std::string shapeType;
                groupIss >> shapeType;

                std::unique_ptr<ShapeBuilder> builder = createBuilder(shapeType);
                if (builder) {
                    builder->buildShape(line);
                    auto shape = builder->getResult();
                    if (shape) {
                        group->AddShape(shape);
                    }
                    if (!group->IsEmpty()) {
                        group->MakeFrame();
                    }
                }
            }
            shapes.push_back(group);
        }
        else {
            std::unique_ptr<ShapeBuilder> builder = createBuilder(type);
            if (builder) {
                builder->buildShape(line);
                auto shape = builder->getResult();
                if (shape) {
                    shapes.push_back(shape);
                }
            }
        }
    }

    file.close();
    return shapes;
}

std::unique_ptr<ShapeBuilder> ShapeLoader::createBuilder(const std::string& type)
{
    if (type == "Circle") {
        return std::make_unique<CircleBuilder>();
    }
    else if (type == "Rectangle") {
        return std::make_unique<RectangleBuilder>();
    }
    else if (type == "Triangle") {
        return std::make_unique<TriangleBuilder>();
    }
    return nullptr;
}
