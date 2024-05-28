#include "MinMax.h"
#include <vector>
#include <limits>


using namespace std;

int minMax_X(board& b, int depth, int alpha, int beta, bool maximizingPlayer)
{
    int size = b.getSize();
    char winner = b.checkIfEnd();

    // Sprawdz warunek stopu - czy po ruchu kto� wygra�
    if (winner == 'X')
    {
        return 10 + depth;
    }
    else if (winner == 'O')
    {
        return -10 - depth;
    }
    else if (b.isFull())
    {
        return 0;
    }

    // Ruch maksymalizuj�cy
    // Dla ka�dego wolnego miejsca rozwi� drzewo rozwi�za� i wybierz najlepsze(o najwi�kszej warto�ci) rozwi�zanie. (Jest to ruch komputera)
    if (maximizingPlayer)
    {
        int maxVal = INT_MIN;
        for (int row = 0; row < size; row++)
        {
            for (int col = 0; col < size; col++)
            {
                if (b.getElement(row, col) == 'E')
                {
                    b.placeChar(row + 1, col + 1, 'X');
                    int val = minMax_X(b, depth - 1, alpha, beta, false);
                    b.removeElement(row + 1, col + 1);
                    maxVal = max(maxVal, val);

                    // Ci�cie alfa-beta
                    alpha = max(alpha, val);
                    if (beta <= alpha)
                    {
                        break;
                    }
                }
            }
        }

        return maxVal;
    }
    // Ruch minimalizuj�cy
    // Dla ka�dego wolnego miejsca rozwi� drzewo rozwi�za� i wybierz najgorsze(o najmniejszej warto�ci) rozwi�zanie. (Jest to ruch cz�owieka)
    else
    {
        int minVal = INT_MAX;
        for (int row = 0; row < size; row++)
        {
            for (int col = 0; col < size; col++)
            {
                if (b.getElement(row, col) == 'E')
                {
                    b.placeChar(row + 1, col + 1, 'O');
                    int val = minMax_X(b, depth - 1, alpha, beta, true);
                    b.removeElement(row + 1, col + 1);
                    minVal = min(minVal, val);

                    // Ci�cie alfa-beta
                    beta = min(beta, val);
                    if (beta <= alpha)
                    {
                        break;
                    }
                }
            }
        }

        return minVal;
    }
}

int minMax_O(board& b, int depth, int alpha, int beta, bool maximizingPlayer)
{
    int size = b.getSize();
    char winner = b.checkIfEnd();

    // Sprawdz warunek stopu - czy po ruchu kto� wygra�
    if (winner == 'O')
    {
        return 10 + depth;
    }
    else if (winner == 'X')
    {
        return -10 - depth;
    }
    else if (b.isFull())
    {
        return 0;
    }

    // Ruch maksymalizuj�cy
    // Dla ka�dego wolnego miejsca rozwi� drzewo rozwi�za� i wybierz najlepsze(o najwi�kszej warto�ci) rozwi�zanie. (Jest to ruch komputera)
    if (maximizingPlayer)
    {
        int maxVal = INT_MIN;
        for (int row = 0; row < size; row++)
        {
            for (int col = 0; col < size; col++)
            {
                if (b.getElement(row, col) == 'E')
                {
                    b.placeChar(row + 1, col + 1, 'O');
                    int val = minMax_O(b, depth - 1, alpha, beta, false);
                    b.removeElement(row + 1, col + 1);
                    maxVal = max(maxVal, val);

                    // Ci�cie alfa-beta
                    alpha = max(alpha, val);
                    if (beta <= alpha)
                    {
                        break;
                    }
                }
            }
        }

        return maxVal;
    }
    // Ruch minimalizuj�cy
    // Dla ka�dego wolnego miejsca rozwi� drzewo rozwi�za� i wybierz najgorsze(o najmniejszej warto�ci) rozwi�zanie. (Jest to ruch cz�owieka)
    else
    {
        int minVal = INT_MAX;
        for (int row = 0; row < size; row++)
        {
            for (int col = 0; col < size; col++)
            {
                if (b.getElement(row, col) == 'E')
                {
                    b.placeChar(row + 1, col + 1, 'X');
                    int val = minMax_O(b, depth - 1, alpha, beta, true);
                    b.removeElement(row + 1, col + 1);
                    minVal = min(minVal, val);

                    // Ci�cie alfa-beta
                    beta = min(beta, val);
                    if (beta <= alpha)
                    {
                        break;
                    }
                }
            }
        }

        return minVal;
    }
}

position nextMove(board& b, char whoAmI)
{
    int rank = INT_MIN;

    position bestMove{ -1, -1 };

    // Dla ka�dej wolnej kom�rki wstaw znak i rozwi� drzewo rozwi�za�.
    for (int row = 0; row < b.getSize(); row++)
    {
        for (int col = 0; col < b.getSize(); col++)
        {
            if (b.getElement(row, col) == 'E')
            {
                b.placeChar(row + 1, col + 1, whoAmI);

                // Oblicz warto�� dla podanego ruchu
                int score = whoAmI == 'X' ? minMax_X(b, b.getSize(), INT_MIN, INT_MAX, false) : minMax_O(b, b.getSize(), INT_MIN, INT_MAX, false);
                // Wycofaj ruch
                b.removeElement(row + 1, col + 1);
                // Przypisz wsp�rz�dne dla najlepszego ruchu
                if (score > rank)
                {
                    rank = score;
                    bestMove = { row + 1, col + 1 };
                }
            }
        }
    }
    return bestMove;
}