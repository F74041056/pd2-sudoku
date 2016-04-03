#include <iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

class Sudoku
{
	public:
		int map[10][10];
		int add;
		int ats[10][10];

		Sudoku();
		void giveQuestion();
		void readIn();
		int col_check(int,int);
		int row_check(int,int);
		int squ_check(int,int,int);
		void solve1();
		void solve();
		void changeNum(int,int);
		void changeRow(int,int);
		void changeCol(int,int);
		void rotate(int);
		void flip(int);
		void change();
		void printOut();
		void transform();
};
