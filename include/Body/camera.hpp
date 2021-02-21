#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


// Camera body. Handle translations and zoom.
class Camera2D
{
    
    private:
        sf::View view;

        // Convert delta value to zoom
        float getZoomValue(float delta);
    
    public:
        
        // Default constructor
        Camera2D() {};
        
        // Camera2D constructor 
        Camera2D(int width, int height);
        
        
        // Activate window view
        void activate(sf::RenderWindow* window);
        
        // Update transformation
        void updateView(float offset, bool isFocused);
        void updateView(sf::Event& action, bool isFocused);

};
