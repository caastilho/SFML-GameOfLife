#include <Body/camera.hpp>


// Construct view object
Camera2D::Camera2D(int width, int height)
{
    view.setSize(width, height);
    view.setCenter(sf::Vector2f(width / 2.f, height / 2.f));
}


// Activate window view
void Camera2D::activate(sf::RenderWindow* window)
{
    window->setView(view);
}


// Convert delta to zoom value
float Camera2D::getZoomValue(float delta)
{
    float zoom;
    float factor = 0.15;
    
    // Scale view down
    if (delta < 0)
    { 
        zoom = 1 - factor;
    }
    
    // Scale view up
    else if (delta > 0)
    {
        zoom = 1 + factor;
    }
    
    return zoom;
}


// Update transformation
void Camera2D::updateView(float offset, bool isFocused)
{
    
    int x_scaler = 0;
    int y_scaler = 0;
    
    // Up movement
    if(isFocused && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        y_scaler = -1;

    // Left movement
    if(isFocused && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        x_scaler = -1;

    // Down movement
    if(isFocused && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        y_scaler = 1;

    // Right movement
    if(isFocused && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        x_scaler = 1;

    
    sf::Vector2f translation(x_scaler * offset, y_scaler * offset);
    view.move(translation);
    
}

void Camera2D::updateView(sf::Event& action, bool isFocused)
{
    
    // Scale scene based on mouse wheel delta
    if (isFocused && action.type == sf::Event::MouseWheelMoved)
    {
        int delta = action.mouseWheel.delta;
        float zoom = getZoomValue(delta);
        view.zoom(zoom);
    }
    
}
