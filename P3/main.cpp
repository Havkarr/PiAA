#include "board/tic-tac-toe.hpp"
#include "algorithm/min-max.hpp"
#include <iostream>

using namespace std;

int main(void)
{
    bool correctMove = false, playerMove = true; // correctMove - sprawdź czy wykonano poprawny ruch, playerMove - czyj jest nastepny ruch
    char choice = '-', player = 'X', ai = 'O', whoWon = 'E'; 
    int s, r, c; // s - rozmiar pola do gry, r - wybrany przez gracza wiersz, c - wybrana przez gracza kolumna

    cout << "Tic-tac-toe!\n----------------------------------------------------------------\n\n" 
        << "Podaj rozmiar planszy(dlugosc jednego boku): ";
    cin >> s;

    srand(time(NULL));

    // Sprawdź czy gracz podał poprawny rozmiar planszy
    if (s < 0 || cin.fail())
    {
        cout << "Podano zly rozmiar planszy.\n";
        return 1;
    }

    while (choice != '0')
    {
        board ttt(s);
        int roundNumber = s*s;
        cout << "\n1. Rozpocznij gre.\n" << "2. Zmien rozmiar planszy\n" << "3. Chce grac " << ai << "\n" << "0. Wyjscie\n";
        cin >> choice;

        switch (choice)
        {
        case '1': // Gra
            // Graj dopóki ktoś nie wygra lub nie będzie remisu
            while (whoWon == 'E' && roundNumber > 0)
            {
                ttt.displayBoard();

                if (playerMove == true) // Ruch gracza
                {   
                    
                    while (!correctMove)
                    {
                        cout << "Podaj gdzie chcesz wstawic znak: ";
                        cin >> r >> c;
                        correctMove = ttt.placeChar(r,c,player);
                    }

                    playerMove = !playerMove;
                    correctMove = false;
                }
                else // Ruch komputera
                {
                    position nextPosition = nextMove(ttt, ai);
                    ttt.placeChar(nextPosition.row, nextPosition.col, ai);
            
                    playerMove = !playerMove;
                }
                
                --roundNumber;
                whoWon = ttt.checkIfEnd();
            }
            
            // Napisz kto wygrał
            if (whoWon == 'O')
            {
                cout << "Wygralo O!\n";
            }
            else if (whoWon == 'X')
            {
                cout << "Wygral X!\n";
            }
            else if (roundNumber == 0)
            {
                cout << "Remis!\n";
            }

            whoWon = 'E';
            break;

        case '2': // Zmiana rozmiaru planszy
            cout << "Podaj rozmiar planszy(dlugosc jednego boku): ";
            cin >> s;
            break;

        case '3': // Zamiana symbolu gry
            choice = player;
            player = ai;
            ai = choice;
            break;

        case '0': // Wyjscie z gry
            break;

        default:
            cout << "Podano zla opcje. Wyberz cyfre z przedzialu [0-3]\n";
            break;
        }
    }

    return 0;
}