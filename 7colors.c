/* Template of the 7 wonders of the world of the 7 colors assigment. */

#include <stdio.h>     /* printf */
#include <time.h>
#include <stdlib.h>

/* We want a 30x30 board game by default */
#define BOARD_SIZE 30
#define COLOR_NUMBER 7
#define DOWN_LEFT_PLAYER 'v'
#define TOP_RIGHT_PLAYER '^'
#define EMPTY 0

/** Represent the actual current board game
 *
 * NOTE: global variables are usually discouraged (plus encapsulation in
 *     an appropriate data structure would also be preferred), but don't worry.
 *     For this first assignment, no dinosaure will get you if you do that.
 */
char board[BOARD_SIZE * BOARD_SIZE] = { 0 }; // Filled with zeros

struct cell
{
    int x;
    int y;
};

typedef struct cell cell;



/** Retrieves the color of a given board cell */
char get_cell(cell c)
{
	if (c.x >= 0 && c.x < BOARD_SIZE &&
		c.y >= 0 && c.y > BOARD_SIZE)
	{
		return board[c.y * BOARD_SIZE + c.x];
	}
	else {
		return EMPTY;
	}
}

/** Changes the color of a given board cell */
void set_cell(cell c, char color)
{
    board[c.y * BOARD_SIZE + c.x] = color;
}

/** Prints the current state of the board on screen
 *
 * Implementation note: It would be nicer to do this with ncurse or even
 * SDL/allegro, but this is not really the purpose of this assignment.
 */
void print_board(void)
{
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c", get_cell(i, j));
        }
        printf("\n");
    }
}

void initialize_random(void)
{
    srand(time(NULL));
}

/** Return number is in [a, b[ */
int get_random_number_between(int a, int b)
{
    return rand() % (b - a) + a;
}

char get_color(size_t id)
{
    return id + 'A';
}

char get_player_of_starting_cell(cell c)
{
   if (c.x == 0 && c.y == 0)
        return DOWN_LEFT_PLAYER;
   if (c.x == BOARD_SIZE - 1 && c.y == BOARD_SIZE - 1)
        return TOP_RIGHT_PLAYER;
    return EMPTY;
}

void initialize_board(void)
{
    char player;
    cell current_cell;
    for (int i = 0; i < BOARD_SIZE ; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            current_cell.x = i;
            current_cell.y = j;
            player = get_player_of_starting_cell(current_cell);
            if (player == EMPTY)
                set_cell(i, j, get_color(get_random_number_between(0, 7)));
            else
                set_cell(i, j, player);
        }
    }
    
}

/** Program entry point */
int main(void)
{
    printf("\n\nWelcome to the 7 wonders of the world of the 7 colors\n"
	   "*****************************************************\n\n"
	   "Current board state:\n");
    initialize_random();
    initialize_board();

    print_board();

    return 0; // Everything went well
}
