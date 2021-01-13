#include "game/camera.hpp"


// Construct environment
Camera::Camera()
{
    x = 0;
    y = 0;
    zoom = 0;
}

Camera::Camera(float startX, float startY, float startZoom)
{
    x = startX;
    y = startY;
    zoom = startZoom;
}

void Camera::set(float startX, float startY, float startZoom)
{
    x = startX;
    y = startY;
    zoom = startZoom;
}


// Update X and Y position
void Camera::updateXY(float deltaX, float deltaY)
{
    
    int x_scaler = 0;
    int y_scaler = 0;
    
    // Y-AXIS TRANSLATIONS
    // Up key is being pressed
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) 
        y_scaler = -1;
    
    // Down key is being pressed
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        y_scaler = 1;
    
    
    // X-AXIS TRANSLATIONS
    // Left key is being pressed
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        x_scaler = -1;
    
    // Right key is being pressed
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        x_scaler = 1;
    
    // Update coordinates
    x += deltaX * x_scaler;
    y += deltaY * y_scaler;

}

// Update camera zoom
void Camera::updateZoom(float delta, float amount)
{
    zoom += delta * amount;
}


// Constrain X value
void Camera::constrainX(float minimum, float maximum)
{
    x = std::min(maximum, std::max(minimum, x));
}

// Constrain Y value 
void Camera::constrainY(float minimum, float maximum)
{
    y = std::min(maximum, std::max(minimum, y));
}

// Constrain zoom
void Camera::constrainZoom(float minimum, float maximum)
{
    zoom = std::min(maximum, std::max(minimum, zoom));
}

