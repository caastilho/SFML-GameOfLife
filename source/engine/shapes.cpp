#include <engine/shapes.hpp>


// 'TriangleShape' methods
TriangleShape::TriangleShape(const sf::Vector2f point_0, const sf::Vector2f point_1, const sf::Vector2f point_2)
{
    
    points[0] = point_0;
    points[1] = point_1;
    points[2] = point_2;
    
    // Update shape points
    update();
    
}

std::size_t TriangleShape::getPointCount() const
{
    return 3;
}

sf::Vector2f TriangleShape::getPoint(std::size_t index) const
{
    return points[index];
}
