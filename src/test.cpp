#include "../include/cell.h"
#include "../include/generation.h"
#include "../include/life.h"
#include "../include/ioput.h"
#include <vector>
#include <iostream>

//THIS IS ONLY A TESTING FILE TO TEST THE STRUCTS THAT WE'VE BEEN MAKING
//USE IT AT YOUR OWN WILL BUT MAKE SURE TO LEAVE SOME COMMENTS TO WHAT YOU'RE TESTING

std::ostream& operator<<(std::ostream& os, const Cell &target) 
{
    os << ">>Cell of  grid position [" << target.line - 1 << "][" << target.column - 1   << "]\n";
    os << ">>>>>Alive: " << target.alive << std::endl;
    os << ">>>>>Alive Next State: " << target.alive_next_state << std::endl;
    return os;
}
std::ostream& operator<<(std::ostream& os, const Life &target) 
{
    for(int i = 0; i < target.height; i++)
    {
        os << "[";
        for(int j = 0; j < target.lenght; j++)
        {
            if(target.Cells[i+1][j+1].alive)
                os << " * ";
            else
                os <<  " . ";
                
        }
        os << "]";
        os<< std::endl;
    }

    return os;
}
std::ostream& operator<<(std::ostream& os, const Generation &target) 
{
    os << "Generation " << target.generation_number << std::endl;

}

int main()
{
    Life game;
    game = read_input();
    while(game.current.state != Game_Over)
    {
        std::cout << game.current;
        std::cout << game;
        game.update();
        

    }

    

}
    
    
    



    
    
    



