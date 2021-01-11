#pragma once
#include <SFML/Graphics.hpp>


// Simulation environment (Canvas)
class Canvas
{
    
    sf::RenderWindow*
    CANVAS_window;
    
    int 
    CANVAS_width, 
    CANVAS_height;
    
    // Handle window events
    void HandleEvents(sf::Event& action);
    
    // Clean environment
    void Exit();
    
public:
    
    // Canvas constructor
    Canvas(int width, int height, const char* title);
    
    // Run canvas
    void Run();
    
    // Simulation methods
    void Setup();
    void Loop();
    void Clean();
    
};
