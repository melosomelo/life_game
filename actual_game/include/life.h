#ifndef LIFE_H
#define LIFE_H

#include "cell.h"
#include "generation.h"
#include <vector>
#include <fstream>
#include <string>


struct Life
{      
     public:
        using Grid = std::vector<std::vector<Cell>>;


        //The actual grid of all cells 
        Grid Cells;
        //All the generations 
        std::vector<Generation> all_generations;
        //The current generation of living cells
        Generation current;
        //Virtual lenght and height
        int lenght;
        int height;

        Life(){/*empty*/}
        ~Life(){/*empty*/}
        Life(int lines, int columns);//Initializing the struct with the dimensions of the grid

        Life& operator=(const Life &other)
        {
            this->Cells = other.Cells;
            this->all_generations = other.all_generations;
            this->current = other.current;
            this->lenght = other.lenght;
            this->height = other.height;
            this->current.generation_number = other.current.generation_number;
            return *this;
        }



        bool stable() const
        {
            return this->current.state == Stable;

        }

        bool extinct() const
        {
            return this->current.state == Extinct;
        }

        int count_alive_neighbours(Cell &subject)const;

    ///===Rules 
    // == By definition, if the return value is true, then the cell's next state will be alive.
    // == All the rules are functional and have been tested. 
        bool Rule01(Cell &subject) const; //A living cell stays alive if it has more than 1 living neighbour


        bool Rule02(Cell &subject)const ; //A living cell stays alive if it has less than 4 living neighbours


        bool Rule03(Cell &subject) const; //A living cell stays alive if it has 2 or 3 living neighbours

        bool Rule04(Cell &subject) const; // A dead cell will become alive if it has exactly three living neighbours


        void check_cell_state(Cell &subject);


        void check_surroundings(Cell &subject);


        void update_current_generation(); //Function that stores the current generation and changes the cell's states


        int search_for_equal_gen();  //determine wether there has been a generation equal to the current one 


        void update_gen_status();

        void update(); //general update that does all the functions regarding checking cell state and updating generations



    
    

};






#endif