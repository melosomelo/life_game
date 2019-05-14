
# The Classes/Structs

This will be the classes that we're going to use. We'll adopt a bottom-up building strategy so that it will make everything more gradual and, consequently, a lot easier.

## Struct Cell 

* **bool** current_state (checks wether the cell is alive or not )
* **int** x  (x position in the grid)
* **int** y (y position in the grid)
* **bool** next_state (next state on the grid - this guarantees that everything will happen at the same time)
* operator == 
* bool checked 
	* Checks if the cell has already been analysed by the **check__cell_state** function.

## Struct Generation 

For organization's sake, we'll use 5 states that the current simulation may have, that will be:
* Running         
* Stable 
* Extinct 
* Game Over 

*There will be a **typedef** for these states, with an **int** type.*

* vector\<Cell> living_cells
* **int** state 
* **int** generation_number
* int state


## Class Life

* vector\<vector\<Cell>> grid
* check_equal(Generation current) 
* update() - updates the state of the the current generation 
* stable()
* extinct()
* void check_cell_state() (check the cells neighbours of the cell to determine its next state)
* void check_surroundings() 
	* Applies the **check_cell_state** in a cell and in all its neighbours 
	* guarantees that the **checked** atribute will be useful, since we're individualizing the analysis.
