#ifndef INPUT_H
#define INPUT_H
#include "life.h"
#include "cell.h"
#include "generation.h"
#include <fstream>
#include <iostream>
#include <string>
#include "../../image_handling/include/canvas.h"
#include "../../image_handling/include/common.h"
#include "../../image_handling/include/lodepng.h"




class ioput
{
    private:
        bool help; //determines wether we will prent a help text
        std::string imgdir; //specify directory where output images are written to
        int maxgen; //maximum number of generations to simulate
        int fps; // Number of generations presented per second 
        int blocksize; //Pixel size of a cell. Default = 5
        life::Color bkgcolor; //Color name of the background. Default = GREEN.
        life::Color alivecolor; // Color name for representing alive cells. Default = RED.
        std::string outfile; //Write the text representation of the simulation to the given filename.
    public:
        ~ioput(){/*empty*/}
        /* 
         * Default constructor that sets the command line specifications 
         * @return A ioput object with the default specifications
         */
        ioput(): help(false), imgdir("../build/images"), maxgen(-1), fps(1), blocksize(5), bkgcolor(life::GREEN), alivecolor(life::RED), outfile("simulation.txt")
        {/*empty*/}

        /*
        * Reads a .txt file that stores the specs of the size of the grid and its distribution
        * of living and dead cells.
        * @return A Life object that will manage the Life Game Simulatiln
        */
        Life read_input();

        void check_cmd_line_specs(char* argv[], int argc);
        
        life::Color determine_color(std::string color);

        void print();

        bool get_help()
        {
            return this->help;
        }
        
        std::string get_imgdir()
        {
            return this->imgdir;
        }

        int get_maxgen()
        {
            return this->maxgen;
        }

        int get_fps()
        {
            return this->fps;
        }

        int get_blocksize()
        {
            return this->blocksize;
        }
        
        life::Color get_bkgcolor()
        {
            return this->bkgcolor;
        }
        life::Color get_alivecolor()
        {
            return this->alivecolor;
        }
        std::string get_outfile()
        {
            return this->outfile;
        }

        
    

};





/*
 * Prints a welcome text message to the game 
 */
void welcome();

/*
 * Prints a help message if the "-h" input spec has been detected
 */
void print_help();













#endif