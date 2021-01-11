#include <engine/vector.hpp>


// Get random Vector2f between a range 
sf::Vector2f getRandomVector(float minimum, float maximum)
{
    
    // Get random coordinates
    float x = minimum + ((float)rand() / RAND_MAX) * (maximum - minimum);
    float y = minimum + ((float)rand() / RAND_MAX) * (maximum - minimum);
    
    // Return vector
    return sf::Vector2f(x, y);
    
}

// Get hadamard product (element-wise operation) between two vectors
sf::Vector2f hadamard(sf::Vector2f& v1, sf::Vector2f& v2)
{
    
    // Get the product between axis
    float x = v1.x * v2.x;
    float y = v1.y * v2.y;
    
    // Return new vector
    return sf::Vector2f(x, y);
    
}

// Set vector magnitude
sf::Vector2f setMagnitude(sf::Vector2f& source, float magnitude)
{
    
    // Get new vector values
    float current = getMagnitude(source);
    float x = source.x * magnitude / current;
    float y = source.y * magnitude / current;
    
    // Return vector
    return sf::Vector2f(x, y);
    
}

// Constrain vector values
sf::Vector2f constrain(sf::Vector2f& source, float maximum) 
{
    float x = std::min(source.x, maximum);
    float y = std::min(source.y, maximum);
    return sf::Vector2f(x, y);
}


// Get the dot product of a vector
float dot(sf::Vector2f& v1, sf::Vector2f& v2)
{
    return (v1.x * v2.x) + (v1.y * v2.y);
}

// Get distance between two vectors
float getDistance(sf::Vector2f& v1, sf::Vector2f& v2)
{
    return sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2));
}

// Get vector magnitude
float getMagnitude(sf::Vector2f& source)
{
    return sqrt(pow(source.x, 2) + pow(source.y, 2));
}

// Get angle between two vectors
float getAngleBetween(sf::Vector2f& v1, sf::Vector2f& v2)
{
    float angle = (dot(v1, v2)) / (getMagnitude(v1) * getMagnitude(v2));
    return angle;
}

// Get angle from vector
float getAngle(sf::Vector2f& source)
{
    return atan2(source.y, source.x) * 180/3.14159265;
}
