#include <engine/canvas.hpp>
#include "game/board.hpp" 
#include <cmath>

static Board board;
static int scaler = 20;

// Setup simulation environment
void Canvas::Setup()
{
    
    // Get board dimensions
    int width = ceil(CANVAS_width / scaler);
    int height = ceil(CANVAS_height / scaler);
    
    // Setup cells environment
    board.setValues(width, height, scaler, CANVAS_window);
    board.add("gosper_glider_gun", 10, 10);
    
}


// Run simulation environment
void Canvas::Loop()
{
    
    // Clear screen content
    CANVAS_window->clear();
    
    // Run simulation
    board.run();
}


// Clean simulation environment
void Canvas::Clean()
{
    
}

