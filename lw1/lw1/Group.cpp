#include "Group.h"
#include <algorithm>
#include <sstream>

void Group::MakeFrame()
{
    m_frame.setPosition(GetPosition());
    m_frame.setSize(sf::Vector2f(GetRightDownCorner().x - GetPosition().x, GetRightDownCorner().y - GetPosition().y));
    m_frame.setFillColor(sf::Color::Transparent);
    m_frame.setOutlineThickness(2);
    m_frame.setOutlineColor(sf::Color::Magenta);
}

void Group::AddShape(std::shared_ptr<Shape> shape)
{
    m_group.push_back(shape);
}

void Group::DeleteShape(std::shared_ptr<Shape> shape)
{
    m_group.erase(std::remove(m_group.begin(), m_group.end(), shape), m_group.end());
}

std::shared_ptr<Shape> Group::clone() const
{
    auto newGroup = std::make_shared<Group>();

    for (const auto& shape : m_group) {
        newGroup->AddShape(shape->clone());
    }
    return newGroup;
}

std::vector<std::shared_ptr<Shape>> Group::GetShapes() { return m_group; }

bool Group::IsEmpty() const { return m_group.empty(); }

void Group::Draw(sf::RenderWindow& window)
{
    for (const auto& shape : m_group)
        shape->Draw(window);
    if (m_isSelected)
        window.draw(m_frame);
}

std::string Group::serialize() const
{
    std::ostringstream oss;
    oss << "{\n";
    for (const auto& shape : m_group) {
        oss << shape->serialize() << "\n";
    }
    oss << "}\n";
    return oss.str();
}

bool Group::Contains(const sf::Vector2f& point) const
{
    for (const auto& shape : m_group)
        if (shape->Contains(point))
            return true;
    return false;
}

sf::Vector2f Group::GetPosition() const
{
    if (!m_group.empty())
    {
        float minX = m_group[0]->GetPosition().x;
        float minY = m_group[0]->GetPosition().y;
        for (const auto& shape : m_group)
        {
            minX = std::min(minX, shape->GetPosition().x);
            minY = std::min(minY, shape->GetPosition().y);
        }
        return sf::Vector2f(minX, minY);
    }
    return sf::Vector2f(0, 0);
}

void Group::setPosition(const sf::Vector2f& position)
{
    if (m_group.empty())
        return;

    sf::Vector2f currentPosition = GetPosition();
    sf::Vector2f offset = position - currentPosition;

    for (auto& shape : m_group)
    {
        shape->Move(offset);
    }

    MakeFrame();
}

sf::Vector2f Group::GetRightDownCorner() const
{
    if (!m_group.empty())
    {
        float maxX = m_group[0]->GetRightDownCorner().x;
        float maxY = m_group[0]->GetRightDownCorner().y;
        for (const auto& shape : m_group)
        {
            maxX = std::max(maxX, shape->GetRightDownCorner().x);
            maxY = std::max(maxY, shape->GetRightDownCorner().y);
        }
        return sf::Vector2f(maxX, maxY);
    }
    return sf::Vector2f(0, 0);
}

void Group::Move(const sf::Vector2f& offset)
{
    for (auto& shape : m_group)
        shape->Move(offset);
    m_frame.move(offset);
}

void Group::accept(Visitor& visitor)
{
    visitor.visit(*this);
}

void Group::Select(bool select) { m_isSelected = select; }

bool Group::IsSelected() const { return m_isSelected; }

bool Group::IsGroup() const { return true; }
