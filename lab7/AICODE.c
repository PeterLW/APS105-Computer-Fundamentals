#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int movei, movej, tiecount = 0, **interestboard;
bool firstmove = true, firstmoveother = true;
//Coded by Oliver Wu 1000658709

//finds the total longest possible moves in all directions and adds them together
int findLongest(char **board, int n, int row, int col){
	int i = 0, j = 0, highest = 0, total, rowstart, colstart, totalhighest=0;
	char stone = board[row][col];
	bool same = true, starthere;
	if (board[row][col] == 'B' || board[row][col] == 'W'){
		stone = board[row][col]; //Sets the reference stone as the stone in the row
		//---------------------------------------------------------------------------
		//Will go up the row until stones are not the same
		for (int i = row, starthere = false; i >= 0 && starthere == false; i--){
			if (board[i][col] != stone){ //checks to see if row is the same as the stone
				rowstart = i + 1;
				starthere = true;
			}
			else
				rowstart = i;
		}
		//Program now goes down the row, counting the contiguous stones
		for (int i = rowstart, same = true, total = 0; i < n && same == true; i++){
			if (board[i][col] != stone){
				same = false;
			}
			else if (board[i][col] == stone){
				total++;
				if (highest <= total){
					highest = total;
				}
			}
		}
		totalhighest += highest;
		highest = 0;
		//---------------------------------------------------------------
		//Will check the col for same stone
		//Will go left to the col until stones are not the same
		for (int j = col, starthere = false; j >= 0 && starthere == false; j--){
			if (board[row][j] != stone){ //Checks to see if the col is same as the stone
				colstart = j + 1;
				starthere = true;
			}
			else
				colstart = j;
		}
		//Program now goes to the right of the col, counting the contiguous stones
		for (int j = colstart, total = 0, same = true; j < n && same == true; j++){
			if (board[row][j] != stone){
				same = false;
			}
			else if (board[row][j] == stone){
				total++;
				if (highest <= total){
					highest = total;
				}
			}
		}
		totalhighest += highest;
		highest = 0;
		i = 0;
		j = 0;
		//--------------------------------------------------------------------

		//program will now check diagonals, moving from top left, to bottom right
		//moves to top left to check for contiguous stones in that direction
		for (int i = row, j = col, starthere = false; i >= 0 && j >= 0 && starthere == false; i--, j--){
			if (board[i][j] != stone){ //Checks to see if the col is same as the stone
				colstart = j + 1;
				rowstart = i + 1;
				starthere = true;
			}
			else{
				colstart = j;
				rowstart = i;
			}
		}
		i = 0;
		j = 0;
		//program will start from the starting point and move down to the right to find longest contiguous stones
		for (int i = rowstart, j = colstart, total = 0, same = true; i < n && j < n && same == true; i++, j++){
			if (board[i][j] != stone){
				same = false;
			}
			else if (board[i][j] == stone){
				total++;
				if (highest <= total){
					highest = total;
				}
			}
		}
		totalhighest += highest;
		highest = 0;
		i = 0;
		j = 0;
		//-------------------------------------------------------------------------------------

		//Program will now check diagonals moving from top right, to bottom left
		//moves to top right to check for contiguous stones in that direction
		for (int i = row, j = col, starthere = false; i >= 0 && j < n && starthere == false; i--, j++){
			if (board[i][j] != stone){ //Checks to see if the col is same as the stone
				colstart = j - 1;
				rowstart = i + 1;
				starthere = true;
			}
			else{
				colstart = j;
				rowstart = i;
			}
		}
		i = 0;
		j = 0;
		//Program will start from starting point and move down tothe right to find the longest contiguous stone
		for (int i = rowstart, j = colstart, total = 0, same = true; i < n && j >= 0 && same == true; i++, j--){
			if (board[i][j] != stone){
				same = false;
			}
			else if (board[i][j] == stone){
				total++;
				if (highest <= total){
					highest = total;
				}
			}
		}
		totalhighest += highest;
		return totalhighest;
	}
	else
		return 0;
}
//finds the longest continuous stone
int findLongestbasic(char **board, int n, int row, int col){
	int i = 0, j = 0, highest = 0, total, rowstart, colstart, totalhighest = 0;
	char stone = board[row][col];
	bool same = true, starthere;
	if (board[row][col] == 'B' || board[row][col] == 'W'){
		stone = board[row][col]; //Sets the reference stone as the stone in the row
		//---------------------------------------------------------------------------
		//Will go up the row until stones are not the same
		for (int i = row, starthere = false; i >= 0 && starthere == false; i--){
			if (board[i][col] != stone){ //checks to see if row is the same as the stone
				rowstart = i + 1;
				starthere = true;
			}
			else
				rowstart = i;
		}
		//Program now goes down the row, counting the contiguous stones
		for (int i = rowstart, same = true, total = 0; i < n && same == true; i++){
			if (board[i][col] != stone){
				same = false;
			}
			else if (board[i][col] == stone){
				total++;
				if (highest <= total){
					highest = total;
				}
			}
		}
		//---------------------------------------------------------------
		//Will check the col for same stone
		//Will go left to the col until stones are not the same
		for (int j = col, starthere = false; j >= 0 && starthere == false; j--){
			if (board[row][j] != stone){ //Checks to see if the col is same as the stone
				colstart = j + 1;
				starthere = true;
			}
			else
				colstart = j;
		}
		//Program now goes to the right of the col, counting the contiguous stones
		for (int j = colstart, total = 0, same = true; j < n && same == true; j++){
			if (board[row][j] != stone){
				same = false;
			}
			else if (board[row][j] == stone){
				total++;
				if (highest <= total){
					highest = total;
				}
			}
		}
		i = 0;
		j = 0;
		//--------------------------------------------------------------------

		//program will now check diagonals, moving from top left, to bottom right
		//moves to top left to check for contiguous stones in that direction
		for (int i = row, j = col, starthere = false; i >= 0 && j >= 0 && starthere == false; i--, j--){
			if (board[i][j] != stone){ //Checks to see if the col is same as the stone
				colstart = j + 1;
				rowstart = i + 1;
				starthere = true;
			}
			else{
				colstart = j;
				rowstart = i;
			}
		}
		i = 0;
		j = 0;
		//program will start from the starting point and move down to the right to find longest contiguous stones
		for (int i = rowstart, j = colstart, total = 0, same = true; i < n && j < n && same == true; i++, j++){
			if (board[i][j] != stone){
				same = false;
			}
			else if (board[i][j] == stone){
				total++;
				if (highest <= total){
					highest = total;
				}
			}
		}
		i = 0;
		j = 0;
		//-------------------------------------------------------------------------------------

		//Program will now check diagonals moving from top right, to bottom left
		//moves to top right to check for contiguous stones in that direction
		for (int i = row, j = col, starthere = false; i >= 0 && j < n && starthere == false; i--, j++){
			if (board[i][j] != stone){ //Checks to see if the col is same as the stone
				colstart = j - 1;
				rowstart = i + 1;
				starthere = true;
			}
			else{
				colstart = j;
				rowstart = i;
			}
		}
		i = 0;
		j = 0;
		//Program will start from starting point and move down tothe right to find the longest contiguous stone
		for (int i = rowstart, j = colstart, total = 0, same = true; i < n && j >= 0 && same == true; i++, j--){
			if (board[i][j] != stone){
				same = false;
			}
			else if (board[i][j] == stone){
				total++;
				if (highest <= total){
					highest = total;
				}
			}
		}
		return highest;
	}
	else
		return 0;
}

