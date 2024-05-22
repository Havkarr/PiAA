#pragma once
#include <vector>
#include <iostream>

class board
{
private:
    std::vector<std::vector<char>> b;
    int size = 0, toWin = 0;
    std::string frame = "-";

public:
    board(int rows=3, int toWin=3);
    ~board();

    void displayBoard();
    bool placeChar(int row, int column, char c);
    char checkIfEnd();
    int getSize();
    char getElement(int row, int col);
    void removeElement(int row, int col);
    bool isFull();

};


