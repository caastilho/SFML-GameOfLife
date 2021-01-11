#pragma once
#include <SFML/Graphics.hpp>


// Camera class. Stores camera translation and zoom
struct Camera
{
    
    // Create Camera fields (translation and zoom)
    float x, y, zoom;
    
    // Construct camera environment
    Camera();
    Camera(float startX, float startY);
    void set(float startX, float startY);
    
    
    // Update values
    void updateXY(float deltaX, float deltaY);
    
    
};