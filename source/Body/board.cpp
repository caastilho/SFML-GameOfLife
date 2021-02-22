#include <Body/board.hpp>
#include <iostream>


// Setup board environment
Board::Board(int _width, int _height, sf::RenderWindow* _window): width(_width), height(_height), window(_window)
{
    
    // Setup cell attributes
    shape.setFillColor(sf::Color(225, 225, 255));
    
    // Setup grid line attributes
    gridLine.setFillColor(sf::Color(10, 10, 13));
    
    // Setup matrix values
    setupMatrix();
}



// Setup matrices valuess
void Board::setupMatrix()
{
    
    // Setup matrices sizes
    matrix = std::vector<std::vector<int>>(height);
    copied = std::vector<std::vector<int>>(height);
    
    // Create rows
    for (int y=0; y < height; y++)
        for (int x=0; x < width; x++)
        {
            matrix[y].push_back(0);
        }
}

void Board::setupCheck()
{
    
    // Iterate thru matrix dimensions
    for (int y=0; y < matrix.size(); y++)
        for (int x=0; x < matrix[0].size(); x++)
        {
            int value = matrix[y][x];
            
            // Add cell and neighbours to 'check' cell is alive
            if (value == 1) 
                addToCheck(y, x);
        }
}

void Board::addToCheck(int y, int x)
{
    // Add cell and neighbours to 'check' cell is alive
    for (int dy=-1; dy <= 1; dy++)
        for (int dx=-1; dx <= 1; dx++)
        {
            
            // Get cell coordinates
            unsigned int yValue = y + dy;
            unsigned int xValue = x + dx;
            
            // Validate coordinates
            bool isYValid = yValue >= 0 && yValue < matrix.size();
            bool isXValid = xValue >= 0 && xValue < matrix[0].size();
            
            if (isYValid && isXValid)
            {
                sf::Vector2u newPosition(xValue, yValue);
                bool found = false;
                
                // Check if position is not in array
                for (sf::Vector2u& position : check)
                {
                    if (position == newPosition)
                    {
                        found = true;
                        break;
                    }
                }
                
                // Add to 'check' array
                if (!found)
                    check.push_back(newPosition);
            }
        }
}



// Get the amount of neighbouring cell
int Board::getNeighbours(int y, int x)
{
    
    // Get new indexes
    std::vector<int> cellsIndexes;
    
    for (int dy=-1; dy <= 1; dy++)
        for (int dx=-1; dx <= 1; dx++)
        {
            
            // Check if delta indexes are not 0, 0
            if (!(dy == 0 && dx == 0))  
            {
                cellsIndexes.push_back(y + dy);
                cellsIndexes.push_back(x + dx);
            }
        }
    
    // Get neighbouring cells
    int neighbours = 0;
    for (int i=0; i <= 16; i += 2)
    {   
        
        int y = cellsIndexes[i];
        int x = cellsIndexes[i + 1];
        
        // Add to the neighbours count
        if (0 <= x && x < width && 0 <= y && y < height)
            neighbours += copied[y][x];
    }
    
    // Return cells
    return neighbours;
    
}



// Update cell's states
void Board::doGeneration()
{
    
    copied = matrix;
    std::vector<sf::Vector2u> oldCheck = check;
    check.clear();
    
    
    // Iterate thru matrix dimensions
    for (int i=0; i < oldCheck.size(); i++)
    {
        sf::Vector2u& coordinates = oldCheck[i];
        int y = coordinates.y;
        int x = coordinates.x;
    
        if (0 <= x && x < width && 0 <= y && y < height)
        {
            
            int neighbours = getNeighbours(y, x);
            int value = copied[y][x];
            
            // Revive cell if conditions are favorable
            if (value == 1 && (neighbours == 3 || neighbours == 2))
            { 
                value = 1;
            }
            
            // Born cell if conditions are favorable
            else if (value == 0 && neighbours == 3)
            {
                value = 1;
            }

            // Kill cell by default (Overpopulation or Isolation)
            else
            {
                value = 0;
            }
            
            // Update value
            matrix[y][x] = value;
            
            // Add to check if cell is alive
            if (value)
                addToCheck(y, x);
        }
    }
    
}

// Draw cells on the canvas
void Board::display()
{
    
    // Create check if it is not created
    if (!isCheckCreated)
    {
        setupCheck();
        isCheckCreated = true;
    }
    
    // Resize shape
    shape.setSize(sf::Vector2f(scaler, scaler)); 

    // Draw alive cells
    for (sf::Vector2u& coordinate : check)
    {
        
        int x = coordinate.x;
        int y = coordinate.y;
        
        if (matrix[y][x])
        {
            shape.setPosition(x * scaler, y * scaler);
            window->draw(shape);
        }
    }
    
    // Draw board's grid lines
    if (drawGridLines)
    {
        
        // Draw vertical lines
        gridLine.setSize(sf::Vector2f(1, height * scaler));
        for (int x = 0; x <= width; x++)
        {
            sf::Vector2f position(x * scaler, 0);
            gridLine.setPosition(position);
            window->draw(gridLine);
        }
        
        // Draw horizontal lines
        gridLine.setSize(sf::Vector2f(width * scaler, 1));
        for (int y = 0; y <= height; y++)
        {
            sf::Vector2f position(0, y * scaler);
            gridLine.setPosition(position);
            window->draw(gridLine);
        }
    }
    
}


// Add pattern to matrices
void Board::add(std::vector<std::vector<int>> pattern, int startX, int startY)
{
    // Add pattern to main matrix
    for (int y=0; y < pattern.size(); y++)
        for (int x=0; x < pattern[0].size(); x++)
            matrix[startY + y][startX + x] = pattern[y][x];    
}

// Change cell state
void Board::updateCell(int x, int y, int newState)
{
    matrix[y][x] = newState;
    if (newState)
        addToCheck(y, x);
}
