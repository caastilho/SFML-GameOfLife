#include <Graphics/canvas.hpp>



// Construct canvas environment
Canvas::Canvas(int width, int height, const char* name)
{
    
    // Create window shape (width, height and buffer depth)
    sf::VideoMode shape(width, height);
    
    // Crete window style
    int style = sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize;
    
    // Construct window object
    window = new sf::RenderWindow(shape,  name, style);
    
}

// Run canvas environment
void Canvas::run()
{
    
    // Setup canvas scenes
    setupScenes();
    
    // Start canvas main loop
    while(window->isOpen())
    {
        eventsHandler();
        runScenes();
        
        // Change window's buffer
        window->display();
    }
    
}



// Setup graphical objects
void Canvas::setupObjects()
{
    
}



// Create graphical objects array
void Canvas::addShaders(std::string fragmented, std::string vertex)
{
}

void Canvas::addTexture(std::string path)
{
}

void Canvas::addFont(std::string path)
{
}




// Setup canvas scenes
void Canvas::setupScenes()
{
    
    // Setup "simulation" scene
    scene_0.setup(window, isFocused);
    
}

// Run canvas current scene
void Canvas::runScenes()
{
    
    // Run current scene
    switch(scene_index)
    {
        
        // Run "simulation" scene
        case 0:
            scene_0.run();
            break;
    }
    
}

// Canvas event handler
void Canvas::eventsHandler()
{
    
    // Iterate thru events
    while(window->pollEvent(action))
    {
        
        // "Close" window event
        if (action.type == sf::Event::Closed)
            window->close();
        
        // "FocusIn" window event
        if (action.type == sf::Event::GainedFocus)
            isFocused = true;
        
        // "FocusOut" window event
        if (action.type == sf::Event::LostFocus)
            isFocused = false;
        
        
        // Current scene event handler
        switch(scene_index)
        {
            
            // "simulation" scene events handler
            case 0:
                scene_0.events(action);
                break;
        }
    }
}
