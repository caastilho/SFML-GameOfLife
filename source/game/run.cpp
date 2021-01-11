#include <engine/canvas.hpp>
#include "game/board.hpp" 
#include "game/camera.hpp"


static Board board;
static Camera camera;

// Setup simulation environment
void Canvas::setup()
{
    
    // Setup cells environment
    board.set(1000, 1000, CANVAS_window);
    board.add("gosper_glider_gun", 500, 500);
    
    // Set camera initial values
    camera.set(500, 500);
    
}


// Run simulation environment
void Canvas::loop()
{
    
    // Clear screen content
    CANVAS_window->clear();
    
    // Update X and Y camera axis
    camera.updateXY(1.2, 1.2);
    
    // Get values
    float zoom = camera.zoom * 20;
    float x = camera.x;
    float y = camera.y;
    
    // Run simulation
    board.doGeneration();
    board.drawStates(x, y, CANVAS_width, CANVAS_height, zoom);

}


// Clean simulation environment
void Canvas::events(sf::Event& action)
{
    
}
