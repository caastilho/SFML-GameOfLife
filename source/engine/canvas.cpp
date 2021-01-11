#include <SFML/Graphics.hpp>
#include "engine/canvas.hpp"


// Canvas constructor method. Create 'RenderWindow' object
Canvas::Canvas(int width, int height, const char* title) 
{
    
    // Create 'RenderWindow' object
    CANVAS_window = new sf::RenderWindow();
    
    // Set window attributes
    CANVAS_window->setPosition(sf::Vector2i(0, 0));
    
    sf::VideoMode shape(width, height);
    int style = sf::Style::Close | sf::Style::Titlebar;
    CANVAS_window->create(shape, title, style);
    
    // Set window size
    sf::Vector2u size = CANVAS_window->getSize(); 
    CANVAS_width  = size.x;
    CANVAS_height = size.y;
}


// Run canvas environment
void Canvas::run()
{
    
    // Setup simulation environment
    setup();
    
    // Main window loop
    while (CANVAS_window->isOpen())
    {
        handleEvents(CANVAS_event);
        loop();
        
        // Display window changes
        CANVAS_window->display();
        
    }
    
}

// Handle window events
void Canvas::handleEvents(sf::Event& action)
{
    
    while (CANVAS_window->pollEvent(action)) 
    {
        
        // Close window if event 'Closed' is detected
        if (action.type == sf::Event::Closed)
            exit();
        
        // Simulation event handler
        events(action);
        
    }
    
    
}

// Quit environment
void Canvas::exit()
{
    
    CANVAS_window->close();
}
