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



/*!
\class ioput
A class that's in charge of taking care of all inputs, such as files, and outputting everything that is required,
such as .mp4 and .txt files as well as the cmd line output.
*/

class ioput
{
    private:
        bool help; /*!<Signals if the user wants to print the help text*/
        std::string imgdir; /*!<The directory in which the images will be store*/
        int maxgen; /*!<The max number of generation simulations. Default is = - 1, since it will have none*/
        int fps; /*!<The number of frame per seconds. Default = 1*/
        int blocksize;/*!<Cellsize(in pixels) in the .mp4 file. It will determine a square in the .mp4 file with the. Default = 5 */
        life::Color bkgcolor;/*!<Background color of the .mp4 file. See common.h library. Default = GREEN*/
        life::Color alivecolor;/*!<Color of the alive cell block. Deafault = RED*/
        std::string outfile;/*!<Outfile name of the simulation output*/
        std::string infile;/*!<File from which we will read the specs of the cell grid. Default = specs.txt*/
    public:
        /*!
        \brief Regular destructor
        */
        ~ioput(){/*empty*/}
        /*!
        \brief Default constructor with the default parameters already set.
        */
        ioput(): help(false), imgdir("null"), maxgen(-1), fps(1), blocksize(5), bkgcolor(life::GREEN), alivecolor(life::RED), outfile("simulation.txt"), infile("specs.txt")
        {/*empty*/}

        /*!
        Reads the input from the infile attribute and sets the grid of the cells. 
        In order it reads the dimensions of the grid, the ammount of lines and columns, the alive character that will be read in the next line to signal a living cell
        and the state of the following lines. Any character that is different from the one specified will be considering a dead cell.
        @return A Life object with the grid as specified.
        */

        Life read_input();

        /*!
        Reads the command line arguments and sets all of them to different ones, if specified. If not, the default ones will remain.
        If the user inputs a wrong argument, it will be interpreted as the infile, resulting in an error.
        */
        void check_cmd_line_specs(char* argv[], int argc);
        
        /*!
        \brief A separate function to determine the color of the background and the alivecolor
        */
        life::Color determine_color(std::string color);

        void print();

        /*!
        @return The help attribute.
        */
        bool get_help()
        {
            return this->help;
        }

        /*!
        @return The imgdir attribute.
        */
        
        std::string get_imgdir()
        {
            return this->imgdir;
        }
        /*! 
        @return The maxgen attribute.
        */

        int get_maxgen()
        {
            return this->maxgen;
        }
        /*!
        @return the fps attribute.
        */

        int get_fps()
        {
            return this->fps;
        }
        /*!
        @return The blocksize attribute.
        */

        int get_blocksize()
        {
            return this->blocksize;
        }

        /*!
        @return The bkgcolor attribute.
        */
        life::Color get_bkgcolor()
        {
            return this->bkgcolor;
        }

        /*!
        @return The alivecolor attribute
        */
        life::Color get_alivecolor()
        {
            return this->alivecolor;
        }
        /*!
        @return The outlife attribute
        */
        std::string get_outfile()
        {
            return this->outfile;
        }
        /*!
        @return the infile attribute
        */
        std::string get_infile()
        {
            return this->infile;
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