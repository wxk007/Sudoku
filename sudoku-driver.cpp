// Jerry Roth
// CS 3270
// Project 1 - Sudoku Solver
// Oct. 2006

#include <iostream>
#include <string>
#include <time.h>
#include "Sudoku.h"

int main(int argc, char *argv[]) {
    std::string ans, filename;
    Sudoku puzzle;

    std::cout << "\nSudoku Solver" << std::endl;
    std::cout << "-------------\n" << std::endl;

    do {
        std::cout << "\nEnter name of file containing the Sudoku problem: ";
        std::cin >> filename;
        puzzle.loadFromFile(filename);

        std::cout << "Given Puzzle:\n" << std::endl;
        puzzle.print();

        std::cout << "\nSolved Puzzle:\n" << std::endl;

        clock_t startTime = clock();

        if (puzzle.solve()) {
            puzzle.print(); // print solved puzzle
        } else {
            std::cout << "\nNo Solution" << std::endl; // indicate there is no solution
        }

        clock_t endTime = clock();

        std::cout << "\n\nTime used: "
                  << (endTime - startTime) / (double) CLOCKS_PER_SEC
                  << " seconds.\n" << std::endl;

        //// Note: if you have the answer to your puzzle in another file, you can use
        //// the following code to compare your solution to the known answer.
        //Sudoku solution;
        //solution.loadFromFile("<type the answer file name here>");
        //if (puzzle.equals(solution))
        //   std::cout << "Correct solution" << std::endl;
        //else
        //   std::cout << "Incorrect solution" << std::endl;



        std::cout << "\nDo you want to run it again? (Y|N) ";
        std::cin >> ans;

    } while (ans == "Y" || ans == "y");


    return 0;
}

