#ifndef CELL_H
#define CELL_H

#include <iostream>


struct Cell
{
    bool alive; // check if its alive in this current generation
    int column;  // real column position
    int line; // REAL line position
    bool alive_next_state; //check if its alive next state
    bool checked; //checks if the cell has already been analysed by the check__cell__state function
    
    ~Cell(){/*empty*/}

    Cell(){/*empty*/}

    Cell(bool state): alive(state) //constructor that initializes a dead cell with no position
    {/*empty*/}

    Cell(int w, int z): column(w), line(z) //Initializing cell with only the position
    {/*empty*/}
    
    bool operator==(Cell &other) const //defines equality amongst cells
    {
        return (this->column == other.column) && (this->line == other.line);
    }
    bool operator!=(Cell &other) const
    {
        return !(*this == other);
    }
    Cell& operator=(const Cell &other) 
    {
        this->alive = other.alive;
        return *this;

    }
    

};








#endif