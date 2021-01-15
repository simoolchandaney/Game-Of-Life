// SIMRAN MOOLCHANDANEY
// SECTION 01
// OCTOBER 12
// lifefunc.h
// function prototypes for Game of Life

#define SIZE 40
typedef struct {
	char opt;
	int x;
	int y;
} Mode; // will store option and coordinates from txt file 

void create_board(char[][SIZE], int);
void print_board(char[][SIZE], int);
void showmenu();
void new_board(char [][SIZE], int);
int check(int, int);
int check2(int, int);
void read_mode(FILE *, char [][SIZE], Mode []); 
