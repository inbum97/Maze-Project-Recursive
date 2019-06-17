#ifndef Maze_H
#define Maze_H
#include <iostream>
#include <string>
#define N 60
using namespace std;

class Maze {
private:
	int numRow;
	int numCol;
	int rowS;
	int colS;
	int rowE;
	int colE;
public:
	char mazeArr[N][N];

	//overloaded constructor
	Maze(int,int,int,int,int,int);
	bool findPath(int x, int y,int index);
	void solve(int);
	void setEnd(int x, int y);
	void print();
};

//Overloaded Constructor
Maze::Maze(int nr, int nc, int sr, int sc, int er, int ec) {
	numRow = nr+2;
	numCol = nc+2;
	rowS = sr+1;
	colS = sc+1;
	rowE = er+1;
	colE = ec+1;
}

//Printing a solution path to the maze
void Maze::print() {
	cout << "**********solution to the Maze**************\n";
	for (int x = 0; x < numRow; x++) {
		for (int y = 0; y < numCol; y++) {
			cout<< mazeArr[x][y] << " ";
		}
		cout << endl;
	}
}

/*****************************************
 setEnd: Setting the end point to a maze
 *****************************************/
void Maze::setEnd(int x, int y) {mazeArr[x][y] = 'E';}

/*************************************************
 solve: Calling findPath function to find a path
  to a maze. If found, set starting point
  else let the user know that there is no solution
  to the maze
  *************************************************/
void Maze::solve(int index) {
	setEnd(rowE, colE);
	if (findPath(rowS, colS, index)) {
		mazeArr[rowS][colS] = 'S';
		print();
	}
	else
		cout << "There is no solution to this maze\n";
}

/*******************************************
 findPath: Recursive function to find a path
  to a maze. Try all four directions to find a path
  if stuck, backtrack. 
  return true If there is an open path
  return false if there is no open path
*********************************************/
bool Maze::findPath(int x, int y, int index) {
	// Accept case Found exit
	if (mazeArr[x][y] == 'E')
		return true;
	// Reject case: Encounter Wall or path
	if (  mazeArr[x][y] == 'W' || mazeArr[x][y] == '*' || mazeArr[x][y]=='w' )
		return false;


	// Mark location as part of the solution path
	mazeArr[x][y] = '*';

	
	//Try north
	if (findPath(x - 1, y, index) == true) {
		return true;
	}

	//Try east
	if (findPath(x, y + 1, index) == true) {
		return true;

	}
	
	//Try south
	if (findPath(x + 1, y, index) == true) {
		return true;
	}
	
	//Try west
	if (findPath(x, y - 1, index) == true) {
		return true;

	}

	//Unmark location
	if(index!=4)
		mazeArr[x][y] = '.';

	return false;

}




#endif Maze_H