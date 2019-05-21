#ifndef OUT_PUT_H
#define OUT_PUT_H

#include <iostream>
#include <string>
#include "../include/common.h"

#include "ioput.h"

class out_put{


    public:
    ioput options;

    out_put(ioput options) :options{options} 
    {/*Empty*/};


    void print_out_stream (std::ostream & os, Life life, char alive_char, char dead_char);

    void print_out_image (const Life life);

    


};


#endif