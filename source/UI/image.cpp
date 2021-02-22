#include <UI/image.hpp>


// Construct image sprite
Image::Image(sf::Texture& texture, int width, int height)
{
    
    // Image container
    sf::RectangleShape container(sf::Vector2f(width, height));
    
    // Setup image texture
    sprite.setTexture(texture);
    
    // Scale sprite based on desired dimensions
    sf::Vector2u sprite_dimensions = texture.getSize();
    float x = width  / (float)sprite_dimensions.x;
    float y = height / (float)sprite_dimensions.y;
    
    sprite.scale(x, y);
    
}


// Set image X, Y positions
void Image::setPosition(float x, float y)
{
    sprite.setPosition(sf::Vector2f(x, y));
}



// Display image
void Image::display(sf::RenderWindow* window)
{
    window->draw(sprite);
}

