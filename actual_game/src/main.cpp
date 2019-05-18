#include "../include/life.h"
#include "../include/ioput.h"
#include <iostream>


std::ostream& operator<<(std::ostream& os, const Cell &target) 
{
    os << ">>Cell of  grid position [" << target.line - 1 << "][" << target.column - 1   << "]\n";
    os << ">>>>>Alive: " << target.alive << std::endl;
    os << ">>>>>Alive Next State: " << target.alive_next_state << std::endl;
    return os;
}
std::ostream& operator<<(std::ostream& os, const Life &target) 
{
    os << ">>>>PRINTING CURRENT GRID STATE: \n";
    for(int i = 0; i < target.height; i++)
    {
        for(int j = 0; j < target.lenght; j++)
        {
            os << target.Cells[i+1][j+1];
        }
    }
    return os;
}
std::ostream& operator<<(std::ostream& os, const Generation &target) 
{
    os<< ">>>>PRINTING LIVING CELLS \n";
    for(auto i (0u); i < target.living_cells.size(); i++)
    {
        os << target.living_cells[i];
    }
    return os;
}


int main()
{
    Life game = read_input();
    Life game2 = read_input();
    game.update();
    game.update();
    game.update();
    Generation g03 = game.current;
    game.update();
    game.current = g03;
    int result = game.search_for_equal_gen();
    std::cout << result;
    
}