int findLongestpossible(char **board, int n, int row, int col, char givenstone, char otherstone){
	int i = 0, j = 0, highest = 0, total, rowstart, colstart, totalhighest = 0;
	char stone = board[row][col];
	bool same = true, starthere;
	if (board[row][col] == 'B' || board[row][col] == 'W'){
		stone = board[row][col]; //Sets the reference stone as the stone in the row
		//---------------------------------------------------------------------------
		//Will go up the row until stones are not the same
		for (int i = row, starthere = false; i >= 0 && starthere == false; i--){
			if (board[i][col] != otherstone){ //checks to see if row is the same as the stone
				rowstart = i + 1;
				starthere = true;
			}
			else
				rowstart = i;
		}
		//Program now goes down the row, counting the contiguous stones
		for (int i = rowstart, same = true, total = 0; i < n && same == true; i++){
			if (board[i][col] == otherstone){
				same = false;
			}
			else if (board[i][col] != otherstone){
				total++;
				if (highest <= total){
					highest = total;
				}
			}
		}
		//---------------------------------------------------------------
		//Will check the col for same stone
		//Will go left to the col until stones are not the same
		for (int j = col, starthere = false; j >= 0 && starthere == false; j--){
			if (board[row][j] != otherstone){ //Checks to see if the col is same as the stone
				colstart = j + 1;
				starthere = true;
			}
			else
				colstart = j;
		}
		//Program now goes to the right of the col, counting the contiguous stones
		for (int j = colstart, total = 0, same = true; j < n && same == true; j++){
			if (board[row][j] == otherstone){
				same = false;
			}
			else if (board[row][j] != otherstone){
				total++;
				if (highest <= total){
					highest = total;
				}
			}
		}
		i = 0;
		j = 0;
		//--------------------------------------------------------------------

		//program will now check diagonals, moving from top left, to bottom right
		//moves to top left to check for contiguous stones in that direction
		for (int i = row, j = col, starthere = false; i >= 0 && j >= 0 && starthere == false; i--, j--){
			if (board[i][j] != otherstone){ //Checks to see if the col is same as the stone
				colstart = j + 1;
				rowstart = i + 1;
				starthere = true;
			}
			else{
				colstart = j;
				rowstart = i;
			}
		}
		i = 0;
		j = 0;
		//program will start from the starting point and move down to the right to find longest contiguous stones
		for (int i = rowstart, j = colstart, total = 0, same = true; i < n && j < n && same == true; i++, j++){
			if (board[i][j] == otherstone){
				same = false;
			}
			else if (board[i][j] != otherstone){
				total++;
				if (highest <= total){
					highest = total;
				}
			}
		}
		i = 0;
		j = 0;
		//-------------------------------------------------------------------------------------

		//Program will now check diagonals moving from top right, to bottom left
		//moves to top right to check for contiguous stones in that direction
		for (int i = row, j = col, starthere = false; i >= 0 && j < n && starthere == false; i--, j++){
			if (board[i][j] != otherstone){ //Checks to see if the col is same as the stone
				colstart = j - 1;
				rowstart = i + 1;
				starthere = true;
			}
			else{
				colstart = j;
				rowstart = i;
			}
		}
		i = 0;
		j = 0;
		//Program will start from starting point and move down tothe right to find the longest contiguous stone
		for (int i = rowstart, j = colstart, total = 0, same = true; i < n && j >= 0 && same == true; i++, j--){
			if (board[i][j] == otherstone){
				same = false;
			}
			else if (board[i][j] =! otherstone){
				total++;
				if (highest <= total){
					highest = total;
				}
			}
		}
		return highest;
	}
	else
		return 0;
}

