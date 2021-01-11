#include <engine/canvas.hpp>


// Main project entry-point
int main(int argc, char* argv[])
{
    
    Canvas canvas(1920, 1080, "Cellular Automata");
    canvas.Run();
    
    // Exit C++ environment
    return 0;

}


