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

#define FIELD { \
	{	Water,	Water,	Water,	Water,	Water,	Water,	Water,  Water,  Water,  Water}, \
	{	Water,	Water,	Water,	Water,	Water, 	Water, 	Water,  Water,  Water,  Water}, \
	{	Water,  Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water}, \
	{	Water,	Water,	Water,	Water,	Water,	Water,   Water,	Water,	Water,	Water}, \
	{	Water,  Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water}, \
	{	Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water}, \
	{	Water,  Water, Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water}, \
	{	Water,  Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water}, \
	{	Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water,   Water,  Water}, \
	{	Water,  Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water}  \
}

#define GUESS_FIELD{ \
	{	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown}, \
	{	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown}, \
	{	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown}, \
	{	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown}, \
  {	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown}, \
  {	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown}, \
  {	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown}, \
  {	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown}, \
  {	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown}, \
  {	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown,	Unknown}, \
}

static CellContent my_field[FIELDSIZE][FIELDSIZE] = FIELD;
static CellContent opposite_field[FIELDSIZE][FIELDSIZE] = FIELD;

static CellContent my_guesses[FIELDSIZE][FIELDSIZE] = GUESS_FIELD;

void load_game(){
FILE* my_file = fopen("battleship.my", "r+");
FILE* opposite_file = fopen("battleship.op", "r+");

for (int i = 0; i < FIELDSIZE; i++) {
  fwrite(my_field[i], sizeof(CellContent), FIELDSIZE, my_file);
  fwrite(opposite_field[i], sizeof(CellContent), FIELDSIZE, opposite_file);
}

fclose(my_file);
fclose(opposite_file);
}

/**
*** @param row The row where we get the shot.
*** @param col The col where we get the shot.
*** @return The value of cell indicated by row and column of the own field (filled
*** with the values of battleship.my). If row/col point outside the field the
*** value OutOfRange is returned.
*/
CellContent get_shot(int row, int col){
  if (row < 0 || row > 9 || col < 0 || col > 9) {
    return OutOfRange;
  }
return my_field[col][row];
}

/**
*** Sets the row and column of the my guesses table to the value held in the
*** opponents field. If this is a Water all surrounding cells are marked as water.
*** @param row The row where we place the shot
*** @param col The columnt where we place the shot.
*** @return True if target field is valid, i.e., inside the field, False otherwise.
*/
bool shoot(int row, int col){
  if ((row< 0 || row > 9) || (col < 0 || col > 9)) {
    return false;
  }

return false;
}

/**
*** @param row The row where we want to get our own guess.
*** @param col The column where we want to get our own guess.
*** @return The value of the table with my guesses at row and column. If row/col
*** is outside the field OutOfRange is returned.
*/
CellContent get_my_guess(int row, int col){
  if (row < 0 || row > 9 || col < 0 || col > 9) {
    return OutOfRange;
  }
return my_guesses[row][col];
}
