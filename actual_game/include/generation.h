#ifndef GENERATION_H
#define GENERATION_H

#include <vector>
#include "cell.h"

enum states{Running, Stable, Extinct, Game_Over};

struct Generation
{

    ~Generation(){/*empty*/}
    
    Generation(){/*empty*/}

    Generation(std::vector<std::vector<Cell>> &grid, int height, int lenght): state(Running) //Receives the grid to capture only the living cells
    {
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < lenght; j++)
            {
                if(grid[i+1][j+1].alive)
                    this->living_cells.push_back(grid[i+1][j+1]);
            }
        }

    }

    Generation&  operator =( const Generation &other)
    {
        this->living_cells = other.living_cells;
        return *this;
    }



    bool operator == (Generation &other) const
    {
        if(this->living_cells.size() != other.living_cells.size())
            return false;
        else
        {
            for(auto i (0u); i < other.living_cells.size(); i++)
            {
                if(this->living_cells[i] != other.living_cells[i])
                    return false;
                else
                    continue;
            }
        }
        return true;
    }

    
    int generation_number; //identifies the generation

    int state; //receives one of the states defined in the enum

    std::vector<Cell> living_cells; //stores only the living cells;


};









#endif