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
    
    setupObjects();
    
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



// Get "assets" directory path
std::string Canvas::getAssetsPath()
{
    // Get current working directory
    char result[PATH_MAX];
    size_t count = readlink("/proc/self/exe", result, PATH_MAX);
    std::string full_path = std::string(result, (count > 0) ? count : 0);
    
    // Get "assets" path
    std::string path = full_path.substr(0, full_path.size() - 7) + "assets/";
    
    // Return path
    return path;
}

// Setup graphical objects
void Canvas::setupObjects()
{
    
    // Get assets path
    std::string assets = getAssetsPath();
    
    
    // Load textures objects
    addTexture(assets + "pause_image.png");
    addTexture(assets + "play_image.png");
    
}



// Create graphical objects array
void Canvas::addShaders(std::string fragmented, std::string vertex)
{
}

void Canvas::addTexture(std::string path)
{
    
    sf::Texture texture;
    
    // Load texture from file or create an empty
    if (!texture.loadFromFile(path))
    {
        std::cout << "Texture [" << path << "] could not be loaded.\n";
        texture.create(200, 200); 
    }
    
    // Add texture to array
    textures.push_back(texture);
    
}

void Canvas::addFont(std::string path)
{
}



// Setup canvas scenes
void Canvas::setupScenes()
{
        
    // Setup "simulation" scene
    scene_0.setup(window, &isFocused, textures);
    
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
