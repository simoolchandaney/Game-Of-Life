// SIMRAN MOOLCHANDANEY
// OCTOBER 12
// SECTION 01
// lifefunc.h
// function definitions for Game of Life

#include <stdio.h>
#include "lifefunc.h" // grants access to function prototype, board size and struct defined as globals

extern const char space; // grants access to space character defined as a global in main 

void create_board(char board[][SIZE], int size) {
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			board[i][j] = space;
		}
	}
} // initializes the board to all spaces 

void print_board(char board[][SIZE], int size) {
	int i;
	int j;
	int k;
	for (i = 0; i < (size+2); i++) {
		printf("-");
	}
	printf("\n");
	for (j = 0; j < size; j++) {
		printf("|");
		for (k = 0; k < size; k++) {
			printf("%c", board[j][k]);
		}
		printf("|");
		printf("\n");
	}
	for (i = 0; i < (size+2); i++) {
		printf("-");
	}
	printf("\n");
} // prints the board with the corresponding borders and with the elemenet that is in each cell 

void showmenu() {
	printf("\n");
	printf("choose one of the following options:\n");
	printf("\"a\", followed by 2 integers which will be the coordinates wherre to add a new live cell\n");
	printf("\"r\", followed by 2 integers which will be the coordinates of the cell you want to remove\n");
	printf("\"n\" to advance the simulation to the next iteration by applying the rules of the game\n");
	printf("\"q\" to quit the program\n");
	printf("\"p\" to play the program forever\n");
} 

void new_board(char board[][SIZE], int size) {
	// use for n and p
	// creates temporary board in which we check the rules of the game and update the original board correspondingly 
	char temp_board[SIZE][SIZE];
	int i, j;
	for (i = 0; i < size; i++) { // intializing temp board to original board
		for (j = 0; j < size; j++) {
			temp_board[i][j] = board[i][j];
		}
	}
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			int neighbor = 0;
			int k, l;
			for (k = -1; k <= 1; k++) {
				for (l = -1; l <= 1; l++) {
					if ((check(i+k,j+l) == 1) && (k !=0 || l != 0)) {
						if (temp_board[i+k][j+l] == 'X') {
						neighbor++;
						}
					}
				}
			}
			// rules of the game
			if ((neighbor < 2) || (neighbor > 3)) {
				board[i][j] = space;
			}
			else if (neighbor == 3) {
				board[i][j] = 'X';
			}
			else if (neighbor == 2) {
				board[i][j] = temp_board[i][j];
			}
		}
	}
}

int check(int x, int y) { // makes sure that the coordinates are in the range of the board when checking for neighbors
	if ((x >= 0) && (x < SIZE) && (y >= 0) && (y < SIZE)) {
		return 1;
	}
	return 0;
}

int check2(int x, int y) { // makes sure that the coordinates are in the range of the board when getting one from the user (options a and r)
	if ((x >= 0) && (x < SIZE) && (y >= 0) && (y < SIZE)) {
		return 1;
	}
	else {
		printf("(%d, %d) is out of the board bounds\n", x, y);
	}
	return 0;
}

// function to read in commands from text file for batch mode
void read_mode(FILE *fp, char board[][SIZE], Mode arr[]) {
	int n = 0;
	while (arr[n].opt != 'p') { // will read in all commands till before p
		fscanf(fp, "%c %d %d", &arr[n].opt, &arr[n].x, &arr[n].y);
		if (arr[n].opt == 'a') {
			if ((check(arr[n].x,arr[n].y) == 1) && (board[arr[n].x][arr[n].y] != 'X')) {
			board[arr[n].x][arr[n].y] = 'X';
			}
		}
		else if (arr[n].opt == 'r') {
			if ((check(arr[n].x,arr[n].y) == 1) && (board[arr[n].x][arr[n].y] != space)) {
			board[arr[n].x][arr[n].y] = space;
			}	
		}
	}
}





				


	

