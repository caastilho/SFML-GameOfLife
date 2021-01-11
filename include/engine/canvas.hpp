#pragma once
#include <SFML/Graphics.hpp>


// Simulation environment (Canvas)
class Canvas
{
    
    private:

        // SFML Render window
        sf::RenderWindow* 
        CANVAS_window;
        
        // SFML Window dimensions
        int 
        CANVAS_width, 
        CANVAS_height;
        
        // SFML Window events
        sf::Event CANVAS_event;
        void handleEvents(sf::Event& action);
        
        // Clear canvas environment
        void exit();
        
        // Run SFML environment
        void events(sf::Event& action);
        void setup();
        void loop();
    
    public:
        
        // Construct canvas environment
        Canvas(int width, int height, const char* title);
        
        // Master function. Start canvas environment
        void run();
    
};
