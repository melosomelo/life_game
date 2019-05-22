#ifndef CELL_H
#define CELL_H



#include <iostream>

/*! \struct Cell
A abstraction of an actual Cell. It is the basic member of the simulation
and it only does really simple things, such as guard its own characteristics.s
*/
struct Cell
{
    bool alive;//!<Signals if the cell is alive or not
    int column;//!<The column in which the cell is
    int line; //!<The line in which the cell is
    bool alive_next_state;//!<Signals if the cell will be alive in the next gen
    

    /*!
    \brief Regular destructor
    */
    ~Cell(){/*empty*/}
    /*!
    \brief Regular constructor 
    */
    Cell(){/*empty*/}

    /*! 
    \brief Initializes a cell being dead, i.e., alive = false
    */
    Cell(bool state): alive(state) //constructor that initializes a dead cell with no position
    {/*empty*/}

    /*!
    \brief Intializes a cell with its positions already defined
    */
    Cell(int w, int z): column(w), line(z) //Initializing cell with only the position
    {/*empty*/}
    
    /*!
    \brief Defines the == operator for cells. They will be the same if their position is the same.
    */
    bool operator==(Cell &other) const //defines equality amongst cells
    {
        return (this->column == other.column) && (this->line == other.line);
    }
    /*!
    \brief The opposite of the == operator
    */
    bool operator!=(Cell &other) const
    {
        return !(*this == other);
    }
    /*!
    \brief Attribution operator for cells, it receives only the alive parameter.
    */
    Cell& operator=(const Cell &other) 
    {
        this->alive = other.alive;
        return *this;

    }
    

};








#endif