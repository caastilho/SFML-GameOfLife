#include <engine/canvas.hpp>
#include "game/board.hpp" 
#include "game/camera.hpp"

// #include <cmath>


static Board board;
static int width = 1000;
static int height = 1000;

static Camera camera;
static float maxZoom = 0;
static float maxX = 0;
static float maxY = 0;


// Handle camera transformations
void handleCamera(int CANVAS_width, int CANVAS_height)
{
    // Update X and Y camera axis
    camera.updateXY(1.2, 1.2);

    // Constrain zoom
    camera.constrainZoom(maxZoom, 0.5);
    float zoom = camera.zoom * 100;

    // Constrain coordinates
    maxX = width - (CANVAS_width / zoom);
    maxY = height - (CANVAS_height / zoom);
    camera.constrainX(0, maxX);
    camera.constrainY(0, maxY);    
}


// Setup simulation environment
void Canvas::setup()
{
    
    // Setup cells environment
    board.set(width, height, CANVAS_window);
    board.add("gosper_glider_gun", width/2, height/2);
    
    // Set camera initial values
    camera.set(width/2, height/2);
    maxZoom = ((float)CANVAS_width / width) / 100.0;
    
}

// Run simulation environment
void Canvas::loop()
{
    
    // Clear screen content
    CANVAS_window->clear();
    
    // Update camera values
    handleCamera(CANVAS_width, CANVAS_height);
    
    // Get values
    float zoom = camera.zoom * 100;
    float x = camera.x;
    float y = camera.y;
    
    // Run simulation
    board.doGeneration();
    board.drawStates(x, y, CANVAS_width, CANVAS_height, zoom);

}

// Clean simulation environment
void Canvas::events(sf::Event& action)
{
    
    // Mouse wheel event (Zoom in or Zoom out)
    if (action.type == sf::Event::MouseWheelMoved)
    {
        float increment = 0.08 * camera.zoom;
        camera.updateZoom(action.mouseWheel.delta, increment);
    }
}
