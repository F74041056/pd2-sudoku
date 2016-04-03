#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Sudoku.h"
using namespace std;

int main()
{
	Sudoku ss;
	ss.readIn();
	ss.solve();
	return 0;
}
