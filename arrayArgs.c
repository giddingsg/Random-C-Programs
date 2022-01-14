//Author: Garrett Giddings | Date: 6/7/2020
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROWS 10
#define COLUMNS 10
#define SPACE '.'

#define MOVES 4
#define LEFT 0
#define DOWN 1
#define UP 2
#define RIGHT 3

#define N 10

void generate_random_walk(char walk[N][N]);  //prototype of the first function
void print_array(char walk[N][N]);  //prototype of the second function

int main(void)
{
    char walk[N][N];

    srand((unsigned) time(NULL));
    generate_random_walk(walk);
    print_array(walk);

    return 0;
}

void generate_random_walk(char walk[N][N]) {
    char letter;
    bool potential_move[MOVES];
    int i, row, column, count, cMove;
    srand((unsigned) time(NULL));

    for (row = 0; row < ROWS; row++) {
        for (column = 0; column < COLUMNS; column++) {
            walk[row][column] = SPACE;
        }
    }

    row = 0; column = 0;
    for (letter = 'A'; letter <= 'Z'; letter++) {
        walk[row][column] = letter;

        for (i = 0; i < MOVES; potential_move[i] = false, i++);
        count = 0;
        if (column-1 >= 0 && walk[row][column-1] == SPACE) {
            potential_move[LEFT] = true;
            count++;
        }
        if (row+1 < ROWS && walk[row+1][column] == SPACE) {
            potential_move[DOWN] = true;
            count++;
        }
        if (row-1 >= 0 && walk[row-1][column] == SPACE) {
            potential_move[UP] = true;
            count++;
        }
        if (column+1 < COLUMNS && walk[row][column+1] == SPACE) {
            potential_move[RIGHT] = true;
            count++;
        }
        if (count == 0)
            break;

        while (true) {
            cMove = rand() % MOVES;
            if (potential_move[cMove] == true) {
                switch(cMove) {
                    case LEFT:  column--;
                        break;
                    case DOWN:  row++;
                        break;
                    case UP:    row--;
                        break;
                    case RIGHT: column++;
                        break;
                }
                break;
            } else {
                continue;
            }
        }
    }
    printf("\n");
}

void print_array(char walk[N][N]) {
    int rowP, columnP;
    for (rowP = 0; rowP < N; rowP++) {
        for (columnP = 0; columnP < N; columnP++) {
            printf("%2c", walk[rowP][columnP]);
        }
        printf("\n");
    }
}