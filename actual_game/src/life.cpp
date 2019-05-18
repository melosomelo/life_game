#include "../include/life.h"


Life::Life(int lines, int columns)
{
    Cell dead(false);
    Grid temp_grid (lines+2, std::vector<Cell>(columns+2));
    for(int i = 0; i < lines+2; i++)
    {
        for(int j = 0; j < columns+2; j++)
        {
            temp_grid[i][j] = dead;
            temp_grid[i][j].line = i;
            temp_grid[i][j].column = j;
        }
    }
    this->Cells = temp_grid;
    this->lenght = columns;
    this->height = lines;
    this->current.state = Running;
    this->current.generation_number = 0;
}

int Life::count_alive_neighbours(Cell &subject) const
{
    int alive_neighbours = 0;
    for(auto i = subject.line - 1; i <= subject.line + 1; i++)
    {
        for(auto j = subject.column - 1; j <=subject.column + 1; j++ )
        {
            if(i == subject.line && j == subject.column)   
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
bool Life::Rule01(Cell &subject) const
{
    int alive_neighbours = count_alive_neighbours(subject);
    return alive_neighbours > 1;

}


bool Life::Rule02(Cell &subject) const
{
    int alive_neighbours = count_alive_neighbours(subject);
    return alive_neighbours < 4;

}

bool Life::Rule03(Cell &subject) const
{
    int alive_neighbours = count_alive_neighbours(subject);
    return (alive_neighbours == 2) || (alive_neighbours == 3);
}

bool Life::Rule04(Cell &subject) const
{
    int alive_neighbours = count_alive_neighbours(subject);
    return alive_neighbours == 3;
}

void Life::check_cell_state(Cell &subject)
{
    if(subject.alive)
        subject.alive_next_state = (Rule01(subject) && Rule02(subject) && Rule03(subject));
    else
        subject.alive_next_state = Rule04(subject);
}

void Life::check_surroundings(Cell &subject)
{
    for(int i = subject.line - 1; i <= subject.line + 1; i++)
    {
        for(int j = subject.column - 1; j <=subject.column + 1; j++)
        {
            if(i == 0 || j == 0 || i == this->height +1 || j == this->lenght +1) // we skip the ones in the outer limits
            {   
                continue;
            }
            this->check_cell_state(this->Cells[i][j]);
        }
    }
}

void Life::update_current_generation()
{
    for(int i = 0; i < this->height; i++) //updating the state of the cells
    {
        for(int j = 0; j < this->lenght; j++)
        {
            this->Cells[i+1][j+1].alive = this->Cells[i+1][j+1].alive_next_state; //updating the state of each single cell
            this->Cells[i+1][j+1].alive_next_state = false;
        }
    }
    this->all_generations.push_back(this->current); //storing the current generation
    this->current.living_cells.clear(); //clearing the living cells vector so that we can add the new ones
    Generation temp = Generation(this->Cells, this->height, this->lenght); //Creating a temporary generation 
    this->current = temp; //assigning the current generation to the temporary one we created
    this->current.generation_number += 1;

    
}

int Life::search_for_equal_gen()  //appears to be working
{
    for(const auto &i: this->all_generations)
    {   
        if(i == this->current)
        {
            this->current.state = Stable;
            return i.generation_number;
        } 
        
    }
    return -1;
}

void Life::update_gen_status()
{
    if(this->current.state == Stable || this->current.state == Extinct)
    {
        this->current.state = Game_Over;
        std::cout << ">>>>GAME OVER<<<< \n";
    }
    else
    {
        int possible_equal = this->search_for_equal_gen();
        if(possible_equal != -1)
        {
            std::cout << ">>>FOUND THAT GENERATION " << possible_equal << " IS EQUAL TO THE CURRENT ONE. CURRENT GENERATION IS NOW STABLE. \n";
            this->current.state = Stable;
        }
        else if(this->current.living_cells.size() == 0)
        {
            this->current.state = Extinct;
            std::cout << ">>>>ALL CELLS ARE DEAD. GENERATION IS EXTINTCT. \n";
        }
        else
        {
            this->current.state = Running;
        }
        

    }
    

}

void Life::update()
{
    for(auto &i: this->current.living_cells)
        this->check_surroundings(i);
    this->update_current_generation();
    this->update_gen_status();

}