//Prints array
void printBoard(char **board, int n, char stone){
	char otherstone;
	printf("\n");
	printf("   ");
	int i = 0, j = 0;
	for (int i = 0; i < n; i++){
		printf("%4d", i);
	}
	printf("\n");
	printf("    ");
	for (int i = 0; i < 4*n; i++){
		printf("_");
	}
	printf("\n");
	for (int i = 0; i < n; i++){
		printf(" %2d ", i);
		for (int j = 0; j < n; j++){
			printf("|");
			if (board[i][j] == 'B'){
				printf(" \u25FC ");
			}
			else if (board[i][j] == 'W'){
				printf(" \u25FB ");
			}
			else
				printf("   ", board[i][j]);
		}
		printf("|\n");
		printf("    ");
		for (int i = 0; i < 4 * n; i++){
			printf("_");
		}
		printf("\n");
	}
	printf("\n");
}
//creates array for multiple uses
int** createarray(int size, int value){
	int **board;
	board = (int**)malloc(size*sizeof(int*));	//Creates the pointers to the rows
	for (int i = 0; i < size; i++){	//Creates the pointers to the columns
		board[i] = (int*)malloc(size*sizeof(int));
	}
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			board[i][j] = value;//sets the board equal to the value specified by the program
		}
	}
	return board;
}
//wil imput board with coordinates with stone type and check the best score of human with recursion in each row:
int bestscorerow(char **board, int size, char stone, int i, int j){
	int rowscore = 0;
	int highestscore = 0;
	if (j == size){
		return 0; //should return nothing once reached end of the row
	}
	else{
		if (board[i][j] == 'W' || board[i][j] == 'B'){	//If space is occupied, the maximum size is 0 since it can't place there
			highestscore = 0;
			rowscore = bestscorerow(board, size, stone, i, j + 1);
		}
		else{		//will set set maximum to longest length on
			board[i][j] = stone;
			highestscore = findLongest(board, size, i, j);
			board[i][j] = 'U';
			rowscore = bestscorerow(board, size, stone, i, j + 1);
		}
		if (highestscore < rowscore){ //will compare the next column vs the current stone, if it is larger, then it will return the larger one
			highestscore = rowscore;
		}
		return highestscore;
	}
}
//compiles the highest scores from the bestscorerow function and sends them to the bestmove array
int highestrowscore(char **board, int size, char stone){
	//printf("In Function: highestrowscore");
	int highestscore = 0, current;
	for (int i = 0; i < size; i++){
		current = bestscorerow(board, size, stone, i, 0);
		if (highestscore < current){
			highestscore = current;
		}
	}
	return highestscore;
}

