#include <Scenes/simulation.hpp>


// Setup scene environement
void SCENE_Simulation::setup(sf::RenderWindow* _window, bool& _isFocused)
{
    
    window = _window;
    isFocused = _isFocused;
    
    
    // Create camera object
    sf::Vector2u size = window->getSize();
    camera = Camera2D(size.x, size.y);
    
    // Create board object
    board = Board(200, 200, window);
    
    // Create board editor object
    editor = Editor(&board, window);
    
}


// Run scene environment
void SCENE_Simulation::run()
{
    
    // Clear window buffer
    window->clear(sf::Color::Black);
    
    
    // Update camera values
    camera.updateView(2.5, isFocused);
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
    
    // Edit simulation if it is paused
    if (!isSimulationActive)
        editor.edit(action);
    
    // Key pressed event type
    if (action.type == sf::Event::KeyPressed)
    {
        
        // Pause or play simulation
        if (action.key.code == sf::Keyboard::Space)
            isSimulationActive = !isSimulationActive;
            
    }
}
