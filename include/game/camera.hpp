#pragma once
#include <SFML/Graphics.hpp>


// Camera class. Stores camera translation and zoom
struct Camera
{
    
    // Create Camera fields (translation and zoom)
    float x, y, zoom;
    
    // Construct camera environment
    Camera();
    Camera(float startX, float startY, float startZoom);
    void set(float startX, float startY, float startZoom);
    
    
    // Update values
    void updateXY(float deltaX, float deltaY);
    void updateZoom(float delta, float amount);
    
    // Constrain values
    void constrainX(float minimum, float maximum);
    void constrainY(float minimum, float maximum);
    void constrainZoom(float minimum, float maximum);
    
};
