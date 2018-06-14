/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			battleship.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include <stdio.h>
#include "battleship.h"

CellContent my_field[FIELDSIZE][FIELDSIZE];
CellContent opposite_field[FIELDSIZE][FIELDSIZE];
CellContent my_guesses[FIELDSIZE][FIELDSIZE];

void load_game(){
FILE* my_file = fopen("battleship.my", "r");
FILE* opposite_file = fopen("battleship.op", "r");

for (int i = 0; i < FIELDSIZE; i++) {
  for (int j = 0; j < FIELDSIZE; j++) {
    fread(&my_field[i][j], sizeof(CellContent), 1, my_file);
    fread(&opposite_field[i][j], sizeof(CellContent), 1, opposite_file);
    my_guesses[i][j] = Unknown;
  }
}
fclose(my_file);
fclose(opposite_file);
}

CellContent get_shot(int row, int col){
  if (row < 0 || row > 9 || col < 0 || col > 9) {
    return OutOfRange;
  }
  else return my_field[row][col];
}

bool shoot(int row, int col){
  CellContent my_guess = get_my_guess(row, col);
  if (my_guess == OutOfRange ||row< 0 || row > 9 || col < 0 || col > 9) {
    return false;
  }
  else if (opposite_field[row][col] == Water || opposite_field[row][col] == Boat ) {
    my_guesses[row][col] = opposite_field[row][col];
    if (my_guesses[row][col] == Boat) {

      for (int i = row-1; i < row+2; i++) {
        for (int j = col-1; j < col+2; j++) {
          my_guess = get_my_guess(i, j);
          if (my_guess == Unknown) {
            my_guesses[i][j] = Water;
          }
        }
      }
    }
  }
return true;
}

CellContent get_my_guess(int row, int col){
  if (row < 0 || row > 9 || col < 0 || col > 9) {
    return OutOfRange;
  }
else return my_guesses[row][col];
}
