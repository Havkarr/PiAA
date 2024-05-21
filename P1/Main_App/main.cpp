// g++ main.cpp .\algorithms\merge_sort.cpp .\algorithms\quick_sort.cpp .\algorithms\introsort.cpp -o main
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <chrono>
#include "algorithms\merge_sort.hpp"
#include "algorithms\quick_sort.hpp"
#include "algorithms\introsort.hpp"
#include "structure.hpp"


using namespace std;


vector <movie> movie_list;


// Wypisz zawartosc movie_list na terminalu
void print_data(vector <movie> movie_list)
{
    vector<movie>::iterator it = movie_list.begin();
    while (it != movie_list.end())
    {
        cout << it->title << " ocenka: " << it->grade << endl;
        ++it;
    }

}

// Sprawdz czy elementy zostaly uporzadkowane prawidlowo
void verify_list(vector <movie> movie_list)
{
    vector<movie>::iterator it = movie_list.begin();

    if (it->grade > (it+1)->grade)
    {
        cout << "Blad!!" << endl;
        return;
    }
    ++it;

    while (it != movie_list.end())
    {
        if (it->grade < (it-1)->grade)
        {
            cout << "Blad!!" << endl;
            return;
        }
        ++it;
    }
    cout <<  "Poprawna kolejnosc.\n";
}

// Zapisz zawartosc movie_list do pliku .csv
void save_to_csv(vector <movie> movie_list)
{
    string filename;
    cout << "Podaj nazwe pliku bez rozszerzenia: ";
    cin >> filename;
    filename += ".csv";
    ofstream plik (filename);
    
    if (plik.good() == true)
    {
        plik << ",movie,rating\n";
        int i = 0;
        vector<movie>::iterator it = movie_list.begin();
        while (it != movie_list.end())
        {
           plik << i <<","<<it->title<<","<<it->grade<< endl;
           ++i;++it;
        }
    }
    plik.close();
}

// Zaladuj dane z pliku
void load_file(vector <movie>* movie_list)
{
    if (movie_list->empty() != true)
    {
        // Przy ponownym zaladowaniu oproznij liste
        movie_list->clear();
    }
    

    int size = 5, s = 0;
    string filename = "full.csv";

    // cout << "Podaj nazwe pliku: ";
    // cin >> filename;
    cout << "Podaj wielkosc struktury:";
    cin >> size;

    auto start = chrono::high_resolution_clock::now();
    fstream plik;
    plik.open( filename, ios::in | ios::out );
    if( plik.good() == true )
    {
        string line, title, grade;
        movie temp;
        getline(plik, line);
        while(getline(plik,line))
        {
            title = line.substr(line.find_first_of(",")+1,line.find_last_of(","));
            grade = line.substr(line.find_last_of(",")+1);
            title = title.substr(0,title.find_last_of(','));

            if (grade.empty())
            {
                continue;
            }

            temp.title = title;
            temp.grade = stof(grade);
            movie_list->push_back(temp);

            if (s == size-1)
            {
                break;
            }
            s++;
        }
    } 
    else 
        cout << "Blad przy wczytywaniu pliku" << endl;  
    plik.close();

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "Filtrowanie danych zajelo " << duration.count() << " mikrosekund.\n"; 
}

// Oblicz wartosc srednia
float mean_val(vector <movie> movie_list)
{
    int sum = 0;
    float count;
    count = movie_list.size();

    if(count <= 0)
    {
        return 0;
    }
    
    vector<movie>::iterator it = movie_list.begin();

    while (it != movie_list.end())
    {
        sum += it->grade;
        ++it;
    }
    return (sum/count);
}

// Oblicz mediane
float median(vector <movie> movie_list)
{
    int size = movie_list.size();

    if(size <= 0)
    {
        return 0;
    }

    if (size%2==0)
    {
        return (movie_list[(size/2)].grade + movie_list[(size/2)-1].grade)/2;
    }
    else
    {
        return movie_list[ceil(size/2)].grade;
    }
    
    
}

int main()
{
    cout << "\n_________________________________________________________\n";

    char c = 'z';
    chrono::high_resolution_clock::time_point start;
    chrono::high_resolution_clock::time_point end;
    chrono::microseconds duration;

    while (c != '0')
    {
        cout << endl << "0 - Wyjscie.\n"
        << "1 - Zaladuj dane.\n"
        << "2 - Wypisz dane.\n"
        << "3 - Zapisz dane.\n"
        << "4 - Sortuj dane.\n"
        << "5 - Policz srednia i mediane.\n"
        << "Podaj liczbe: ";
        cin >> c;

        switch (c)
        {
            case '0':
                break;

            case '1':
                load_file(&movie_list);
                break;
            case '2':
                cout << "\n_________________________________________________________\n";
                print_data(movie_list);
                break;
            case '3':
                save_to_csv(movie_list);
                break;
            case '4':
                cout << "\n Wybierz sortowanie:\n"
                << "1 - Merge sort (sortowanie przez scalanie).\n"
                << "2 - Quick sort (sortowanie szybkie).\n"
                << "3 - Intro sort (sortowanie introspectywne).\n"
                << "4 - Powrot\n";
                cin >> c;
                switch (c)
                {
                    case '4':
                        break;
                    case '1':
                        start = chrono::high_resolution_clock::now();
                        merge_sort(&movie_list);
                        end = chrono::high_resolution_clock::now();
                        duration = chrono::duration_cast<chrono::microseconds>(end - start);

                        cout << "Merg sort trwal " << duration.count() << " mikrosekund.\n"; 
                        verify_list(movie_list);
                        break;
                    case '2':
                        start = chrono::high_resolution_clock::now();
                        quick_sort(&movie_list,0,movie_list.size()-1);
                        end = chrono::high_resolution_clock::now();
                        duration = chrono::duration_cast<chrono::microseconds>(end - start);

                        cout << "Quick sort trwal " << duration.count() << " mikrosekund.\n";
                        verify_list(movie_list);
                        break;
                    case '3':
                        start = chrono::high_resolution_clock::now();
                        intro_sort(&movie_list);
                        end = chrono::high_resolution_clock::now();
                        duration = chrono::duration_cast<chrono::microseconds>(end - start);

                        cout << "Intro sort trwal " << duration.count() << " mikrosekund.\n";
                        verify_list(movie_list);
                        break;
                    default:
                        cout << "Podano zly argument.\n";
                        break;
                }

                break;
            case '5':
                cout << "\nSrednia arytmetyczna: " << mean_val(movie_list) << endl;
                cout << "Mediana: " << median(movie_list) << endl;
                break;
            
            default:
                cout << "Podano zly argument.\n";
                break;
        }

    }
    

    return 0;
}