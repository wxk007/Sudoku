//
// Created by wxk's alienware on 2017/2/1.
//

#ifndef PROJECT1_SUDOKU_H
#define PROJECT1_SUDOKU_H

#include <iostream>


class Sudoku {
private:
    //used to store the input and the solution of puzzle
    int puzzle[9][9];
    //used to store the temporary backtrace solution of the puzzle
    int tempPuzzle[9][9];
    //this method is used to calculate whether a specific integer can be putted in to a specific place
    bool IsRightPlace(int count);
    //the backTrace algorithm is implemented here.
    void backTrace(int count);
public:
    //the constructor would initialize the integer array puzzle
    Sudoku();
    //this method would be used to read the file from the path of filename
    void loadFromFile(std::string filename);
    //this method would be called to solve the sudoku problem
    bool solve();
    //this method would be used to print out the current condition of integer array puzzle
    void print() const;
    //this method is used to detect whether two puzzles are the same
    bool equals(const Sudoku &other) const;

};


#endif //PROJECT1_SUDOKU_H
