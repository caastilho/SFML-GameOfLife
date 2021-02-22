#pragma once
#include <SFML/Graphics.hpp>

#include <Body/board.hpp>
#include <Body/camera.hpp>
#include <Scripts/editor.hpp>

#include <UI/image.hpp>


// Scene simulation
class SCENE_Simulation
{
    
    private:
        
        // Canvas render window
        sf::RenderWindow* window;
        
        // Stores window focused state
        bool* isFocused;
        
        
        // Simulation states
        bool isSimulationActive = false;
        
        
        // GUI window view
        sf::View GUIview;
        
        // State displayer
        Image playing, paused;
        
        
        // Simulation camera
        Camera2D camera;
        
        // Game of life board
        Board board;
        
        // Game of life board editor
        Editor editor;
    
    
    public:
        
        // Default scene constructor
        SCENE_Simulation() {};

        
        // Setup scene environement
        void setup(sf::RenderWindow* _window, bool* _isFocused, std::vector<sf::Texture>& textures);
        
        // Run scene environment
        void run();
        
        // Scene events handler
        void events(sf::Event& action);
};
