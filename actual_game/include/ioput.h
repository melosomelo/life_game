#ifndef INPUT_H
#define INPUT_H
#include "life.h"
#include "cell.h"
#include "generation.h"
#include <fstream>
#include <iostream>



/*
 * Reads a .txt file that stores the specs of the size of the grid and its distribution
 * of living and dead cells.
 * \return A Life object that will manage the Life Game Simulatiln
 */
Life read_input();


void welcome();

void print_terminal_grid();








#endif