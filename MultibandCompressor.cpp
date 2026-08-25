//
// Created by mf on 8/26/26.
//

#include "MultibandCompressor.h"
#include <vector>
// obiektowka is wining omg for real!!!!!!!!!!!
// high pass = orginal - low pass
void MultibandCompressor::process(std::vector<float> & t) {
    std::vector<float> lowBand = t;
    std::vector<float> highBand; highBand.resize(t.size());
    m_crossover.process(lowBand);
    for (int i = 0; i < t.size(); i++) {
        highBand[i] = t[i] - lowBand[i];
    }
    m_compLow.process(lowBand);
    m_compHigh.process(highBand);

    for (int i = 0; i < t.size(); i++) {
        t[i] = lowBand[i] + highBand[i];
    }
}