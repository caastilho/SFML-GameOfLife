#pragma once
#include <SFML/Graphics.hpp>
#include <Body/board.hpp>
#include <vector>


class Editor
{
        
    private:
        
        // Game of Life board pointer
        Board* board;
        
        // Render window pointer
        sf::RenderWindow* window;
        
        
        // Check if index is within bonderies
        bool isInBonderies(int x, int y);
        
        
        // Get X, Y board position based on view and cursor X, Y
        sf::Vector2i getTruePosition(float x, float y);
        
        // Change cell position to "alive"
        void bornCell(int x, int y);
        
        // Change cell position to "dead"
        void killCell(int x, int  y);
        
        
    public:
        
        // Default constructor
        Editor() {};
        
        // Construct "Editor" environment
        Editor(Board* _board, sf::RenderWindow* _window): board(_board), window(_window) {};
        
        
        // Handle window clicks when "Editor" mode is active
        void edit(sf::Event& action);
        
};
