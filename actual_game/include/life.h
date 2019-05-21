#ifndef LIFE_H
#define LIFE_H

#include "cell.h"
#include "generation.h"
#include <vector>
#include <fstream>
#include <string>

/*!
\struct Life 
The main data structure of the game. It manages all the main game functions and updates every single generation
It is responsible for determining everything that involves the Cell and Generation structs, since both are only storage-driven.
*/
struct Life
{      
     private:
        using Grid = std::vector<std::vector<Cell>>;


        



        int lenght; /*!<VIRTUAL lenght*/
        int height; /*!<VIRTUAL height*/

    public:
        std::vector<Generation> all_generations;/*!<All the past generations of living cells*/
        
        Generation current; /*!<The current generation of living cells*/
        
        Grid Cells;/*!<A matrix of cells*/
        
        
        /*!
        \brief Regular constructor
        */
        Life(){/*empty*/}
        /*! 
        \brief Regular destructor
        */
        
        ~Life(){/*empty*/}
        /*!
        An alternate constructor that initializes the grid filled of dead cells with the amount of lines and columns. 
        It allocates a larger matrix with +2 lines and columns since these extra lines and columns will help us in the 
        analysis of the surrounding area of the limit cells
        */
        Life(int lines, int columns);//Initializing the struct with the dimensions of the grid

        /*!
        Definition of the attribution operator for the Life object. 
        It receives the grid as well as its dimensions and the current generation
        */
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


        /*!
        @return A bool to signal if the generation is stable
        */
        bool stable() const
        {
            return this->current.state == Stable;

        }
        /*!
        @return A bool to signal if the generation is extinct
        */

        bool extinct() const
        {
            return this->current.state == Extinct;
        }

        /*!
        A function that counts the living neighbours of a specific cell. 
        This is function is extremely necessary since all the Rules that determine the next state of the cell revolve around the amount
        of living neighbours
        @param A specific cell
        @return The amount of living neighbours
        */

        int count_alive_neighbours(Cell &subject)const;

    ///===Rules 
    // == By definition, if the return value is true, then the cell's next state will be alive.
    // == All the rules are functional and have been tested. 
        bool Rule01(Cell &subject) const; /*!<Rule 01 of the game*/


        bool Rule02(Cell &subject) const ; /*!<Rule 02 of the game*/


        bool Rule03(Cell &subject) const; /*<Rule 03 of the game*/

        bool Rule04(Cell &subject) const; /*<Rule 04 of the game*/


        /*!
        A function that determines the cell's alive_next_state param. It counts the amount of living neighbours 
        and applies all the rules.
        @param A cell
        */
        void check_cell_state(Cell &subject);

        
        /*!
            This function return the Grid height
            @return height
        */
        
        int get_height() const{
            return height;
        }

        /*!
        This function return the Grid height
        @return height
        */
        int get_lenght() const{
            return lenght;
        }
        /*!
        A function that applies the check_cell_state function in a cell and in all of its neighbours
        @param a Cell
        */
        void check_surroundings(Cell &subject);


        /*!
        A function that updates the alive state of all cells, stores the current generation in the all_generations vector,
        assigns a new current generation and updates the number of the generation
        */
        void update_current_generation(); //Function that stores the current generation and changes the cell's states

        /*!
        A function that searches for an equal generation to the current one. 
        It returns -1 if it fails to find any.
        @return The number of the generation that is equal
        */
        int search_for_equal_gen();  //determine wether there has been a generation equal to the current one 


        /*!
        A function that updates the state of the current generation as it analysis the state of the living_cells vector and searches for an equal generation to 
        the current one.
        */
        void update_gen_status();

        /*!
        A general function that does all the functions that involve any form of minor update, such as
        updating the generation, the state of the cells, etc...
        */
        void update(); //general update that does all the functions regarding checking cell state and updating generations



    
    

};






#endif