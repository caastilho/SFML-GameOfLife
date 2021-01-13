#include <engine/canvas.hpp>

#include <string>
#include <limits.h>
#include <unistd.h>

#include "game/board.hpp" 
#include "game/camera.hpp"


static Board board;
static int width = 1000;
static int height = 1000;

static Camera camera;
static float maxZoom = 0;

static sf::Font retroFont;
static sf::Text paused;
static bool running = false;


// Handle camera transformations
void handleCamera(int CANVAS_width, int CANVAS_height)
{

    // Constrain zoom
    camera.constrainZoom(maxZoom, 0.5);
    float zoom = camera.zoom * 100;

    // Update X and Y camera axis
    camera.updateXY(6 / zoom, 6 / zoom);
    
    // Constrain coordinates
    int maxX = width - (CANVAS_width / zoom);
    int maxY = height - (CANVAS_height / zoom);
    camera.constrainX(0, maxX);
    camera.constrainY(0, maxY);    
}


// Setup Writer fonts
void setupPaused(int width, int height)
{
    
    // Get 'Retro font path'
    char result[PATH_MAX];
    size_t count = readlink("/proc/self/exe", result, PATH_MAX);
    std::string full_path = std::string(result, (count > 0) ? count : 0);
    std::string path = full_path.substr(0, full_path.size() - 7) + "assets/retro.ttf";
    
    // Create Retro font
    retroFont.loadFromFile(path);
    
    // Create text object
    paused.setString("Paused");
    paused.setFont(retroFont);
    paused.setCharacterSize(50);
    paused.setPosition(10, height - 100);
    paused.setFillColor(sf::Color(255, 255, 255));
    
}



// Setup simulation environment
void Canvas::setup()
{
    
    // Setup cells environment
    board.set(width, height, CANVAS_window);
    board.add("gosper_glider_gun", width/2, height/2);
    
    // Set camera initial values
    camera.set(width/2, height/2, 0.3);
    maxZoom = ((float)CANVAS_width / width) / 100.0;
    
    // Setup text 'Paused' environment
    setupPaused(CANVAS_width, CANVAS_height);
    
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
    if (running)
    {
        board.doGeneration();
    }
    
    else
    {
        CANVAS_window->draw(paused);
    }
    
    // Draw simulation
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
    
    // Pause or Play simulation
    if (action.type == sf::Event::KeyPressed)
    {
        if (action.key.code == sf::Keyboard::Space)
            running = !running;
    }
    
}
