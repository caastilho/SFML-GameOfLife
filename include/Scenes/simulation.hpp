#pragma once
#include <SFML/Graphics.hpp>
#include <Body/board.hpp>
#include <Body/camera.hpp>


// Scene simulation
class SCENE_Simulation
{
    
    private:
        
        // Canvas render window
        sf::RenderWindow* window;
        
        // Stores window focused state
        bool isFocused;
        
        
        // Simulation state
        bool isSimulationActive = false;
        
        // Game of life board
        Board board;
        
        // Simulation camera
        Camera2D camera;
    
    
    public:
        
        // Default scene constructor
        SCENE_Simulation() {};

        
        // Setup scene environement
        void setup(sf::RenderWindow* _window, bool& _isFocused);
        
        // Run scene environment
        void run();
        
        // Scene events handler
        void events(sf::Event& action);
};
