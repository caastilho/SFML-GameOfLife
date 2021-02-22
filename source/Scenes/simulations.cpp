#include <Scenes/simulation.hpp>


// Setup scene environement
void SCENE_Simulation::setup(sf::RenderWindow* _window, bool* _isFocused, std::vector<sf::Texture>& textures)
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
    
    
    // Setup GUI view size 
    GUIview.setSize(size.x, size.y);
    GUIview.setCenter(sf::Vector2f(size.x / 2.f, size.y / 2.f));
    
    // Create states displayer (Paused or Playisn)
    paused = Image(textures[0], 120, 85);
    playing = Image(textures[1], 128, 85);
    
}


// Run scene environment
void SCENE_Simulation::run()
{
    
    // Clear window buffer
    window->clear(sf::Color::Black);
    
    
    
    // Update camera values
    camera.updateView(2.5, *isFocused);
    camera.activate(window);

    
    // Do generation with simulation is active
    if (isSimulationActive)
        board.doGeneration();
    
    // Display board on buffer
    board.display();
    
    
    // Draw state displayer
    window->setView(GUIview);
    if (isSimulationActive)
    {
        playing.setPosition(10, 1080 - 95);
        playing.display(window);
    }
    
    else
    {
        paused.setPosition(18, 1080 - 100);
        paused.display(window);
    }
    
    
    // Reset window view
    camera.activate(window);
    
}


// Scene events handler
void SCENE_Simulation::events(sf::Event& action)
{
    
    // Update camera values
    camera.updateView(action, *isFocused);
    
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
