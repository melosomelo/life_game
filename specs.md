
# The Classes/Structs

This will be the classes that we're going to use. We'll adopt a bottom-up building strategy so that it will make everything more gradual and, consequently, a lot easier.

## Cell 

* **bool** current_state (checks wether the cell is alive or not )
* **int** x  (x position in the grid)
* **int** y (y position in the grid)
* **bool** next_state (next state on the grid - this guarantees that everything will happen at the same time)


## Current Configuration 

For organization's sake, we'll use 5 states that the current simulation may have, that will be:
* Start (the simulation is starting now)
* Running         
* Stable 
* Extinct 
* Game Over 

*There will be a **typedef** for these states, with an **int** type.*
    