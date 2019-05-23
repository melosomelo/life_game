#include "../include/cell.h"
#include "../include/generation.h"
#include "../include/life.h"
#include "../include/ioput.h"
#include "../include/canvas.h"
#include "../include/common.h"
#include "../include/lodepng.h"
#include <vector>
#include <iostream>
#include <fstream>

std::ostream& operator<<(std::ostream& os, const Life &target) 
{
    for(int i = 0; i < target.height; i++)
    {
        os << "[";
        for(int j = 0; j < target.lenght; j++)
        {
            if(target.Cells[i+1][j+1].alive)
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

}

int main(int argc, char* argv[])
{
    Life game;
    int counter = 0;
    ioput test;
    std::ofstream outfile;
    test.check_cmd_line_specs(argv, argc); //read command line specs 
    outfile.open(test.get_outfile()); //opening the outfile
    game = test.read_input(); // return the life object with the input from specs.txt file
    life::Canvas image(game.lenght, game.height, test.get_blocksize()); //initializing the canvas object
    while(game.current.state != Game_Over && game.current.generation_number!= test.get_maxgen())
    {
        outfile << game.current;
        outfile << game;
        if(test.get_imgdir() == "null")
        {
            std::cout << game.current;
            std::cout << game;
        }
        else
        {
            test.paint_canvas(image, game, counter);
            counter++;
        }
        game.update();
        

    }
    if(game.current.generation_number == test.get_maxgen())
        std::cout << "MAX GEN NUMBER WAS ACHIEVED. CHECK OUTFILE FILE FOR THE RESULT. \n";

    

}
    
    
    



    
    
    



