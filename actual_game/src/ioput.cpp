#include "../include/ioput.h"



Life read_input()
{
    int height, lenght; //dimensions of the cell grid
    std::ifstream input_specs; //file from which we will read the specs
    std::string line; //string to store lines from the file 
    char alive_char;
    input_specs.open("specs.txt");
    input_specs >> height >> lenght;
    Life grid(height, lenght); //initializing the new object
    input_specs >> alive_char; 
    input_specs.get();
    input_specs.get();
    for(int i = 0 ; i < height; i++)
    {
        std::getline(input_specs, line);
        std::cout << "LINE IS " << line << std::endl;
        for(int j = 0; j < lenght; j++)
        {
            if(line[j] == alive_char)
            {
                grid.Cells[i+1][j+1].alive = true;
                grid.current.living_cells.push_back(grid.Cells[i+1][j+1]);
            }
        }
        
    }
    grid.current.generation_number = 0;
    grid.current.state = Running;
    return grid;


}


