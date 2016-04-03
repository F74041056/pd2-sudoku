// README for project1
// First you have to write the program for the project1
// After finishing, you will have two file about the project1, Sudoku.h and Sudoku.cpp
// Then, creat the main function that the project1 need, that is, giveQuestion.cpp, solve.cpp, and transform.cpp
// Final, write all your compile instruction in the Makefile
// Thus, in the folder of the project1 will have the following files:
// Sudoku.h, Sudoku.cpp, giveQuestion.cpp, solve.cpp, transform.cpp, Makefile
// Then input the instruction
make
// Then, it will appear the following words:
// g++ -o giveQuestion giveQuestion.cpp Sudoku.o
// g++ -o solve solve.cpp Sudoku.o
// g++ -o transform transform.cpp Sudoku.o
// Next, input:
./giveQuestion > question.txt
// Then, it will creat a file, question.txt, where the question is inputed
// Final, input:
./solve < question.txt
// The answer to the question is outputed in the screen
1
6 4 9 2 1 5 3 8 7
8 1 7 4 3 6 5 9 2
2 5 3 8 7 9 4 6 1
3 8 4 1 6 2 9 7 5
1 9 5 7 4 8 6 2 3
7 2 6 5 9 3 8 1 4
5 7 1 6 8 4 2 3 9
9 6 2 3 5 1 7 4 8
4 3 8 9 2 7 1 5 6
