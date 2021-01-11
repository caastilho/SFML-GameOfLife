#include "game/board.hpp"
#include <iostream>
#define log(x) std::cout << x << "\n";


// Setup board environment
Board::Board()
{
    canvas = nullptr;
    width = 0;
    height = 0;
    
    // Setup cell size
    shape.setSize(sf::Vector2f(0, 0));
}

Board::Board(int _width, int _height, int _size, sf::RenderWindow* _canvas)
{
    setValues(_width, _height, _size, _canvas);
}

void Board::setValues(int _width, int _height, int _size, sf::RenderWindow* _canvas)
{
    canvas = _canvas;
    width = _width;
    height = _height;
    
    // Setup cell size
    shape.setSize(sf::Vector2f(_size, _size));
    
    // Setup matrices sizes
    matrix = std::vector<std::vector<int>>(height);
    copied = std::vector<std::vector<int>>(height);
    
    // Setup matrix values
    setupMatrix();
}


// Setup matrices valuess
void Board::setupMatrix()
{
    
    // Create rows
    for (int y=0; y < height; y++)
    {
        
        // Create row object
        std::vector<int> row(width);
        matrix.push_back(row);
        
        // Create columns
        for (int x=0; x < width; x++)
        {
            matrix[y].push_back(0);
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
        
        // Bond indexes if needed
        if (y > height) y = 0;
        if (y < 0) y = height;
        
        if (x > width) x = 0;
        if (x < 0) x = width;
        
        // Add to the neighbours count
        neighbours += copied[y][x];
    }
    
    // Return cells
    return neighbours;
    
}



// Run simulation
void Board::run()
{

    copied = matrix;
    update();
    draw();
    
}


// Update cell's states
void Board::update()
{
    
    // Iterate thru matrix dimensions
    for (int y=0; y < copied.size(); y++)
        for (int x=0; x < copied[0].size(); x++)
        {
            
            int value = copied[y][x];
            int neighbours = getNeighbours(y, x);

            if (value == 1 && (neighbours == 3 || neighbours == 2)) {value = 1;}
            else if (value == 0 && neighbours == 3) {value = 1;}
            else {value = 0;}
            
            // Update value
            matrix[y][x] = value;
            
        }
    
}


// Draw cells on the canvas
void Board::draw()
{
    // Iterate thru matrix dimensions
    for (int y=0; y < matrix.size(); y++)
        for (int x=0; x < matrix[0].size(); x++)
        {
            
            // Update shape position
            int scaler = shape.getSize().x;
            shape.setPosition(x * scaler, y * scaler);
            
            // Set fill color
            if (matrix[y][x] == 0) shape.setFillColor(sf::Color(0, 0, 0));
            if (matrix[y][x] == 1) shape.setFillColor(sf::Color(255, 255, 255));
            
            // Draw shape
            canvas->draw(shape);
        }
}



// Add pattern to matrices
void Board::add(const char* name, int startX, int startY)
{
    std::vector<std::vector<int>> pattern = getPattern(name);
    
    // Add pattern to main matrix
    for (int y=0; y < pattern.size(); y++)
        for (int x=0; x < pattern[0].size(); x++)
            matrix[startY + y][startX + x] = pattern[y][x];
    
}
