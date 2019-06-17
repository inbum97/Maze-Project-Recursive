#ifndef MazeIterative_H
#define MazeIterative_H
#include <iostream>
#include <string>
#include "Stack.h"
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
	int dir = 0;
public:
	char mazeArr[N][N];

	//overloaded constructor
	Maze(int, int, int, int, int, int);
	Maze(int, int);
	bool findPath(int x, int y);
	void solve(int);
	void setEnd(int x, int y);
	void print();
	int getDir() { return dir; }
};

//Overloaded Constructor
Maze::Maze(int nr, int nc, int sr, int sc, int er, int ec) {
	numRow = nr + 2;
	numCol = nc + 2;
	rowS = sr + 1;
	colS = sc + 1;
	rowE = er + 1;
	colE = ec + 1;
}

Maze::Maze(int x, int y) {
	rowS = x;
	colS = y;
}

//Printing a solution path to the maze
void Maze::print() {
	cout << "**********solution to the Maze**************\n";
	for (int x = 0; x < numRow; x++) {
		for (int y = 0; y < numCol; y++) {
			cout << mazeArr[x][y] << " ";
		}
		cout << endl;
	}
}

/*****************************************
setEnd: Setting the end point to a maze
*****************************************/
void Maze::setEnd(int x, int y) { mazeArr[x][y] = 'E'; }

/*************************************************
solve: Calling findPath function to find a path
to a maze. If found, set starting point
else let the user know that there is no solution
to the maze
*************************************************/
void Maze::solve(int index) {
	setEnd(rowE, colE);
	if (findPath(rowS, colS)) {
		mazeArr[rowS][colS] = 'S';
		print();
	}
	else
		cout << "There is no solution to this maze\n";
}

bool Maze::findPath(int x, int y) {
	Stack<Maze> s;
	int i = x;
	int j = y;
	Maze temp(x, y);
	s.push(temp);
	while (!s.isEmpty()) {
		s.getTop(temp);
		int d = temp.getDir();
		i = temp.rowS;
		j = temp.colS;

		temp.dir++;

		if (mazeArr[i][j] == 'E')
			return true;
		if (d == 0) {
			if (mazeArr[i - 1][j] == '.') {
				Maze temp1(i - 1, j);
				mazeArr[i - 1][j] = '*';
				s.push(temp1);
			}
		}
		else if (d == 1) {
			if (mazeArr[i][j + 1] == '.') {
				Maze temp1(i, j + 1);
				mazeArr[i][j + 1] = '*';
				s.push(temp1);
			}
		}
		else if (d == 2) {
			if (mazeArr[i+1][j] == '.') {
				Maze temp1(i+1, j);
				mazeArr[i+1][j] = '*';
				s.push(temp1);
			}
		}
		else if (d == 3) {
			if (mazeArr[i][j - 1] == '.') {
				Maze temp1(i, j - 1);
				mazeArr[i][j - 1] = '*';
				s.push(temp1);
			}
		}
		else {
			s.pop(temp);
		}
	}
	return false;
}




#endif Maze_H
