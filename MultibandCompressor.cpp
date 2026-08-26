//
// Created by mf on 8/26/26.
//

#include "MultibandCompressor.h"
#include <vector>
// obiektowka is wining omg for real!!!!!!!!!!!
// high pass = orginal - low pass
void MultibandCompressor::process(std::vector<float> & t) {
    std::vector<float> lowBand = t;
    std::vector<float> lowMidBand; lowMidBand.resize(t.size());
    std::vector<float> midBand; midBand.resize(t.size());
    std::vector<float> HigMidBand; HigMidBand.resize(t.size());
    std::vector<float> HigBand; HigBand.resize(t.size());
    std::vector<float> rest1; rest1.resize(t.size());
    std::vector<float> rest2; rest2.resize(t.size());
    std::vector<float> rest3; rest3.resize(t.size());

    m_lowCrossover.process(lowBand); // 1 pasmo
    for (int i = 0; i < t.size(); i++) {
        rest1[i] = t[i] - lowBand[i];  // wszystko oprocz pierwszego pasma 4/5 pasma
    }

    lowMidBand = rest1;
    m_lowMidCrossover.process(lowMidBand); // 2 pasmo
    for (int i = 0; i < t.size(); i++) {
        rest2[i] = rest1[i] - lowMidBand[i]; //wszystko oprocz 2 pierwszych pasm 3/5 pasma
    }

    midBand = rest2;
    m_MidCrossover.process(midBand); // pasmo 3
    for (int i = 0; i < t.size(); i++) {
        rest3[i] = rest2[i] - midBand[i]; // osatnie 2 pasma tutaj 2/5 pasma
    }

    HigMidBand = rest3;
    m_HighMidCrossover.process(HigMidBand); // pasmo 4
    for (int i = 0; i < t.size(); i++) {
        HigBand[i] = rest3[i] - HigMidBand[i]; // pasmo 5
    }

    // kompresowanie
    m_compLow.process(lowBand);
    m_compLowMid.process(lowMidBand);
    m_compMid.process(midBand);
    m_compHighMid.process(HigMidBand);
    m_compHigh.process(HigBand);

    // sklejene spowrotem
    for (int i = 0; i < t.size(); i++) {
        t[i] = lowBand[i] + lowMidBand[i] + midBand[i]  + HigMidBand[i] + HigBand[i];
    }
}