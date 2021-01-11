#include "game/camera.hpp"


// Construct environment
Camera::Camera()
{
    x = 0;
    y = 0;
    zoom = 0;
}

Camera::Camera(float startX, float startY)
{
    x = startX;
    y = startY;
    zoom = 1;
}

void Camera::set(float startX, float startY)
{
    x = startX;
    y = startY;
    zoom = 1;
}


// Update X and Y position
void Camera::updateXY(float deltaX, float deltaY)
{
    
    int x_scaler = 0;
    int y_scaler = 0;
    
    // Y-AXIS TRANSLATIONS
    // Up key is being pressed
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) 
        y_scaler = -1;
    
    // Down key is being pressed
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        y_scaler = 1;
    
    
    // X-AXIS TRANSLATIONS
    // Right key is being pressed
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        x_scaler = -1;
    
    // Left key is being pressed
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        x_scaler = 1;
    
    // Update coordinates
    x += deltaX * x_scaler;
    y += deltaY * y_scaler;

}
