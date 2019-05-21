#include "../include/out_put.h"

#include "../include/canvas.h"
#include "../include/common.h"
#include "../include/lodepng.h"
#include <sstream>


void out_put::print_out_stream(std::ostream & os, Life life, char alive_char, char dead_char){

    for (int y =0; y< life.get_height(); y++)
    {
        for (int x =0; x< life.get_lenght(); x++)
        {
            if (life.Cells[y][x].alive)
            {
                os<< alive_char;
            }
            else
            {
                os<< dead_char;
            }
            if (x == life.get_lenght() - 1)
            {
                os <<std::endl;
            }
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
void out_put::print_out_image( const Life life){

    life::Canvas canvas(life.get_lenght(),life.get_height(),this->options.get_blocksize());

    for (int y = 0; y< life.get_height(); y++){
        for (int x = 0; x < life.get_lenght(); x++){
            
            if (life.Cells[y][x].alive){
                canvas.pixel(life::Point2(x,y), options.get_alivecolor());
            }else{
                canvas.pixel(life::Point2(x,y), options.get_bkgcolor());
            }
        
        }
    }

    std::stringstream path;
    
    path << options.get_imgdir() <<"Generation "<< life.all_generations.size()<<".png";

    encode_png(  path.str().c_str() , canvas.pixels(), canvas.width(), canvas.height());
    path.clear();
}

