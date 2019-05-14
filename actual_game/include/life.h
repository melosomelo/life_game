#ifndef LIFE_H
#define LIFE_H

#include "cell.h"
#include "generation.h"
#include "all_generations.h"

class Life
{
    Life(){/*empty*/}
    ~Life(){/*empty*/}

    //The actual grid of all cells 
    std::vector<std::vector<Cell>> Grid;
    //All the generations 
    std::vector<Generation> all_generations;

    Generation current;



    bool stable()
    {
        return this->current.state == Stable;

    }
    bool extinct()
    {
        return this->current.state = Extinct;
    }

    
    

};





#endif