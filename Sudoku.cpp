//
// Created by wxk's alienware on 2017/2/1.
//

#include <iostream>

#include <iostream>
#include <algorithm>
#include <fstream>
#include "Sudoku.h"

Sudoku::Sudoku() {
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++){
            this->puzzle[i][j] = 0;
        }
    }
}

void Sudoku::loadFromFile(std::string filename) {
    //using std::ifstream method to read the txt file
    std::ifstream fin(filename);
    //counter is a integer which is used to store the current position of reader.
    int counter = 0;
    while(fin){
        //put the read value into the correct place in integer array
        fin >> *(puzzle[counter/9] + counter % 9);
        counter++;
    }
}

bool Sudoku::IsRightPlace(int count) {
    int row = count / 9;
    int col = count % 9;
    //for each small square, the same integer can't be existed
    int squareRow = row / 3 * 3;
    int squareCol = col / 3 * 3;
    for(int i = squareRow; i < squareRow + 3; i++){
        for(int j = squareCol; j < squareCol + 3; j++){
            if(tempPuzzle[i][j] == tempPuzzle[row][col] && row != i && col != j){
                return false;
            }
        }
    }

    //for each row
    for(int i = 0; i < 9; i++){
        if(tempPuzzle[row][i] == tempPuzzle[row][col] && i != col){
            return false;
        }
    }

    //for each column
    for(int i = 0; i < 9; i++){
        if(tempPuzzle[i][col] == tempPuzzle[row][col] && i != row){
            return false;
        }
    }
    return true;
}

void Sudoku::backTrace(int count) {
    if(count == 81){
        //if the integer count reaches 81, means that the sudoku puzzle has been solved, we need to copy the
        //tempPuzzle to the puzzle as a result;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                puzzle[i][j] = tempPuzzle[i][j];
            }
        }
        return;
    }
    int row = count / 9;
    int col = count % 9;
    if(tempPuzzle[row][col] != 0){
        backTrace(count +1);
    }
    else{
        for(int k = 1; k <= 9; k++){
            tempPuzzle[row][col] = k;
            if(IsRightPlace(count)){
                backTrace(count + 1);
            }
        }
        //this step means to backtrace
        tempPuzzle[row][col] = 0;
    }
}

bool Sudoku::solve() {
    //give the data in puzzle to the tempPuzzle
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            tempPuzzle[i][j] = puzzle[i][j];
        }
    }
    backTrace(0);
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(puzzle[i][j] == 0){
                return false;
            }
        }
    }
    return true;

}


void Sudoku::print() const {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cout << puzzle[i][j] << " ";
            if (j % 3 == 2) {
                std::cout << "|";
            }
        }
        std::cout<<std::endl;
        if(i%3 == 2){
            std::cout<<"------+-------+------"<<std::endl;
        }
    }
}

bool Sudoku::equals(const Sudoku &other) const {
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(this->puzzle[i][j] != other.puzzle[i][j]){
                return false;
            }
        }
    }
    return true;
}

