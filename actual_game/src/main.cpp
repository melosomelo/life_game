#include <iostream>
#include <string>
#include "../include/ioput.h"
#include "../include/life.h"

int main(int argc, char* argv[])
{
    ioput test;
    test.check_cmd_line_specs(argv, argc);
    test.print();
    
     
    
}


