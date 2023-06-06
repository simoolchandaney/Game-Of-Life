# Conway's Game of Life

Conway's Game of Life is an early example of a cellular automaton which can be easily simulated on a computer. A cellular automaton consists of a large number of cells, each operating according to some simple local rules. Given a large enough number of cells and an interesting initial configuration, non-trivial emergent behavior can result.

Rules: a dead cell with exactly 3 neighbors becomes live; and only a live cell with 2 or 3 neighbors survives, all others die.

The program is designed to run in two possible modes: interactive and batch.

The mode chosen will be determined by how the program is run:

1) interactive mode: this mode will be triggered when the program is executed with no command line arguments
Initially, the program sets up a completely blank board; it should then ask the user for input:
If the user enters:
a , followed by two integers: they will represent the coordinates where to add a new live cell (no action needed if cell is already alive).
r , followed by two integers: remove a cell from the cell with those coordinates (no action needed if cell is already dead).
n : advance the simulation to the next iteration by applying the rules of the game.
q : quit the program.
p : play the game continuously (forever, without asking for more input; you can press control-C to stop the program).

2) batch mode: this mode will be triggered if the executable is followed by a data file.
The data file will consist of a sequence of commands (see above) followed by a "p". Lines starting with an "a" or an "r" will be followed by two numbers (representing a cell's location). A typical data file (scene) will most likely consist of just "a" lines (an a followed by two integers), ending with a solo "p" line at the end.
In this batch mode, the program will play the scene continuously.
All data files will definitely have a "p" as the last line; and that all scene files are always valid and correct.

Example usage:

  - playlife              -->  Game of Life in interactive mode
  - playlife glider.txt   -->  Game of Life in batch mode, using that scene

5 scenes that demonstrate a wide variety of complex automata behavior within Life:

scene1.txt  shows four different "still life" objects that do not change as time passes.
scene2.txt  shows four different "oscillators" that progress through two or more stages, but always return to the same shape.
scene3.txt  shows four different objects that move across the screen in different directions.
scene4.txt  shows an "explosion" that creates a large amount of initial activity, but then settles down into still life, oscillators, or nothing.
scene5.txt  shows something unusual or unexpected.

Note: If the user enters an invalid option he will be prompted an error message and the menu once again so that he makes a valid choice
In batch mode the user must enter both the executable name and the name of a text file in the directory with contains a set of commands that will amke the board do different things for an infinite amount of time (i.e. in p mode). The user must enter a valid text file name (will be prompted that it does not exist if not), and will only be able to quit the program with control C.

Files: lifefunc.h, lifefunc.c, and playlife.c (resp., the header, functions file, and main driver)
From the programmer's perspective this the lab subdirectory contains 5 main features:
1. main program: includes all libraries in the header that will be needed for the program (including the function header file to access the function prototypes and the struct). It declares a dead cell (i.e. a space on the board) as a constant. Main will have as an input argc and argv which will count and store in an array (respectively) the inputs entered in the command line. If the user just enters the executable it will go in interactive mode. Here there is a while loop that will run until the user enters q when prompted to do so (the user's choice is scanned in as a char). The while loop allows the menu and board to be displayed after each option the user chooses. An if-else statement is used to offer aternatives regarding the option entered (i.e. if q quit program, if not see options). Thus, the lese statement has a switch statement executing each option. If the option entered is a or r the program scans in the 2 integers followed by it, checks that the coordinates are within bounds and updates the cell in the board. If the user enters n the program calls new_board function that creates a temporary board in which the changes are not made in order to take into account the rules properly (the table is adequately displayes because of the print_board function in the while loop). If the user enters p the program will run continuously making infinite iterations thus we include the new_board and print_board functions (we also use system("clear") to just show 1 board on the screen, and usleep to make the simulation go slower). 
If the user enters the executable followed by the name of the text file the program opens it and checks that this file exits using an if statement. A struct that will store all the commands (I chose this because I found it more logical and tidy) is then created and is inputed to the read_mode funtion that will read in all the commands from the txt file and store them in the struct. Then I basically used the same thing I had for the p option in interactive mode so that it ran infinitely.
2. functions program: includes necessary libraries including function header with prototypes, and declares extern const char space to access the global variable space from the main program. 
functions:
create_board: creates a 40X40 board with all spaces (i.e. empty) using a nested for loop.
print_bopard: uses a for loop to print the top line of - and later bottom, a nested for loop to print the content of the board (which is stored in the array board[]) with | on the right and left side of the board (to make it seem like a board)
showmenu: shows the user all the options he has to choose from
new_board: creates a temporary board from which the program will check the neighbors of each cell to decide whethert it will live or not when the user enters n or p. a nested for loop copies the intial board onto it. a "quadruple-nested" for loop goes through each cell and checks the quantity of neighbors through an if statement and whethe the cell being checked is in bounds and updates it according to the game rules.
check: checks whether the cell is within the boundaries (if statement)
check2: checks whether the coordinates inputted by the user are within boundaries (if-else statement). returns appropriate message if it is not. 
read_mode: reads in each command from the txt file (i.e each line) as a char, int and int and stores them in a struct created in the function prototype until the char read in is p (use of while loop). then an if-else if statement is used to make the appropriate change on the board if the command starts with a or r.
3. functions header: declares the size of the board to be a maximum of 40 as a global. also declares a strcuct that will be used in the function to store the commands as a global. and of course it has all the function declarations
4. Make file: generates executables as editted and as clean functionality
5. scenes text files
