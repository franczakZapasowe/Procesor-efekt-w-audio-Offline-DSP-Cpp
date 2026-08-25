//
// Created by mf on 8/26/26.
//

#ifndef OFFLINEDSP_MULTIBANDCOMPRESSOR_H
#define OFFLINEDSP_MULTIBANDCOMPRESSOR_H
#include "AudioEffect.h"
#include "CompressorEffect.h"
#include "LowPassEffect.h"

class MultibandCompressor: public AudioEffect {
    LowPassFilter m_crossover;
    CompressorEffect m_compLow;
    CompressorEffect m_compHigh;
    public:
    MultibandCompressor(const LowPassFilter &crossover, const CompressorEffect &compLow, const CompressorEffect &compHigh)
        : m_crossover(crossover), m_compLow(compLow), m_compHigh(compHigh){}
    void process(std::vector<float> &) override;
};


#endif //OFFLINEDSP_MULTIBANDCOMPRESSOR_H
