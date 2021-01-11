#pragma once
#include <SFML/Graphics.hpp>


// Triangle shape. 'Shape' class child
class TriangleShape : public sf::Shape
{

private:
    
    // Declare points Vector2f array
    sf::Vector2f points[3];
    
public:
    
    // Construct 'TriangleShape' environment
    explicit TriangleShape(
        const sf::Vector2f point_0, 
        const sf::Vector2f point_1, 
        const sf::Vector2f point_2
    );
    
    // Override 'Shapes' methods
    std::size_t getPointCount() const;
    sf::Vector2f getPoint(std::size_t) const;
    
};
