#include <Scenes/simulation.hpp>

#include <Scripts/reader.hpp>
#include <vector>



// Setup scene environement
void SCENE_Simulation::setup(sf::RenderWindow* _window, bool& _isFocused)
{
    
    window = _window;
    isFocused = _isFocused;
    
    // Get window's sizes
    sf::Vector2u size = window->getSize();
    int width = size.x;
    int height = size.y;
    
    // Create camera object
    camera = Camera2D(width, height);
    
    // Create board object
    board = Board(200, 200, window);
    std::vector<std::vector<int>> a = getPattern("/home/alfa/Desktop/C++/GameOfLife/others/assets/patterns/gosper_glider_gun.cell");
    board.add(a, 10, 10);
    
}


// Run scene environment
void SCENE_Simulation::run()
{
    
    // Clear window buffer
    window->clear(sf::Color::Black);
    
    
    // Update camera values
    camera.updateView(2.5, isFocused);
    
    // Activate window view
    camera.activate(window);
    
    
    // Do generation with simulation is active
    if (isSimulationActive)
        board.doGeneration();
    
    // Draw board cells
    board.drawStates();
    
}


// Scene events handler
void SCENE_Simulation::events(sf::Event& action)
{
    
    // Update camera values
    camera.updateView(action);
    
    // Key pressed event type
    if (action.type == sf::Event::KeyPressed)
    {
        // Pause or play simulation
        if (action.key.code == sf::Keyboard::Space)
            isSimulationActive = !isSimulationActive;
    }
}
