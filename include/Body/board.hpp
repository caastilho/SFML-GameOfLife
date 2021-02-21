#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>


// Conway's Game of Life board
class Board
{
    
    private:
        
        sf::RenderWindow* window;        
        
        // Cell's shape
        sf::RectangleShape shape;
        
        
        // Draw grid lines
        bool drawGridLines = true;
        
        // Grid line shape object
        sf::RectangleShape gridLine;
        

        // Stores "check" matrix created state
        bool isCheckCreated = false;
        
        // Cell's states. Stored inside 2D matrices
        std::vector<sf::Vector2u> check;
        std::vector<std::vector<int>> matrix;
        std::vector<std::vector<int>> copied;
        
        // Setup matrices
        void setupMatrix();
        void setupCheck();
        void addToCheck(int y, int x);
        
        
        // Get neighbouring cells
        int getNeighbours(int y, int x);


    public: 
        
        // Board dimensions
        int width, height;
        
        // Board cell's size
        float scaler = 10;
        
        
        // Default board constructor
        Board() {};
        
        // Board constructor
        Board(int _width, int _height, sf::RenderWindow* _window);
        
        
        // Run simulation
        void doGeneration();
        
        // Draw board
        void display();
        
    
        // Pattern management
        void add(std::vector<std::vector<int>> pattern, int startX, int startY);
        
        // Change cell state
        void updateCell(int x, int y, int newState);
};
