#ifndef CELL_H
#define CELL_H

#include <iostream>


struct Cell
{
    bool alive; // check if its alive in this current generation
    int x;  // x position
    int y; // y position
    bool alive_next_state; //check if its alive next state
    bool checked; //checks if the cell has already been analysed by the check__cell__state function
    
    ~Cell(){/*empty*/}

    Cell(){/*empty*/}

    Cell(bool state): alive(state) //Default constructor that initializes a dead cell with no position
    {/*empty*/}

    Cell(int w, int z): x(w), y(z) //Initializing cell with only the position
    {/*empty*/}
    
    bool operator==(Cell &other) const //defines equality amongst cells
    {
        return (this->x == other.x) && (this->y == other.y);
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

std::ostream& operator<<(std::ostream& os, const Cell &target) 
{
    os << ">>Cell of  grid position (" << target.x - 1 << "," << target.y - 1   << ")\n";
    os << ">>>>>Alive: " << target.alive << std::endl;
    os << ">>>>>Alive Next State: " << target.alive_next_state << std::endl;
    return os;
}






#endif