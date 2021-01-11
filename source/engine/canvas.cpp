#include <SFML/Graphics.hpp>
#include "engine/canvas.hpp"


// Canvas constructor method. Create 'RenderWindow' object
Canvas::Canvas(int width, int height, const char* title) 
{
    
    CANVAS_width = width;
    CANVAS_height = height;
    
    // Create 'RenderWindow' requirements
    sf::VideoMode shape(width, height);
    int style = sf::Style::Close | sf::Style::Resize;

    // Create 'RenderWindow' object
    CANVAS_window = new sf::RenderWindow(shape, title, style);
    
}


// Run canvas environment
void Canvas::Run()
{
    
    sf::Event action;
    
    // Setup simulation environment
    Setup();
    
    // Main window loop
    while (CANVAS_window->isOpen())
    {
        HandleEvents(action);
        Loop();
        
        // Display window changes
        CANVAS_window->display();
        
    }
    
}


// Handle window events
void Canvas::HandleEvents(sf::Event& action)
{
    
    while (CANVAS_window->pollEvent(action)) 
    {
        switch (action.type) 
        {
            case sf::Event::Closed: // Quit environment
                Exit();
                break;
                
            case sf::Event::Resized: // Resize window
                break;
                
        }
        
        
    }
    
    
}

// Quit environment
void Canvas::Exit()
{
    
    CANVAS_window->close();
    Clean();
    
}
