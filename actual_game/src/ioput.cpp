#include "../include/ioput.h"
#include "../include/canvas.h"
#include "../include/common.h"
#include "../include/lodepng.h"


Life ioput::read_input()
{
    int height, lenght; //dimensions of the cell grid
    std::ifstream input_specs; //file from which we will read the specs
    std::string line; //string to store lines from the file 
    char alive_char;
    input_specs.open(this->infile);
    input_specs >> height >> lenght;
    Life grid(height, lenght); //initializing the new object
    input_specs >> alive_char; 
    for(int i = 0 ; i < height; i++)
    {
        std::getline(input_specs, line);

        for(int j = 0; j < line.size(); j++)
        {
            if(line[j] == alive_char)
            {
                grid.Cells[i+1][j+1].alive = true;
                grid.current.living_cells.push_back(grid.Cells[i+1][j+1]);
            }
        }

        
    }
    grid.current.generation_number = 0;
    grid.current.state = Running;
    return grid;

}

life::Color ioput::determine_color(std::string color)
{
    if(color == "BLACK")
        return life::BLACK;
    else if(color == "BLUE")
        return life::DEEP_SKY_BLUE;
    else if(color == "CRIMSON")
        return life::CRIMSON;
    else if(color == "DARK_GREEN")
        return life::DARK_GREEN;
    else if(color == "DEEP_SKY_BLUE")
        return life::DEEP_SKY_BLUE;
    else if(color == "DODGER_BLUE")
        return life::DODGER_BLUE;
    else if(color == "GREEN")
        return life::GREEN;
    else if(color == "LIGHT_BLUE")
        return life::LIGHT_BLUE;
    else if(color == "LIGHT_GREY")
        return life::LIGHT_GREY;
    else if(color == "LIGHT YELLOW")
        return life::LIGHT_YELLOW;
    else if(color == "RED")
        return life::RED;
    else if(color == "STEEL_BLUE")
        return life::STEEL_BLUE;
    else if(color == "WHITE")
        return life::WHITE;
    else if(color == "YELLOW")
        return life::YELLOW;
    else
    {
        std::cout << ">>>>COLOR NOT FOUND. SETTING COLOR TO DEFAULT...\n";
        return this->bkgcolor;
    }
    
}

void ioput::check_cmd_line_specs(char* argv[], int argc)
{
    bool skip = false;
    for(int i = 1; i < argc; i++)
    {
        std::string str_test = argv[i];
        if(skip)
        {
            skip = false;
            continue;
        }
        if(str_test == "--help")
        {
            this->help = true;
        }
        else if(str_test=="--imgdir")
        {
            this->imgdir = argv[i+1];
            skip = true;
        }
        else if(str_test=="--maxgen")
        {
            this->maxgen = std::atoi(argv[i+1]);
            skip = true;

        }
        else if(str_test == "--fps")
        {
            this->fps = std::atoi(argv[i+1]);
            skip = true;

        }
        else if(str_test == "--blocksize")
        {
            this->blocksize = std::atoi(argv[i+1]);
            skip = true;
        }
        else if(str_test == "--bkgcolor")
        {
            std::string color = argv[i+1];
            this->bkgcolor = determine_color(color);
            skip = true;
        }
        else if(str_test == "--alivecolor")
        {
            std::string color = argv[i+1];
            this->alivecolor = determine_color(color);
            skip = true;
        }
        else if(str_test == "--outfile")
        {
            this->outfile = argv[i+1];
            skip = true;
        }
        else
        {
            this->infile = argv[i];
        }
        
        
    }

    
}

void encode_png(const char* filename, const unsigned char * image, unsigned width, unsigned height)
{
    //Encode the image
    unsigned error = lodepng::encode(filename, image, width, height);

    //if there's an error, display it
    if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
}

void ioput::paint_canvas(life::Canvas &image, Life &game, int counter)
{

    life::Color alive_color = this->alivecolor;
    life::Color bkg = this->bkgcolor;
    std::string temporary = this->imgdir;
    temporary += "Generation";
    temporary += std::to_string(counter);
    temporary += ".png";
    const char* filename = temporary.c_str();
    for(auto x (0u); x < game.get_lenght(); x++)
    {
        for(auto y (0u); y < game.get_height(); y++)
        {
            if(game.Cells[y+1][x+1].alive)
                image.pixel(life::Point2(x,y), this->alivecolor);
            else
                image.pixel(life::Point2(x,y), this->bkgcolor);

        }
    }
    encode_png(filename, image.pixels(), image.width(), image.height());

}

void ioput::print() //this is a test function to test if the specs are being captured. It will be deleted later.
{
    std::cout << "HELP IS " << this->help << std::endl
              << "IMGDIR IS " << this->imgdir << std::endl
              << " MAXGEN IS " << this->maxgen << std::endl
              << " FPS IS" << this->fps << std::endl
              << " BLOCKSIZE IS " << this->blocksize << std::endl
              << " OUTFILE IS " << this->outfile << std::endl;

}



void print_help()
{
    std::cout << "Usage: glife [<options>] <input_cfg_file> \n"
              << "  Simulation options: \n"
              << "     --help Print this help text.\n"
              << "     --imgdir <path> Specify directory where output images are written to. \n"
              << "     --maxgen <num> Maximum number of generations to simulate.\n"
              << "     --fps <num> Number of generations presented per second.\n"
              << "     --blocksize <num> Pixel size of a cell. Default = 5.\n"
              << "     --bkgcolor <color> Color name for the background. Default GREEN.\n"
              << "     --alivecolor <color> Color name for representing alive cells. Default RED.\n"
              << "     --outfile <filename> Write the text representation of the simulation\n"
              << "     to the given filename.\n"
              << "  Available colors are:\n"
              << "      BLACK BLUE CRIMSON DARK_GREEN DEEP_SKY_BLUE DODGER_BLUE \n"
              << "      GREEN LIGHT_BLUE LIGHT_GREY LIGHT_YELLOW RED STEEL_BLUE \n"
              <<"       WHITE YELLOW \n";

}

