#pragma once
#include <SFML/Graphics.hpp>
#include <string>


class Button
{
    private:
        
        // Button's colors
        sf::Color defaultColor;
        sf::Color clickColor;
        sf::Color hoverColor;
        
        // Button's sizes
        int defaultSize;
        int clickSize;
        int hoverSize;
        
        // Button "Text" object
        sf::Text buttonText;
        
        
    public:
        
        // Default constructor
        Button() {};
        
        // Construct button environment
        Button(sf::Font font, std::string label);
        
        
        // Button check methods
        void checkClick(sf::Event& action, void (*f));
        void checkHover();
        
        
        // Configure button states
        void configureDefault(sf::Color color, int size);
        void configureClick(sf::Color color, int size);
        void configureHover(sf::Color color, int size);
    
};
