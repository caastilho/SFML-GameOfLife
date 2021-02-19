#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include <Scenes/simulation.hpp>


// Renderer environment (Canvas)
class Canvas
{
    
    private:
        
        // Canvas render window object
        sf::RenderWindow* window;
        
        // Canvas focus state
        bool isFocused = true;
        
        
        // Canvas scenes
        int scene_index = 0; 
        SCENE_Simulation scene_0;
        
        
        // Graphic objects array
        std::vector<sf::Shader> shaders;
        std::vector<sf::Texture> textures;
        std::vector<sf::Font> fonts;
        
        // Add graphical objects array
        void addShaders(std::string fragmented, std::string vertex);
        void addTexture(std::string path);
        void addFont(std::string path);
        
        // Setup graphical objects
        void setupObjects();
        
        
        // Setup canvas scenes
        void setupScenes();
        
        // Run canvas current scene
        void runScenes();
        
        // Canvas event handler
        sf::Event action;
        void eventsHandler();
        
        
    public:
        
        // Construct canvas environment
        Canvas(int width, int height, const char* name);
        
        // Run canvas environment
        void run();
        
};
