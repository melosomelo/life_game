#include "cell.h"
#include "generation.h"
#include "life.h"
#include <vector>
#include <iostream>

//THIS IS ONLY A TESTING FILE TO TEST THE STRUCTS THAT WE'VE BEEN MAKING
//USE IT AT YOUR OWN WILL BUT MAKE SURE TO LEAVE SOME COMMENTS TO WHAT YOU'RE TESTING

int main()
{
    Generation g01;
    //Testing constructors of the Cell Struct
    Cell c01;
    c01.x = 5;
    c01.y = 2;
    Cell c02;
    c02.x = 5;
    c02.y = 2;
    //Testing the living cells vector
    g01.living_cells.push_back(c01);
    g01.living_cells.push_back(c02);
    Generation g02;
    g02.living_cells.push_back(c01);
    g02.living_cells.push_back(c02);
    //Testing the == operator among Generations (its working)
    auto result = g02 == g01;
    //Initializing the Life Struct (maybe will turn it into a Class later on)
    Life test(3,3);
    //testing the << operator 
    std::cout << test;
    std::cout << std::endl;
    //Setting up some stats to test the check_surroundings function
    test.Cells[2][2].alive = true;
    test.Cells[1][2].alive = true;
    test.Cells[2][3].alive = true;
    test.Cells[3][2].alive = true;
    test.Cells[2][1].alive = true;
    test.check_surroundings(test.Cells[2][2]);
    //using the << operator to compare the stats of both generations.
    std::cout << test;



}