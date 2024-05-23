#include "min-max.hpp"
#include <vector>
#include <limits>

using namespace std;


int minMax_X(board &b, int depth, int alpha, int beta, bool maximizingPlayer)
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
                    b.placeChar(row+1, col+1, 'X');
                    int val = minMax_X(b,depth-1,1,1,false);
                    b.removeElement(row+1,col+1);
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
                    b.placeChar(row+1, col+1, 'O');
                    int val = minMax_X(b,depth-1,1,1,true);
                    b.removeElement(row+1,col+1);
                    minVal = min(minVal, val);
                }
            }
        }

        return minVal;
    }
}


int minMax_O(board &b, int depth, int alpha, int beta, bool maximizingPlayer)
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
                    b.placeChar(row+1, col+1, 'O');
                    int val = minMax_O(b,depth-1,1,1,false);
                    b.removeElement(row+1,col+1);
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
                    b.placeChar(row+1, col+1, 'X');
                    int val = minMax_O(b,depth-1,1,1,true);
                    b.removeElement(row+1,col+1);
                    minVal = min(minVal, val);
                }
            }
        }

        return minVal;
    }
}


position nextMove(board &b, char whoAmI)
{
    int rank = INT_MIN;

    position bestMove{-1,-1};

    for (int row = 0; row < b.getSize(); row++)
    {
        for (int col = 0; col < b.getSize(); col++)
        {
            if (b.getElement(row,col) == 'E')
            {
                b.placeChar(row+1,col+1,whoAmI);
                int score = whoAmI == 'X' ? minMax_X(b, b.getSize(),INT_MAX,INT_MIN,false) : minMax_O(b, b.getSize(),INT_MAX,INT_MIN,false);
                cout << score << endl;
                b.removeElement(row+1,col+1);
                if (score > rank)
                {
                    rank = score;
                    bestMove={row+1,col+1};
                }
            } 
        }
    }
    return bestMove;
}