#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
// Maze Search Program
// Jonathan Rose
// November 6, 2013

// This is a program to search a maze for its exit using a recursive approach
// It is broken into several pieces, each part being done by a separate function:
//
// CreateAndInitMaze:  	Creating, Initializing, and Reading in the Maze:
// PrintMaze:          	Print out the Maze
// ValidDirection:	Check if a square in the maze is explorable: 
// FindExit:		Recursively Search the maze
// Main:		main program

// Since we use Maze everywhere, it is handy to have it global, as well as its Size
// Maze will be a dynamically allocated 2 D array
// When initialized, each element will either be:
//	'W' - a wall that can't be crossed
//	'E' - the exit
//	'S' - the starting point
//
// During Traversal of the maze, 
//	'T' means we've already looked at this square, and shouldn't do it again
//	'P' means this square is on the successful path towards the exit

char **Maze;

// The Dimension of the array

int Size;

int StartRow, StartCol;

// This function dynamically allocates the array of size Size
// Then it asks the user for the locations of the walls, Exit and Start

void CreateAndInitMaze() {

	int InRow, InCol;

	// Allocate the array

	Maze = (char **) malloc (Size * sizeof(char *)); 

	for (int i = 0; i< Size; i++) 
		Maze[i] = (char *) malloc (Size * sizeof(char));  

	// Set everything to be unoccupied, 'U' 

	for (int i = 0; i < Size; i++)
	    for (int j = 0; j < Size; j++)
	       Maze[i][j] = 'U';

	// Read in the wall parts

	do {
	    printf("Enter Wall Row Col (-1 -1 to finish): ");
	    scanf("%d %d", &InRow, &InCol);

	    if (InRow != -1) 
	    	Maze[InRow][InCol] = 'W';

	} while (InRow != -1);

	// Get Exit 

        printf("Enter Exit Row Col: ");
        scanf("%d %d", &InRow, &InCol);

	Maze[InRow][InCol] = 'E';

	// Get Start - recall StartRow and StartCol are global, need later

	printf ("Enter Starting Row Col: ");
	scanf("%d %d", &StartRow, &StartCol);
	Maze[StartRow][StartCol] = 'S';

}

// Print a copy of the Maze

void PrintMaze() {

	for (int i = 0; i < Size; i++) {
	    for (int j = 0; j < Size; j++)
	       printf("%c",Maze[i][j]);
	    printf("\n");
	}
}

// ValidDirection looks at a square to see if it is explorable:
// - it returns True if this (Row, Col) is in the maze, is not a wall, and hasn't been explored already

bool ValidDirection(int Row, int Col) {

	bool Valid = false;

	if (Row >= 0 && Row < Size && Col >= 0 && Col < Size) {
	    if (Maze[Row][Col] != 'W' && Maze[Row][Col] != 'T' && Maze[Row][Col] != 'S') Valid = true;
	}

	return Valid;

}

// Function to recursively search the maze - checking for exit from each square in every legal direction

bool FindExit(int Row, int Col) {

	bool Successful = false;

        // Debug line prints out where the search is going

	printf("FindExit %d %d %c\n",Row,Col,Maze[Row][Col]);

	if (Maze[Row][Col] == 'E')  Successful = true;

	else {

	   // Flag this square as already looked at (touched, 'T') 
	   // so that it isn't explored again

	   Maze[Row][Col] = 'T';
	
	   // Look Right

	   if (ValidDirection(Row, Col+1)) Successful = FindExit(Row, Col+1); 
	   
	   // If not successful look Up

	   if (!Successful)  { 
	       if (ValidDirection(Row-1, Col)) Successful = FindExit(Row-1, Col); 
	      
	       // If not successful look Left

	       if (!Successful)  { 
		   if (ValidDirection(Row, Col-1)) Successful = FindExit(Row, Col-1); 

	           // If not successful look Down

	           if (!Successful) { 
		       if (ValidDirection(Row+1, Col)) Successful = FindExit(Row+1, Col); 

	           }
	       }
	   }
	}
	// When arrive here, was either successful from this square or not

	// If successful mark Square as part of Path with 'P'

	if (Successful) {
		Maze[Row][Col] = 'P';
		printf("   Success at %d %d\n",Row,Col);
	}
	else printf("   Fail at %d %d\n",Row,Col);

	return Successful;
}

// Main function creates and reads in the maze, launches recursion to hunt for path at starting point


int main (void) {

	// Size is a global variable, accessible in every function 

	printf("Enter Maze Dimension: ");
	scanf ("%d", &Size);

	// Call Function to dynamically allocate, initialize and return a Size x Size Array
	// It also reads in starting point of maze into global variables StartRow, StartCol

	CreateAndInitMaze();  

	// Print the Initial Maze

	printf("\n");
	PrintMaze();

	// Launch Recursive search of maze

	if (FindExit(StartRow,StartCol)) printf("Exit Found!!!\n");

	else printf ("Exit Not Found!\n");

	PrintMaze();

	// Free up the memory before leaving program, to be clean

	for (int i = 0; i< Size; i++) 
		free(Maze[i]);

	free(Maze);
}
