#pragma once
#include "board.h"
#include <vector>

struct position // Struktura do zwrócenia 2 elementów
{
    int row; // Wiersz
    int col; // Kolumna
};

/**
* Funkcja oceniaj¹ca ruch. Jest to wersja dla komputera graj¹cego X
* @param b - adres do dwuwymiarowego wektora przechowywuj¹cego pole do gry
* @param depth - g³êbokoœæ która pomaga okreœliæ wartoœc rozwi¹zania
* @param alpha - wartoœæ maksymalna w drzewie rozwi¹zañ. Na jej podstawie dokonujemy ciêcia
* @param beta - wartoœæ minimalna w drzewie rozwi¹zañ. Na jej podstawie dokonujemy ciêcia
* @param maximizingPlayer - Jeœli prawda to maksymalizujemy wynik. Jeœli fa³sz to minimalizujemy wynik.
* @return Intiger oceniaj¹cy dany ruch.
*/
int minMax_X(board& b, int depth, int alpha, int beta, bool maximizingPlayer);


/**
* Funkcja oceniaj¹ca ruch. Jest to wersja dla komputera graj¹cego O
* @param b - adres do dwuwymiarowego wektora przechowywuj¹cego pole do gry
* @param depth - g³êbokoœæ która pomaga okreœliæ wartoœc rozwi¹zania
* @param alpha - wartoœæ maksymalna w drzewie rozwi¹zañ. Na jej podstawie dokonujemy ciêcia
* @param beta - wartoœæ minimalna w drzewie rozwi¹zañ. Na jej podstawie dokonujemy ciêcia
* @param maximizingPlayer - Jeœli prawda to maksymalizujemy wynik. Jeœli fa³sz to minimalizujemy wynik.
* @return Intiger oceniaj¹cy dany ruch.
*/
int minMax_O(board& b, int depth, int alpha, int beta, bool maximizingPlayer);


/**
* Funkcja wybieraj¹ca nastêpny ruch.
* @param b - adres do dwuwymiarowego wektora przechowywuj¹cego pole do gry
* @param whoAmI - Podajemy tutaj dla jakiego znaku chcemy przewidzieæ ruch.
* @return Struktura position zawieraj¹ca numer wiersza (row) i numer kolumny (col) nastêpnego optymalnego ruchu.
*/
position nextMove(board& b, char whoAmI);
