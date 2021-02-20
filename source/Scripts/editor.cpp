#include <Scripts/editor.hpp>


// Handle window clicks when "Editor" mode is active
void Editor::edit(sf::Event& action)
{

    // Mouse release button event
    if (action.type == sf::Event::MouseButtonReleased)
    {
        
        // Left mouse button release
        if (action.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2i position = getTruePosition(action.mouseButton.x, action.mouseButton.y);
            bornCell(position.x, position.y);
        }
        
        // Right mouse button release
        if (action.mouseButton.button == sf::Mouse::Right)
        {
            sf::Vector2i position = getTruePosition(action.mouseButton.x, action.mouseButton.y);
            killCell(position.x, position.y);
        }
        
    }
}



// Get X, Y board position based on view and cursor X, Y
sf::Vector2i Editor::getTruePosition(float x, float y)
{
    
    // Convert window mouse position to world mouse position
    sf::Vector2i windowPosition = sf::Mouse::getPosition(*window);
    sf::Vector2f worldPosition = window->mapPixelToCoords(windowPosition);
    
    // Convert world position to board indexes
    float cellSize = board->getScaler();
    int indexX = (int)(worldPosition.x / cellSize);
    int indexY = (int)(worldPosition.y / cellSize);
    
    // Change cell state
    return sf::Vector2i(indexX, indexY);
    
}

// Change cell position to "alive"
void Editor::bornCell(int x, int y)
{
    board->updateCell(x, y, 1);
}

// Change cell position to "dead"
void Editor::killCell(int x, int  y)
{
    board->updateCell(x, y, 0);
}
