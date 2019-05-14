#ifndef CELL_H
#define CELL_H


struct Cell
{
    bool alive; // check if its alive in this current generation
    int x;  // x position
    int y; // y position
    bool alive_next_state; //check if its alive next state
    bool checked; //checks if the cell has already been analysed by the check__cell__state function
    
    ~Cell(){/*empty*/}

    Cell(){/*empty*/}
    
    Cell(Cell &other): alive(other.alive), x(other.x), y(other.y), alive_next_state(other.alive_next_state), checked(other.checked)
    {/*empty*/}
    bool operator==(Cell &other) const //defines equality amongst cells
    {
        return (this->x == other.x) && (this->y == other.y);
    }
    bool operator!=(Cell &other)
    {
        return !(*this == other);
    }
    Cell& operator=(Cell &other) 
    {
        this->alive = other.alive;
        this->x = other.x;
        this->y = other.y;
        this->alive_next_state = other.alive_next_state;
        this->checked = other.checked;
        return *this;

    }
    

};




#endif