#include<iostream>
#include "MazeRecursive.h"
#include <fstream>
using namespace std;
//Prototypes
void buildMaze(string *, int i);
void header();

//Printing header of the project
void header() {
	cout<<"\n\n~~~~~~~~~~~~Welcome to the finding path in a Maze Project~~~~~~~~~~~~~~~\n\n";
}




int main(void)
{
	header();
	string infilename[] = { "maze_1.txt", "maze_2.txt",
		"maze_3.txt", "maze_4.txt",
		"maze_5.txt","maze_6.txt", "" };
	// to allow the user to see the results for one file at a time
	int keepgoing = 1;
	int i = 0;
	// test loop: takes the names of the input files from an array
	for (string *ptr = infilename; keepgoing && *ptr != ""; ptr++)
	{
		cout << "input file: " << ptr << endl;
		buildMaze(infilename,i);
		cout << "please enter 1 to continue 0 to stop" << endl;
		cin >> keepgoing;
		i++;
	}
	return 0;
}

void buildMaze(string *filename, int index)
{
	ifstream infile;
	int numRow;
	int numCol;
	int rowS;
	int colS;
	int rowE;
	int colE;
	char element;
	string space;

	infile.open(filename[index]);
	if (!infile) {
		cout << "Error happened to open the input file!" << endl;
		//exit(EXIT_FAILURE);
	}
	cout << "Now building Maze " << index+1 << endl<<endl;
	infile >> numRow >> numCol >> rowS >> colS >> rowE >> colE;
	getline(infile, space);
	//Use constructor to pass the values to the Customer object.
	Maze m(numRow, numCol, rowS, colS, rowE, colE);
	for (int i = 0; i <= numRow + 1; i++) {
		for (int j = 0; j <= numCol + 1; j++) {
			infile >> element;
			m.mazeArr[i][j] = element;
		}
		getline(infile, space);
	}
	m.solve(index);

	infile.close();
}