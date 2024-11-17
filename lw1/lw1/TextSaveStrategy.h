#pragma once
#include "SaveStrategy.h"
#include <fstream>

class TextSaveStrategy : public SaveStrategy
{
public:
    void saveToFile(const std::string& filename, const std::vector<std::shared_ptr<Shape>>& shapes) override;
};
