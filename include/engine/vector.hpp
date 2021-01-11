#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <cmath>


// Return vector
sf::Vector2f hadamard(sf::Vector2f& v1, sf::Vector2f& v2);
sf::Vector2f getRandomVector(float minimum, float maximum);
sf::Vector2f setMagnitude(sf::Vector2f& source, float magnitude);
sf::Vector2f constrain(sf::Vector2f& source, float maximum);

// Get vector attributes
float dot(sf::Vector2f& v1, sf::Vector2f& v2);
float getDistance(sf::Vector2f& v1, sf::Vector2f& v2);
float getMagnitude(sf::Vector2f& source);
float getAngleBetween(sf::Vector2f& v1, sf::Vector2f& v2);
float getAngle(sf::Vector2f& source);
