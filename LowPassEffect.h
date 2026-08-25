#pragma once
#include "AudioEffect.h"

/* Równanie różnicowe (Filtr IIR)
y[n] = a * x[n] + (1 - a) * y[n-1]
y[n] – Nowa próbka wyjściowa (ta, którą zaraz zapiszesz w wektorze).
x[n] – Aktualna próbka wejściowa (ta, którą właśnie czytasz z wektora).
y[n-1] – Poprzednia przetworzona próbka wyjściowa (Twoja historia z poprzedniego cyklu pętli).
a – Współczynnik odcięcia (liczba od 0.0 do 1.0). Im bliżej jedynki, tym sygnał jest mniej ruszony.
Im bliżej zera, tym bardziej gwałtowne skoki są tłumione, a dźwięk staje się ciemniejszy (bardziej zbasowany).*/


// Wazne jest to że są 2 kanały nie mozna zapisać do prawego wartosci z lewego
class LowPassFilter : public AudioEffect {
    float m_left = 0.0f;
    float m_right = 0.0f;
    float m_a;
    public:
    LowPassFilter(float a): m_a(a) {}; // a to wartosc od 0.0 - 1.0
    void process(std::vector<float> &t)override;
};

