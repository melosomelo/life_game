#ifndef GENERATION_H
#define GENERATION_H

#include <vector>
#include "cell.h"

enum states{Running, Stable, Extinct, Game_Over};

struct Generation
{

    ~Generation(){/*empty*/}
    
    Generation(){/*empty*/}

    bool operator == (Generation &other)
    {
        if(this->living_cells.size() != other.living_cells.size())
            return false;
        else
        {
            for(auto i (0u); i < other.living_cells.size(); i++)
            {
                if(this->living_cells[i] != other.living_cells[i])
                    return false;
            }
        }
        return true;
    }

    //Enumeration to help with the state of the Generatio
    
    int generation_number; //identifies the generation

    int state; //receives one of the states defined in the enum

    std::vector<Cell> living_cells; //stores only the living cells;


};





#endif