#pragma once
#include <vector>
#include <iostream>

class board
{
private:
    std::vector<std::vector<char>> b; // Plansza do gry
    int size = 0; // Rozmiar podany jako d³ugoœæ jednej krawêdzi
    std::string frame = "-"; // Znak ramki do wypisywania w terminau

public:

    board(int rows = 3);

    /**
    * Funkcja wyœwietlaj¹ca plansze w terminalu
    */
    void displayBoard();


    /**
    * Funkcja umieszaj¹ca odpowiedni znak na planszy
    * @param row - nieujemna liczba ca³kowita okreœlaj¹ca rz¹d w którym umieszczamy znak
    * @param col - nieujemna liczba ca³kowita okreœlaj¹ca kolumnê w której umieszczamy znak
    * @param c - znak X lub O w zale¿noœci co chcemy umieœciæ na planszy. Znak E oznacza puste pole.
    * @return Prawda jeœli znak zosta³ umieszczony. Fa³sz jeœli pole jest zajête lub podano z³e wspó³rzêdne.
    */
    bool placeChar(int row, int column, char c);


    /**
    * Funkcja sprawdzaj¹ca czy ktoœ wygra³ rozgrywkê.
    * @return Znak wygranej osoby (X/O). Jeœli gra siê nie skoñczy³a funckaj zwraca znak E.
    */
    char checkIfEnd();


    /**
    * Funkcja zwraca rozmiar pola do gry jako wymiar jednej krawêdzi pola
    * @return Nieujemna liczba ca³kowitoliczbowa
    */
    int getSize();


    /**
    * Funkcja zwraca element le¿¹cy na podanej pozycji.
    * @param row - nieujemna liczba ca³kowita okreœlaj¹ca rz¹d w którym umieszczamy znak
    * @param col - nieujemna liczba ca³kowita okreœlaj¹ca kolumnê w której umieszczamy znak
    * @return Znak le¿¹cy na podanym polu. Jeœli podano Ÿ³e wspó³rzêdne to funkcja zwróci znak E.
    */
    char getElement(int row, int col);


    /**
    * Funkcja usuwa element na podanej pozycji.
    * @param row - nieujemna liczba ca³kowita okreœlaj¹ca rz¹d w którym umieszczamy znak
    * @param col - nieujemna liczba ca³kowita okreœlaj¹ca kolumnê w której umieszczamy znak
    */
    void removeElement(int row, int col);

    /**
    * Funkcja zwraca element le¿¹cy na podanej pozycji.
    * @return Prawda jeœli plansza jest zape³niona i nie ma wiêcej ruchów. Fa³sz jeœli mo¿na dalej wykonaæ ruch.
    */
    bool isFull();


    void changeSize(int s);
};

