#include <UI/button.hpp>


// Construct button environment
Button::Button(sf::Font font, std::string label)
{
    
    // Create text objects
    buttonText.setFont(font);
    buttonText.setString(label);
    
}



// Configure button states
void Button::configureDefault(sf::Color color, int size)
{
    defaultColor = color;
    defaultSize = size;
}

void Button::configureClick(sf::Color color, int size)
{
    clickColor = color;
    clickSize = size;
}

void Button::configureHover(sf::Color color, int size)
{
    hoverColor = color;
    hoverSize = size;
}

