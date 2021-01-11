#pragma once
#include "game/reader.hpp"
#include <SFML/Graphics.hpp>
#include <vector>


// 'Game Of Life' board.
// Style: Finite - Warp
class Board
{
    
    private:
        sf::RectangleShape shape;
        
        int width;
        int height;
        sf::RenderWindow* canvas;

        // Cell's states. Stored inside 2D matrices
        std::vector<std::vector<int>> matrix;
        std::vector<std::vector<int>> copied;
        
        // Setup matrix
        void setupMatrix();
        
        // Run simulation
        void draw();
        void update();
        
        // Get neighbouring cells
        int getNeighbours(int y, int x);

    public: 
        
        // Run simulation
        void run();
        
        // Construct environment
        void setValues(int _width, int _height, int _size, sf::RenderWindow* _canvas);
        Board(int _width, int _height, int _size, sf::RenderWindow* _canvas);
        Board();
        
        // Pattern management
        void add(const char* name, int startX, int startrY);    
};
