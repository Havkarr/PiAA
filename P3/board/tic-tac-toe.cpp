#include "tic-tac-toe.hpp"
#include <iostream>

using namespace std;

board::board(int rows, int toWin)
{
    size = rows;
    toWin = toWin;

    for (int i = 0; i < size; i++)
    {
        b.push_back(vector<char>(size, 'E'));
        frame += "----";
    }
}

void board::displayBoard()
{
    cout << frame << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "| ";
        for (int j = 0; j < size; j++)
        {
            if (b[i][j] == 'E')
            {
                cout << " " << " | ";
            }
            else
            {
                cout << b[i][j] << " | ";
            }
        }
        cout << endl << frame << endl;
    }    
}

bool board::placeChar(int row, int column, char c)
{
    // Sprawdz czy pole jest na planszy
    if (row-1 < 0 || row-1 > size || column-1 < 0 || column-1 > size)
    {
        cout << "Podano zle wspolrzedne. Sprobuj ponownie.\n";
        return false;
    }
    // Sprawdz czy pole jest wolne
    else if(b[row-1][column-1] != 'E')
    {
        cout << "Podane pole jest zajete. Sprobuj ponownie.\n";
        return false;
    }
    
    b[row-1][column-1] = c;
    return true;
}

char board::checkIfEnd()
{
    char temp = 'E';
    bool victory = true;

    // Sprawdź rzędy
    for (int i = 0; i < size; i++)
    {
        victory = true;
        if (b[i][0] == 'E')
        {
            continue;
        }
        temp = b[i][0];
        
        for (int j = 0; j < size; j++)
        {
            if (b[i][j] != temp)
            {
                victory = false;
                break;
            }
        }

        if (victory == true)
        {
            return b[i][0];
        }
    }
    
    // Sprawdź kolumny
    for (int i = 0; i < size; i++)
    {
        victory = true;
        if (b[0][i] == 'E')
        {
            continue;
        }
        temp = b[0][i];
        
        for (int j = 0; j < size; j++)
        {
            if (b[j][i] != temp)
            {
                victory = false;
                break;
            }
        }

        if (victory == true)
        {
            return b[0][i];
        }
    }


    // Sprawdź przekątne
    temp = b[0][0];
    victory = true;
  
    for (int i = 0; i < size; i++)
    {           
        if (b[i][i] != temp || temp == 'E')
        {
            victory = false;
            break;
        }
    }
    
    if (victory == true)
    {
        return b[0][0];
    }

    // Sprawdź drugą przekątną
    victory = true;
    temp = b[size-1][0];

    for (int i = 0; i < size; i++)
    {
        if (b[size-i-1][i] != temp || temp == 'E')
        {
            victory = false;
            break;
        }
    }

    if (victory == true)
    {
        return b[size-1][0];
    }


    return 'E';
}

int board::getSize()
{
    return size;
}

char board::getElement(int row, int col)
{
    return b[row][col];
}

bool board::isFull()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (b[i][j] == 'E')
            {
                return false;
            }
        }
    }    

    return true;
}

void board::removeElement(int row, int column)
{
    // Sprawdz czy pole jest na planszy
    if (row-1 < 0 || row-1 > size || column-1 < 0 || column-1 > size)
    {
        return;
    }
    // Sprawdz czy pole jest wolne
    else if(b[row-1][column-1] == 'E')
    {
        return;
    }
    
    b[row-1][column-1] = 'E';
}

board:: ~board()
{}