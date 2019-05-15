#ifndef LIFE_H
#define LIFE_H

#include "cell.h"
#include "generation.h"
#include <vector>

struct Life
{   
        using Grid = std::vector<std::vector<Cell>>;

        //The actual grid of all cells 
        Grid Cells;
        //All the generations 
        std::vector<Generation> all_generations;
        //The current generation of living cells
        Generation current;

        int lenght; //virtual lenght of the grid, not considering the fake dead cells
        int height; //virtual height of the grid, not considering the fake dead cells
    

        Life(){/*empty*/}
        ~Life(){/*empty*/}
        Life(int lines, int columns) //Initializing the struct with the dimensions of the grid
        {
            Cell dead(false);
            Grid temp_grid (lines+2, std::vector<Cell>(columns+2));
            for(int i = 0; i < lines+2; i++)
            {
                for(int j = 0; j < columns+2; j++)
                {
                    temp_grid[i][j] = dead;
                    temp_grid[i][j].x = i;
                    temp_grid[i][j].y = j;
                }
            }
            this->Cells = temp_grid;
            this->lenght = columns;
            this->height = lines;

        }



        bool stable()
        {
            return this->current.state == Stable;

        }

        bool extinct()
        {
            return this->current.state == Extinct;
        }

        int count_alive_neighbours(Cell &subject) 
        {
            int alive_neighbours = 0;
            for(auto i = subject.x - 1; i <= subject.x + 1; i++)
            {
                for(auto j = subject.y - 1; j <=subject.y + 1; j++ )
                {
                    if(i == subject.x && j == subject.y)   
                        continue;
                    else
                    {
                        if(this->Cells[i][j].alive)
                            alive_neighbours++;
                        
                    }
                }
            }
            return alive_neighbours;
        }
    ///===Rules 
    // == By definition, if the return value is true, then the cell's next state will be alive.
    // == All the rules are functional and have been tested. 
        bool Rule01(Cell &subject) //A living cell stays alive if it has more than 1 living neighbour
        {
            int alive_neighbours = count_alive_neighbours(subject);
            return alive_neighbours > 1;

        }

        bool Rule02(Cell &subject) //A living cell stays alive if it has less than 4 living neighbours
        {
            int alive_neighbours = count_alive_neighbours(subject);
            return alive_neighbours < 4;

        }

        bool Rule03(Cell &subject) //A living cell stays alive if it has 2 or 3 living neighbours
        {
            int alive_neighbours = count_alive_neighbours(subject);
            return (alive_neighbours == 2) || (alive_neighbours == 3);
        }
        bool Rule04(Cell &subject) // A dead cell will become alive if it has exactly three living neighbours
        {
            int alive_neighbours = count_alive_neighbours(subject);
            return alive_neighbours == 3;
        }

        void check_cell_state(Cell &subject)
        {
            if(subject.alive)
                subject.alive_next_state = (Rule01(subject) && Rule02(subject) && Rule03(subject));
            else
                subject.alive_next_state = Rule04(subject);
        }

        void check_surroundings(Cell &subject)
        {
            for(int i = subject.x - 1; i <= subject.x + 1; i++)
            {
                for(int j = subject.y - 1; j <=subject.y + 1; j++)
                {
                    this->check_cell_state(this->Cells[i][j]);
                }
            }
        }

    
    

};

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





#endif