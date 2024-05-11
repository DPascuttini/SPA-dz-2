#include "gameOfLife.h"

bool gameOfLife::slucajna_vrijednost()
{
    return rand() % 4 == 0;
}

bool gameOfLife::celija_zauzeta(int i, int j)
{
    if (i < 0 || i >= REDAKA || j < 0 || j >= STUPACA) {
        return false;
    }
    return _generacija[i][j];
}

gameOfLife::gameOfLife()
{
    srand(time(nullptr));
    for (int i = 0; i < REDAKA; i++) {
        for (int j = 0; j < STUPACA; j++) {
            _generacija[i][j] = slucajna_vrijednost();
        }
    }
}

void gameOfLife::sljedeca_generacija()
{
    for (int i = 0; i < REDAKA; i++) {
        for (int j = 0; j < STUPACA; j++) {
            int broj_susjeda = 0;


            if (celija_zauzeta(i - 1, j - 1)) broj_susjeda++;
            if (celija_zauzeta(i - 1, j)) broj_susjeda++;
            if (celija_zauzeta(i - 1, j + 1)) broj_susjeda++;
            if (celija_zauzeta(i, j - 1)) broj_susjeda++;
            if (celija_zauzeta(i, j + 1)) broj_susjeda++;
            if (celija_zauzeta(i + 1, j - 1)) broj_susjeda++;
            if (celija_zauzeta(i + 1, j)) broj_susjeda++;
            if (celija_zauzeta(i + 1, j + 1)) broj_susjeda++;


            if (_generacija[i][j]) {
                if (broj_susjeda < 2 || broj_susjeda > 3) {
                    _sljedeca_generacija[i][j] = false;
                }
                else {
                    _sljedeca_generacija[i][j] = true;
                }
            }
            else {
                if (broj_susjeda == 3) {
                    _sljedeca_generacija[i][j] = true;
                }
                else {
                    _sljedeca_generacija[i][j] = false;
                }
            }
        }
    }
    for (int i = 0; i < REDAKA; i++) {
        for (int j = 0; j < STUPACA; j++) {
            _generacija[i][j] = _sljedeca_generacija[i][j];
        }
    }
}

void gameOfLife::iscrtaj()
{
    system("CLS");
    for (int i = 0; i < REDAKA; i++) {
        for (int j = 0; j < STUPACA; j++) {
            if (_generacija[i][j]) {
                cout << "*";
            }
            else {
                cout << ".";
            }
        }
        cout << endl;
    }

    cout << endl;
}
