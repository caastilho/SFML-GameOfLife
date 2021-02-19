#include <Scripts/reader.hpp>


// Convert .cell files to Conway's Game Of Life patterns (Matrix)
std::vector<std::vector<int>> getPattern(std::string path)
{
    
    std::vector<std::vector<int>> matrix;
    
    // Open input file
    std::string line;
    std::ifstream file;
    file.open(path);
    
    // Get lines from file
    while (file)
    {
        getline(file, line);
        
        // Create row object
        std::vector<int> row;
        for (char character : line)
        {
            if (character == '.') {row.push_back(0);} 
            else if (character == 'O') {row.push_back(1);}
        }
        
        // Add row to matrix
        matrix.push_back(row);
    }
    
    // Close file
    file.close();
    
    // Return matrix
    return matrix;
    
}
