#pragma once
#include "game/reader.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>


// Conway's Game of Life board
class Board
{
    
    private:
        sf::RenderWindow* canvas;
        int width;
        int height;
        
        // Cell's shape
        sf::RectangleShape shape;

        // Cell's states. Stored inside 2D matrices
        bool isCheckCreated = false;
        
        std::vector<sf::Vector2u> check;
        std::vector<std::vector<int>> matrix;
        std::vector<std::vector<int>> copied;
        
        // Setup matrix
        void setupMatrix();
        void setupCheck();
        void addToCheck(int y, int x);
        
        // Get neighbouring cells
        int getNeighbours(int y, int x);

    public: 
        
        // Run simulation
        void doGeneration();
        void drawStates(float startX, float startY, float width, float height, float scaler);
        
        // Construct environment
        void set(int _width, int _height, sf::RenderWindow* _canvas);
        Board(int _width, int _height, sf::RenderWindow* _canvas);
        Board();
        
        // Pattern management
        void add(const char* name, int startX, int startY);    
};