//offensive move chooser, makes move that is best for computer
void makemoveoff(char **board, int size, char stone){
	//printf("In Function: makemove\n");
	int **movearray = createarray(size, 0), largest, gap = 0;
	char otherstone;
	if (stone == 'B')
		otherstone = 'W';
	else
		otherstone = 'B';
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if (board[i][j] == 'U'){
				board[i][j] = stone;
				movearray[i][j] = findLongest(board, size, i, j) - highestrowscore(board, size, otherstone) + findLongestbasic(board, size, i, j);
				//printf("goodness is %d     ", findLongest(board, size, i, j));
				//printf("badness is %d\n", highestrowscore(board, size, otherstone));
				board[i][j] = 'U';
			}
			else{
				movearray[i][j] = -500;
				//printf("goodness DNE\n");
			}
		}
	}
	largest = movearray[0][0];
	movei = 0;
	movej = 0;
	//Will now find the largest number in the array and reccomend the best move for computer to play
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if (board[i][j] == 'U'){
				if (tiecount%3 == 1 || tiecount%3 == 2){
					if (largest <= movearray[i][j]){
						largest = movearray[i][j];
						movei = i;
						movej = j;
						gap++;
						//printf("The recommended move is %d %d\n", movei, movej);
					}
				}
				else{
					if (largest < movearray[i][j]){
						largest = movearray[i][j];
						movei = i;
						movej = j;
						gap++;
						//printf("The recommended move is %d %d\n", movei, movej);
					}
				}
			}
		}
	}
	//will print out the value of the move array
	/*for (int i = 0; i < size; i++){
	for (int j = 0; j < size; j++){
	printf(" %5d", movearray[i][j]);
	}
	printf("\n");
	}
	*/



	//Computer makes move
	board[movei][movej] = stone;
	printf("Computer lays a stone at ROW %d COL %d.\n", movei, movej);
	//will free the array in memory
	for (int i = 0; i < size; i++){
		free(movearray[i]);
	}
	free(movearray);

	return;
}
//defensive move chooser, makes move that is best for enemy
void makemovedef(char **board, int size, char stone){
	//printf("In Function: makemove\n");
	int **movearray = createarray(size, 0), largest, gap = 0;
	char otherstone;
	bool isU = false;
	if (stone == 'B')
		otherstone = 'W';
	else
		otherstone = 'B';
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if (board[i][j] == 'U'){
				board[i][j] = otherstone;
				movearray[i][j] = findLongest(board, size, i, j) - highestrowscore(board, size, stone) + findLongestbasic(board, size, i, j);
				//printf("goodness is %d     ", findLongest(board, size, i, j));
				//printf("badness is %d\n", highestrowscore(board, size, otherstone));
				board[i][j] = 'U';
			}
			else{
				movearray[i][j] = -500;
				//printf("goodness DNE\n");
			}
		}
	}
	largest = movearray[0][0];
	movei = 0;
	movej = 0;
	//Will now find the largest number in the array and reccomend the best move for computer to play
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if (board[i][j] == 'U'){
				if (tiecount % 3 == 1 || tiecount % 3 == 2){
					if (largest <= movearray[i][j]){
						largest = movearray[i][j];
						movei = i;
						movej = j;
						gap++;
						//printf("The recommended move is %d %d\n", movei, movej);
					}
				}
				else{
					if (largest < movearray[i][j]){
						largest = movearray[i][j];
						movei = i;
						movej = j;
						gap++;
						//printf("The recommended move is %d %d\n", movei, movej);
					}
				}
			}
		}
	}
	//will print out the value of the move array
	/*for (int i = 0; i < size; i++){
	for (int j = 0; j < size; j++){
	printf(" %5d", movearray[i][j]);
	}
	printf("\n");
	}
	*/


	//Computer makes move
	board[movei][movej] = stone;
	printf("Computer lays a stone at ROW %d COL %d.\n", movei, movej);
	//will free the array in memory
	for (int i = 0; i < size; i++){
		free(movearray[i]);
	}
	free(movearray);

	return;
}
//Bug: will keep thinking the 3 in a row that it blocked is still a threat
bool makemove(char **board, int size, char stone, char otherstone){
	int highest = 0, row = 0, col = 0, temp, otherstonehighest = 0, rownow, colnow;
	int stonehighest = 0, winrow, wincol;
	int emergencyhighest = 0;
	char stoneofinterest;
	bool tie = false;
	for (int i = 0; i <= 1;i++){
		printf("");
	}
	//-------------------------------------------
	if (firstmove == true){ // always makes sure the first move is in the middle: the best starting position
		for (int i = size / 3-1; i < size && firstmove == true; i++){
			for (int j = size / 2-1; j < size && firstmove == true; j++){
				if (board[i][j] == 'U'){
					board[0][0] = stone;
					firstmove = false;
					tiecount++;
					printf("Computer lays a stone at ROW %d COL %d.\n", i, j);
				}
			}
		}
		return false;
	}
	if (firstmoveother == true){ // always makes sure the first move is in the middle: the best starting position
			for (int i = size / 3-1; i < size && firstmoveother == true; i++){
				for (int j = size / 2-1; j < size && firstmoveother == true; j++){
					if (board[i][j] == 'U'){
						board[size-1][size-1] = stone;
						firstmoveother = false;
						tiecount++;
						printf("Computer lays a stone at ROW %d COL %d.\n", i, j);
					}
				}
			}
			return false;
		}

	//---------------------------------------------
	//will determine if it is nessissary to be in an offensive position or defensive position
	int **longeststone = createarray(size, 0);
	int **longestotherstone = createarray(size, 0);
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if (board[i][j] == 'U'){
				board[i][j] = stone;
				temp = findLongestbasic(board, size, i, j);
				longeststone[i][j] = temp;
				board[i][j] = 'U';
				if ((temp > highest && board[i][j] == stone)){
					highest = temp;
					row = i;
					col = j;
					stoneofinterest = stone;
				}
				if (temp > stonehighest){
					stonehighest = temp;
					winrow = i;
					wincol = j;
				}
			}
		}
	}

	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if (board[i][j] == 'U'){
				board[i][j] = otherstone;
				temp = findLongestbasic(board, size, i, j);
				longestotherstone[i][j] = temp;
				board[i][j] = 'U';
				if (temp >= highest){
					highest = temp;
					row = i;
					col = j;
					stoneofinterest = otherstone;
				}
				if (temp > otherstonehighest){
					otherstonehighest = temp;
					rownow = i;
					colnow = j;
				}
			}
		}
	}

	//------------------------------------
	if (stonehighest == 6){
		board[winrow][wincol] = stone;
		movei = winrow;
		movej = wincol;
		tiecount++;
		printf("Computer lays a stone at ROW %d COL %d.\n", winrow, wincol);
	}
	else if (otherstonehighest == 6){
		board[rownow][colnow] = stone;
		movei = rownow;
		movej = colnow;
		tiecount++;
		printf("Computer lays a stone at ROW %d COL %d.\n", rownow, colnow);
	}
	//function will try to block the enemy if he has 4 stones in a row, it will try to choose a move that blocks the row, as wel as enhance it's own position
	else if (otherstonehighest > 3){
		for (int i = 0; i < size; i++){
			for (int j = 0; j < size; j++){
				if (longestotherstone[i][j] != 0){
					board[i][j] = stone;
					//issue happens here when there is a better move to play offensivly but will not choose the right location to place the defending stone
					longestotherstone[i][j] += findLongestbasic(board, size, i, j) - highestrowscore(board, size, otherstone);
					board[i][j] = 'U';
				}
			}
		}
		for (int i = 0; i < size; i++){
			for (int j = 0; j < size; j++){
				if (longestotherstone[i][j] > emergencyhighest){
					emergencyhighest = longestotherstone[i][j];
					rownow = i;
					colnow = j;
				}
			}
		}
		for (int i = 0; i < size; i++){
			for (int j = 0; j < size; j++){
				printf(" %5d", longestotherstone[i][j]);
			}
			printf("\n");
		}
		board[rownow][colnow] = stone;
		movei = rownow;
		movej = colnow;
		tiecount++;
		printf("Computer lays a stone at ROW %d COL %d.\n", rownow, colnow);
	}

	/*else if (highest  >3 && stoneofinterest != stone){
		//printf("Defensive move\n");
		makemovedef(board, size, stone);
		tiecount++;
	}
	*/
	else{
		//printf("Offensive move\n");
		makemoveoff(board, size, stone);
		tiecount++;
	}
	tie == false;
	return tie;
}

