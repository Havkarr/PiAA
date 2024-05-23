#pragma once
#include "../board/tic-tac-toe.hpp"
#include <vector>

struct position // Struktura do zwrócenia 2 elementów
{
    int row; // Wiersz
    int col; // Kolumna
};

/**
* Funkcja oceniająca ruch. Jest to wersja dla komputera grającego X
* @param b - adres do dwuwymiarowego wektora przechowywującego pole do gry
* @param depth - głębokość która pomaga określić wartośc rozwiązania
* @param alpha - wartość maksymalna w drzewie rozwiązań. Na jej podstawie dokonujemy cięcia 
* @param beta - wartość minimalna w drzewie rozwiązań. Na jej podstawie dokonujemy cięcia 
* @param maximizingPlayer - Jeśli prawda to maksymalizujemy wynik. Jeśli fałsz to minimalizujemy wynik.
* @return Intiger oceniający dany ruch.
*/
int minMax_X(board &b, int depth, int alpha, int beta, bool maximizingPlayer);


/**
* Funkcja oceniająca ruch. Jest to wersja dla komputera grającego O
* @param b - adres do dwuwymiarowego wektora przechowywującego pole do gry
* @param depth - głębokość która pomaga określić wartośc rozwiązania
* @param alpha - wartość maksymalna w drzewie rozwiązań. Na jej podstawie dokonujemy cięcia 
* @param beta - wartość minimalna w drzewie rozwiązań. Na jej podstawie dokonujemy cięcia 
* @param maximizingPlayer - Jeśli prawda to maksymalizujemy wynik. Jeśli fałsz to minimalizujemy wynik.
* @return Intiger oceniający dany ruch. 
*/
int minMax_O(board &b, int depth, int alpha, int beta, bool maximizingPlayer);


/**
* Funkcja wybierająca następny ruch.
* @param b - adres do dwuwymiarowego wektora przechowywującego pole do gry
* @param whoAmI - Podajemy tutaj dla jakiego znaku chcemy przewidzieć ruch. 
* @return Struktura position zawierająca numer wiersza (row) i numer kolumny (col) następnego optymalnego ruchu.
*/
position nextMove(board &b, char whoAmI);