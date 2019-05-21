#ifndef GENERATION_H
#define GENERATION_H

#include <vector>
#include "cell.h"
/*!
\enum An enum to help the with identifying the current game/generation state
*/
enum states{Running, Stable, Extinct, Game_Over};

/*!
\struct Generation
A bundle of cells. It is basically a more massive cell as it is a simple as a single one.
Every generation is defined only by its living cells, since it's an easier way to determine equality amongst generations.
*/
struct Generation
{

    /*!
    \brief A regular destructor 
    */
    ~Generation(){/*empty*/}
    /*! 
    \brief A regular constructor 
    */
    Generation(){/*empty*/}

    /*!
    An alternate constructor that receives a matrix of all cells used in the simulation, a.k.a. grid.
    It captures only its living cells and pushes them back in the living_cells vector
    @param Grid of cells 
    @param Height of the grid 
    @param Lenght of the grid
    @return A generation object
    */
    Generation(std::vector<std::vector<Cell>> &grid, int height, int lenght): state(Running) 
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

    /*!
    \brief Definition of the atribution operator between Generation. It receives the living_cells vector
    */

    Generation&  operator =( const Generation &other)
    {
        this->living_cells = other.living_cells;
        return *this;
    }


    /*!
    \brief Definition of the == operator between Generations. It returns true if all the living cells are the same 
    */
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

    
    int generation_number; /*!<Generation number for identification*/

    int state; /*!<State according to the enum previously defined*/

    std::vector<Cell> living_cells; /*!<Vector to story the living cell of each generation*/


};









#endif