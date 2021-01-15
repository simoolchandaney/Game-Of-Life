// SIMRAN MOOLCHANDANEY
// SECTION 01
// OCTOBER 12
// playlife.c
// main program for game of life

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "lifefunc.h" // has function prototypes, maximum size of the board and struct to store what is in the text files for the batch mode declared as globals

const char space = ' ';

int main(int argc, char *argv[]) {
	char option[2]; 
	char x;
	// want a single character for the command
	char board[SIZE][SIZE]; 
	int xp, yp; // coordinates inputted by the user for options a and r of interactive mode
	bool done = false;
	create_board(board, SIZE);
	if (argc == 1) {
		// interactive mode
		print_board(board, SIZE);
		while (!done) {
			showmenu();
			printf("option chosen: ");
			scanf("%s", &option); 
			if (strlen(option) > 1) {
				printf("command %s is too long; good bye\n", option); // ensures that character entered for command mode is a single one
				return 1;
			}
			x = option[0]; 
			if (x == 'q') {
				printf("good bye\n"); // option q, quits the program
				done = true;
			}
			else {
				switch (x) {
					case 'a':
						scanf("%d %d", &xp, &yp);
						if ((check2(xp,yp) == 1) && (board[xp][yp] != 'X')) {
							board[xp][yp] = 'X';
						}
						print_board(board, SIZE); // the printed board will have an X added in the position indicated by the user
						break;
					case 'r':
						scanf("%d %d", &xp, &yp);
						if ((check2(xp,yp) == 1) && (board[xp][yp] != space)) {
							board[xp][yp] = space;
						}
						print_board(board, SIZE); // the board printed will have a space added in the position indicated by the user 
						break;
					case 'n':
						new_board(board, SIZE);
						print_board(board, SIZE); // advances 1 step in the iteration 
						break;
					case 'p':
						while (1) {
							new_board(board, SIZE);
							system("clear"); // only 1 board will be shown
							print_board(board, SIZE);
							usleep(100000); // makes simulation go slower
						}
						// infinite loop, only exited with control C
						break;
					default:
					fflush(stdin);
					printf("your input is invalid, chose again\n"); // if character entered is invalid
						break;
				}
			}
		}
	}
	if (argc == 2) {
		// batch mode
		// read in file
		FILE *fp = fopen(argv[1], "r"); // opens text file if it exits
		if (!fp) {
			printf("file %s not found\n", argv[1]);
			return 1;
		}
		Mode mode_arr[100]; // the maximum number of commands a text file can have is 100
		read_mode(fp, board, mode_arr);
		while (1) {
			new_board(board, SIZE);
			system("clear");
			print_board(board, SIZE);
			usleep(100000);
			// in p mode so infinite loop, only exited with control C
		}
	}
	return 0;
}

