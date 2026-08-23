//
// Created by mf on 8/23/26.
//

#include "DelayEffect.h"
// musimy zwiekszyc rozmiar wektora zeby miec miejsce na ogon
void DelayEffect::process(std::vector<float> &t) {
    t.resize(t.size()+m_offset*5);
    for (size_t i =0 ; i <t.size(); ++i) {
        int indexPrzeszly = i - m_offset;
        if (indexPrzeszly >= 0) // ZERO TO JUŻ INDEX!!
            t[i]+=t[indexPrzeszly]*m_delayGain;
    }
}
