#include "min-max.hpp"
#include <vector>
#include <limits>

using namespace std;

int minMax_X(board b, int depth, int alpha, int beta, bool maximizingPlayer)
{
    int size = b.getSize();
    char winner = b.checkIfEnd();
    
    if (winner == 'X')
    {return 10 + depth;}
    else if (winner == 'O')
    {return -10 - depth;}
    else if (b.isFull())
    {return 0;}
    
    if (maximizingPlayer)
    {
        int maxVal = INT_MIN;
        for (int row = 0; row < size; row++)
        {
            for (int col = 0; col < size; col++)
            {
                if (b.getElement(row,col) == 'E')
                {
                    b.placeChar(row, col, 'X');
                    int val = minMax_X(b,depth-1,1,1,false);
                    b.removeElement(row,col);
                    maxVal = max(maxVal, val);
                }
            }
        }
        return maxVal;
    }
    else{
        int minVal = INT_MAX;
        for (int row = 0; row < size; row++)
        {
            for (int col = 0; col < size; col++)
            {
                if (b.getElement(row,col) == 'E')
                {
                    b.placeChar(row, col, 'O');
                    int val = minMax_X(b,depth-1,1,1,false);
                    b.removeElement(row,col);
                    minVal = min(minVal, val);
                }
            }
        }
        return minVal;
    }
}


int minMax_O(board b, int depth, int alpha, int beta, bool maximizingPlayer)
{
    int size = b.getSize();
    char winner = b.checkIfEnd();
    
    if (winner == 'O')
    {return 10 + depth;}
    else if (winner == 'X')
    {return -10 - depth;}
    else if (b.isFull())
    {return 0;}
    
    if (maximizingPlayer)
    {
        int maxVal = INT_MIN;
        for (int row = 0; row < size; row++)
        {
            for (int col = 0; col < size; col++)
            {
                if (b.getElement(row,col) == 'E')
                {
                    b.placeChar(row, col, 'O');
                    int val = minMax_X(b,depth-1,1,1,false);
                    b.removeElement(row,col);
                    maxVal = max(maxVal, val);
                }
            }
        }
        return maxVal;
    }
    else{
        int minVal = INT_MAX;
        for (int row = 0; row < size; row++)
        {
            for (int col = 0; col < size; col++)
            {
                if (b.getElement(row,col) == 'E')
                {
                    b.placeChar(row, col, 'X');
                    int val = minMax_X(b,depth-1,1,1,false);
                    b.removeElement(row,col);
                    minVal = min(minVal, val);
                }
            }
        }
        return minVal;
    }
}