//
// Created by mf on 8/23/26.
//

#include "DelayEffect.h"
// musimy zwiekszyc rozmiar wektora zeby miec miejsce na ogon
// liczymy index naszej starej probki w czasie jezeli jest mnieszny niz 0 czekamy
// jak jest wiekszy dodajemy do aktualnego stary * gain
void DelayEffect::process(std::vector<float> & t) {
    t.resize(t.size() + m_offset*10);
    for (int i = 0; i < t.size(); i++) {
        int index = i - m_offset;
        if (index>=0)
        t[i]+= t[index]*m_gain;
    }
}