int main(void){
	int size = 0, i = 0, j = 0, row, col;
	char stone, winningstone, playerstone, nothing;
	bool winner = false, tie = false;
	char **board;	//Creates the initial pointer to a pointer to an array
	printf("Enter board dimensions (n): ");
	scanf("%d", &size);
	interestboard = createarray(size, 0);
	board = (char**)malloc(size*sizeof(char*));	//Creates the pointers to the rows
	for (int i = 0; i < size; i++){	//Creates the pointers to the columns
		board[i] = (char*)malloc(size*sizeof(char));
	}
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			board[i][j] = 'U';
		}
	}
	printBoard(board, size, stone);
	printf("Computer playing B or W?: ");
	scanf(" %c", &stone);
	if (stone == 'B'){
		playerstone = 'W';
		while (winner == false){
			tie = makemove(board, size, stone, playerstone);
			if (tiecount == size*size){
				tie == true;
			}
			printBoard(board, size, stone);
			if (findLongestbasic(board, size, movei, movej) >= 6 || tie == true){
				winner = true;
				winningstone = stone;
			}
			else{
				tie = makemove(board, size, playerstone, stone);
			if (tiecount == size*size){
				tie == true;
				}
				printBoard(board, size, stone);
				if (tiecount == size*size){
					tie = true;
				}
				if (findLongestbasic(board, size, movei, movej) >= 6 || tie == true){
					winner = true;
					winningstone = playerstone;
				}
			}
		}
	}
	else{
		playerstone = 'B';
		while (winner == false){
			printf("Lay down a stone (ROW COL): ");
			scanf("%d %d", &row, &col);//if doesn't read right, add a space before the %c
			while (board[row][col] != 'U' || row >= size || col >= size){
				printf("That square is occupied.\n");
				printf("Lay down a stone (ROW COL): ");
				scanf("%d %d", &row, &col);
			}
			board[row][col] = playerstone;
			tiecount++;
			if (tiecount == size*size){
				tie = true;
			}
			printBoard(board, size, stone);
			if (findLongestbasic(board, size, row, col) >= 6 || tie == true){
				winner = true;
				winningstone = playerstone;
			}
			else{
				tie = makemove(board, size, stone, playerstone);
				if (tiecount == size*size){
					tie = true;
				}
				printBoard(board, size, stone);
				if (findLongestbasic(board, size, movei, movej) >= 6 || tie == true){
					winner = true;
					winningstone = stone;
				}
			}
		}
	}
	if (winner == true && tie == false){
		if (winningstone == 'B'){
			printf("Black player wins.");
		}
		else
			printf("White player wins.");
	}
	else
		printf("Draw!");
	printf("\n");
	printf("Press enter to exit:");
	scanf(" %c", nothing);
	return 0;
}
