#include "../include/cell.h"
#include "../include/generation.h"
#include "../include/life.h"
#include "../include/ioput.h"
#include "../include/out_put.h"
#include <vector>
#include <iostream>
#include <fstream>



std::ostream& operator<<(std::ostream& os, const Cell &target) 
{
    os << ">>Cell of  grid position [" << target.line - 1 << "][" << target.column - 1   << "]\n";
    os << ">>>>>Alive: " << target.alive << std::endl;
    os << ">>>>>Alive Next State: " << target.alive_next_state << std::endl;
    return os;
}
std::ostream& operator<<(std::ostream& os, const Life &target) 
{
    for(int i = 0; i < target.get_height(); i++)
    {
        os << "[";
        for(int j = 0; j < target.get_lenght(); j++)
        {
            if(target.Cells[i][j].alive)
                os << " * ";
            else
                os <<  "   ";
                
        }
        os << "]";
        os<< std::endl;
    }

    return os;
}
std::ostream& operator<<(std::ostream& os, const Generation &target) 
{
    os << "Generation " << target.generation_number << std::endl;
    return os;
}

int main(int argc, char* argv[])
{
    Life game;
    ioput test;
    std::ofstream outfile;
    test.check_cmd_line_specs(argv, argc); //read command line specs 
    outfile.open(test.get_outfile()); //opening the outfile

    out_put out(test);

    game = test.read_input();
    while(game.current.state != Game_Over && game.current.generation_number!= test.get_maxgen())
    {
        outfile << game.current;
        outfile << game;
        if(test.get_imgdir() == "null")
        {
            std::cout << game.current;
            std::cout << game;
        }else{
            out.print_out_image( game );
        }
        game.update();
        

    }
    if(game.current.generation_number == test.get_maxgen())
        std::cout << "MAX GEN NUMBER WAS ACHIEVED. CHECK OUTFILE FILE FOR THE RESULT. \n";

    

}
    