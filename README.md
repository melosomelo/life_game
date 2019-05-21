# life_game
Project made by [melosomelo](https://github.com/melosomelo) and [DougAlves](https://github.com/DougAlves).
# Introduction

This is a **C++** implementation of the [Conway's Game Of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life). It reads specifications of the simulation from the command line and/or from a **.txt** file and outputs a the resulting simulation in a **.txt** file, a series of **.png** imagens and in a **.mp4** video.

# The Algorithm

Our simulation algorithm consists of analysing a specific state of a generation of cells and determine the next state of each single cell. This analysis is made by following the rules of this game. 

The game can end if all the cells have died (**Extinct**), if the current generation has already occured (**Stable**) and if the **max_gen** number that was specified by the user was achieved within running time.

# The Infrastructure 

Our code was made by using three structs and one class. Each single one of them represents an important agent in this simulation and will be further detailed in the **doxygen** documentation of this code. 

## Cell 
Represents the actual Cell of the simulation. Has really few stats since it's only a very simple entity and it doesn't need to do anything else. 

## Generation 

A gathering of cells. Each generation is only defined by its living cells, because this way the algorithm becomes a lot more efficient.

## Ioput 

This class is in charge of reading all the input that the game might need (files and command line), and ouputting the necessary results, such as the needed for printing the **.png** file.

## Life 

Manages the whole simulation and controls it since it's in charge of running the main game functions, such as **update**, determining wether the game is over, etc...

# Compiling 

To compile this simulation you can use our `main.cpp` file that is ready and compile it through the following line of command: 

```
g++ main.cpp ioput.cpp life.cpp -o main 
```
You can also, when executing the `main` file, use command line arguments to specify some configurations, such as the directory in which you want to store images, the background color of the images, as well as the color of each living cells (**Check doxygen or execute ```./main --help```**).

Otherwhise, there is a `CMakeLists.txt` file avaible and to use it you need to type the following command line instructions:
```
mkdir build
cd build
cmake ..
make  
./game <arguments>
```

