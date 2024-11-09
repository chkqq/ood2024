#include "ShapeBuilder.h"
#include "Group.h"
#include <sstream>
#include <stdexcept>
#include <memory>
#include <vector>
#include "CircleBuilder.h"
#include "RectangleBuilder.h"
#include "TriangleBuilder.h"

class GroupBuilder : public ShapeBuilder {
private:
    std::shared_ptr<Group> group;
    std::vector<std::unique_ptr<ShapeBuilder>>& builders;

public:
    GroupBuilder(std::vector<std::unique_ptr<ShapeBuilder>>& buildersList)
        : builders(buildersList) {}

    void buildShape(const std::string& data) override {
        std::istringstream iss(data);
        std::string type;
        size_t shapeCount;

        // Проверка, что данные соответствуют формату для группы
        if (!(iss >> type >> shapeCount)) {
            throw std::runtime_error("Invalid data format for Group");
        }

        if (type == "Group") {
            group = std::make_shared<Group>();
            std::string shapeData;

            // Обработка каждой фигуры в группе
            for (size_t i = 0; i < shapeCount; ++i) {
                if (!std::getline(iss, shapeData, ';')) {
                    throw std::runtime_error("Insufficient shape data in group");
                }

                bool shapeAdded = false;
                for (auto& builder : builders) {
                    // Попытка построить фигуру из строки данных
                    try {
                        builder->buildShape(shapeData);
                        auto shape = builder->getResult();
                        if (shape) {
                            group->AddShape(shape);
                            shapeAdded = true;
                            break;
                        }
                    }
                    catch (const std::exception& e) {
                        // Если данные не соответствуют ожидаемому формату для билдера, пропустить
                    }
                }

                if (!shapeAdded) {
                    throw std::runtime_error("Failed to add shape to group: Invalid shape data");
                }
            }
        }
        else {
            throw std::runtime_error("Expected 'Group' type in data but got another type");
        }
    }

    std::shared_ptr<Shape> getResult() override {
        return group;
    }
};
