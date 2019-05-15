# Changes that were made 

## Why
I'm making this file because we're early on in the process and we were building our abstract infrastructure of the project but I've already made some big changes and started a whole lot by myself. I don't think I'll need to use this file again since the next changes won't probably be as big and as hard to adapt.

## The Changes 

I'll topicalize all the changes according to the `.h` files that were created regarding the structs. 

## `Cell.H` 

* The biggest change is that I've changed the `living_status` boolean to only `alive`. This way I think it`'s a lot more intuitive to see the current state of the cell. If the value is **false** then it's not alive and if it's **true** then it is alive.s

* I've created two alternative constructors:
    * **Cell(bool state)** - this one I use to help when initializing our Cell matrix, I automatically set all cells to dead. 
    * **Cell(int w, int z)** - I intialize with the coordinates. I haven't really used this one yet. Maybe I ever won't.

* I've defined operators:
    * logical ==
    * logical !=
    * assignment = 
    * printing <<

## `Generation.h`

* Defined the logical == operator 
* Created some stats 
    * generation_number to help detect the number if we find a equal generation later on in the game 
    * state - extinct, running, etc...
    * living_cells - a vector of all the living cells


## `Life.h`

Ok so this one is the most important data structure and it's also the one in which I've made the most changes.

The most important thing to understand, I think, it's the difference between the **virtual** and **actual** size of our Matrix, which I'll be refering to as Grid.

Let's say I wanted to create a 3x3 Grid, with, consequently, 9 cells total. The **virtual lenght and height** of the grid will be equal to 3. 

Underneath, in the code, **we're allocating a 5x5 grid** so that we have an easier time when dealing with the cells that are in the **virtual** limits. Basically, it'll make it easier to check their neighbours.

With this out of the way, we can start describing the changes that I've made.

* Attributes

    * Grid Cells - It's our matrix
    * \<Vector> all_generations - self explanatory
    * Generation current - also self explanatory
    * int height - **virtual** height of the grid
    * int lenght - **virtual** lenght of the grid
* Constructors
    * I've made a alternate constructor that initializes the Life struct with the dimensions of the grid.
        * Notice that inside the code I allocate 2 more lines and 2 more columns that the ones that were passed as arguments.
* Other Important Functions

    * count_alive_neighbours()
        * what it does is pretty self explanatory 
        * it helps us with the checking of all the game rules
    * I made bool functions for all the rules. I defined that the bool return will defined the **bool alive_next_state** parameter of the cell. So, if the function returns **true**, then the cell's **alive_next_state** will equal **true**.
        * I think we only need to maintain the Rule03 and Rule04 functions.
    * check_cell_state - determines the cell's **alive_next_state** attribute.
    * check_surroundings - applies the check_cell_state function to a specific cell and its neighbours.

This part of the code got really modulated, which I thought was pretty good because the subsequent functions got really simple and intuitive to understand. The main function basically is the **count_alive_neighbours**.



