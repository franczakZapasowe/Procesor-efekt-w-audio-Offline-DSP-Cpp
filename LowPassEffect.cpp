//
// Created by mf on 8/25/26.
//

#include "LowPassEffect.h"
/* Równanie różnicowe (Filtr IIR)
y[n] = a * x[n] + (1 - a) * y[n-1]
y[n] – Nowa próbka wyjściowa (ta, którą zaraz zapiszesz w wektorze).
x[n] – Aktualna próbka wejściowa (ta, którą właśnie czytasz z wektora).
y[n-1] – Poprzednia przetworzona próbka wyjściowa (Twoja historia z poprzedniego cyklu pętli).
a – Współczynnik odcięcia (liczba od 0.0 do 1.0). Im bliżej jedynki, tym sygnał jest mniej ruszony.
Im bliżej zera, tym bardziej gwałtowne skoki są tłumione, a dźwięk staje się ciemniejszy (bardziej zbasowany).*/


//nieparzyste wartosci to kanal lewy w stero wav zawsze zaczyna sie od lewego
void LowPassEffect::process(std::vector<float> &tab) {
    int kanal = 0;
    for (int i = 0; i < tab.size(); i++) {
        kanal = i % 2;
        if (kanal == 0) { //lewy
            tab[i] = m_a * tab[i] + (1 - m_a) * m_left;
            m_left = tab[i];
        }else { // prawy
            tab[i] = m_a * tab[i] + (1 - m_a) * m_right;
            m_right = tab[i];
        }
    }
}