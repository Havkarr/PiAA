#pragma once
#include "board.h"
#include <vector>

struct position // Struktura do zwr�cenia 2 element�w
{
    int row; // Wiersz
    int col; // Kolumna
};

/**
* Funkcja oceniaj�ca ruch. Jest to wersja dla komputera graj�cego X
* @param b - adres do dwuwymiarowego wektora przechowywuj�cego pole do gry
* @param depth - g��boko�� kt�ra pomaga okre�li� warto�c rozwi�zania
* @param alpha - warto�� maksymalna w drzewie rozwi�za�. Na jej podstawie dokonujemy ci�cia
* @param beta - warto�� minimalna w drzewie rozwi�za�. Na jej podstawie dokonujemy ci�cia
* @param maximizingPlayer - Je�li prawda to maksymalizujemy wynik. Je�li fa�sz to minimalizujemy wynik.
* @return Intiger oceniaj�cy dany ruch.
*/
int minMax_X(board& b, int depth, int alpha, int beta, bool maximizingPlayer);


/**
* Funkcja oceniaj�ca ruch. Jest to wersja dla komputera graj�cego O
* @param b - adres do dwuwymiarowego wektora przechowywuj�cego pole do gry
* @param depth - g��boko�� kt�ra pomaga okre�li� warto�c rozwi�zania
* @param alpha - warto�� maksymalna w drzewie rozwi�za�. Na jej podstawie dokonujemy ci�cia
* @param beta - warto�� minimalna w drzewie rozwi�za�. Na jej podstawie dokonujemy ci�cia
* @param maximizingPlayer - Je�li prawda to maksymalizujemy wynik. Je�li fa�sz to minimalizujemy wynik.
* @return Intiger oceniaj�cy dany ruch.
*/
int minMax_O(board& b, int depth, int alpha, int beta, bool maximizingPlayer);


/**
* Funkcja wybieraj�ca nast�pny ruch.
* @param b - adres do dwuwymiarowego wektora przechowywuj�cego pole do gry
* @param whoAmI - Podajemy tutaj dla jakiego znaku chcemy przewidzie� ruch.
* @return Struktura position zawieraj�ca numer wiersza (row) i numer kolumny (col) nast�pnego optymalnego ruchu.
*/
position nextMove(board& b, char whoAmI);
