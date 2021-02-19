#include <Graphics/canvas.hpp>


// Main entry-point
int main(int argc, char* argv[])
{
    
    // Setup canvas object
    Canvas canvas(1920, 1080, "Cellular Automata");
    
    // Run canvas environment
    canvas.run();
    
    // Exit C++ environment
    return 0;

}


