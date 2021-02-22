#pragma once
#include <SFML/Graphics.hpp>
#include <string>


class Image
{
    private:
        
        // State Displayer sprite
        sf::Sprite sprite;
        
        
    public:
        
        // Default image constructor
        Image() {};
        
        // Construct image sprite
        Image(sf::Texture& path, int width, int height);
        
        // Set image X, Y positions
        void setPosition(float x, float y);
        
        
        // Display image
        void display(sf::RenderWindow* window);
    
};
