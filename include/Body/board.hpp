#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>


// Conway's Game of Life board
class Board
{
    
    private:
        
        sf::RenderWindow* window;
        int width, height;
        float scaler = 10;
        
        
        // Cell's shape
        sf::RectangleShape shape;


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
        
        // Default board constructor
        Board() {};
        
        // Board constructor
        Board(int _width, int _height, sf::RenderWindow* _window);
        
        
        // Run simulation
        void doGeneration();
        
        // Draw cell's states
        void drawStates();
        
        
        // Get cell scaler without transformation
        float getScaler();
        
    
        // Pattern management
        void add(std::vector<std::vector<int>> pattern, int startX, int startY);
        
        // Change cell state
        void updateCell(int x, int y, int newState);
};
