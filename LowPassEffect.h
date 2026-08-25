//
// Created by mf on 8/25/26.
//

#ifndef OFFLINEDSP_LOWPASSEFFECT_H
#define OFFLINEDSP_LOWPASSEFFECT_H
#include "AudioEffect.h"

/* Równanie różnicowe (Filtr IIR)
y[n] = a * x[n] + (1 - a) * y[n-1]
y[n] – Nowa próbka wyjściowa (ta, którą zaraz zapiszesz w wektorze).
x[n] – Aktualna próbka wejściowa (ta, którą właśnie czytasz z wektora).
y[n-1] – Poprzednia przetworzona próbka wyjściowa (Twoja historia z poprzedniego cyklu pętli).
a – Współczynnik odcięcia (liczba od 0.0 do 1.0). Im bliżej jedynki, tym sygnał jest mniej ruszony.
Im bliżej zera, tym bardziej gwałtowne skoki są tłumione, a dźwięk staje się ciemniejszy (bardziej zbasowany).*/


// Wazne jest to że są 2 kanały nie mozna zapisać do prawego wartosci z lewego

class LowPassEffect:public AudioEffect {
    float m_a;
    float m_left = 0;
    float m_right = 0;
public:
    LowPassEffect(float a):m_a(a) {};
    void process(std::vector<float> &) override;
};


#endif //OFFLINEDSP_LOWPASSEFFECT_H
