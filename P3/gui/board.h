#pragma once
#include <vector>
#include <iostream>

class board
{
private:
    std::vector<std::vector<char>> b; // Plansza do gry
    int size = 0; // Rozmiar podany jako d�ugo�� jednej kraw�dzi
    std::string frame = "-"; // Znak ramki do wypisywania w terminau

public:

    board(int rows = 3);

    /**
    * Funkcja wy�wietlaj�ca plansze w terminalu
    */
    void displayBoard();


    /**
    * Funkcja umieszaj�ca odpowiedni znak na planszy
    * @param row - nieujemna liczba ca�kowita okre�laj�ca rz�d w kt�rym umieszczamy znak
    * @param col - nieujemna liczba ca�kowita okre�laj�ca kolumn� w kt�rej umieszczamy znak
    * @param c - znak X lub O w zale�no�ci co chcemy umie�ci� na planszy. Znak E oznacza puste pole.
    * @return Prawda je�li znak zosta� umieszczony. Fa�sz je�li pole jest zaj�te lub podano z�e wsp�rz�dne.
    */
    bool placeChar(int row, int column, char c);


    /**
    * Funkcja sprawdzaj�ca czy kto� wygra� rozgrywk�.
    * @return Znak wygranej osoby (X/O). Je�li gra si� nie sko�czy�a funckaj zwraca znak E.
    */
    char checkIfEnd();


    /**
    * Funkcja zwraca rozmiar pola do gry jako wymiar jednej kraw�dzi pola
    * @return Nieujemna liczba ca�kowitoliczbowa
    */
    int getSize();


    /**
    * Funkcja zwraca element le��cy na podanej pozycji.
    * @param row - nieujemna liczba ca�kowita okre�laj�ca rz�d w kt�rym umieszczamy znak
    * @param col - nieujemna liczba ca�kowita okre�laj�ca kolumn� w kt�rej umieszczamy znak
    * @return Znak le��cy na podanym polu. Je�li podano ��e wsp�rz�dne to funkcja zwr�ci znak E.
    */
    char getElement(int row, int col);


    /**
    * Funkcja usuwa element na podanej pozycji.
    * @param row - nieujemna liczba ca�kowita okre�laj�ca rz�d w kt�rym umieszczamy znak
    * @param col - nieujemna liczba ca�kowita okre�laj�ca kolumn� w kt�rej umieszczamy znak
    */
    void removeElement(int row, int col);

    /**
    * Funkcja zwraca element le��cy na podanej pozycji.
    * @return Prawda je�li plansza jest zape�niona i nie ma wi�cej ruch�w. Fa�sz je�li mo�na dalej wykona� ruch.
    */
    bool isFull();


    void changeSize(int s);
};

