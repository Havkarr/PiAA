#pragma once
#include <vector>
#include <iostream>

class board
{
private:
    std::vector<std::vector<char>> b; // Plansza do gry
    int size = 0; // Rozmiar podany jako długość jednej krawędzi
    std::string frame = "-"; // Znak ramki do wypisywania w terminau

public:

    board(int rows=3);
    ~board();

    /**
    * Funkcja wyświetlająca plansze w terminalu
    */
    void displayBoard();


    /**
    * Funkcja umieszająca odpowiedni znak na planszy
    * @param row - nieujemna liczba całkowita określająca rząd w którym umieszczamy znak
    * @param col - nieujemna liczba całkowita określająca kolumnę w której umieszczamy znak
    * @param c - znak X lub O w zależności co chcemy umieścić na planszy. Znak E oznacza puste pole.
    * @return Prawda jeśli znak został umieszczony. Fałsz jeśli pole jest zajęte lub podano złe współrzędne.
    */
    bool placeChar(int row, int column, char c);

    
    /**
    * Funkcja sprawdzająca czy ktoś wygrał rozgrywkę.
    * @return Znak wygranej osoby (X/O). Jeśli gra się nie skończyła funckaj zwraca znak E.
    */
    char checkIfEnd();


    /**
    * Funkcja zwraca rozmiar pola do gry jako wymiar jednej krawędzi pola
    * @return Nieujemna liczba całkowitoliczbowa 
    */
    int getSize();


    /**
    * Funkcja zwraca element leżący na podanej pozycji.
    * @param row - nieujemna liczba całkowita określająca rząd w którym umieszczamy znak
    * @param col - nieujemna liczba całkowita określająca kolumnę w której umieszczamy znak
    * @return Znak leżący na podanym polu. Jeśli podano źłe współrzędne to funkcja zwróci znak E. 
    */
    char getElement(int row, int col);


    /**
    * Funkcja usuwa element na podanej pozycji.
    * @param row - nieujemna liczba całkowita określająca rząd w którym umieszczamy znak
    * @param col - nieujemna liczba całkowita określająca kolumnę w której umieszczamy znak
    */
    void removeElement(int row, int col);

    /**
    * Funkcja zwraca element leżący na podanej pozycji.
    * @return Prawda jeśli plansza jest zapełniona i nie ma więcej ruchów. Fałsz jeśli można dalej wykonać ruch. 
    */
    bool isFull();

};


