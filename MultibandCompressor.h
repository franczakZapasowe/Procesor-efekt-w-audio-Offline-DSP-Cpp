//
// Created by mf on 8/26/26.
//

#ifndef OFFLINEDSP_MULTIBANDCOMPRESSOR_H
#define OFFLINEDSP_MULTIBANDCOMPRESSOR_H
#include "AudioEffect.h"
#include "CompressorEffect.h"
#include "LowPassEffect.h"

class MultibandCompressor: public AudioEffect {
    LowPassFilter m_lowCrossover;
    LowPassFilter m_lowMidCrossover;
    LowPassFilter m_MidCrossover;
    LowPassFilter m_HighMidCrossover;


    CompressorEffect m_compLow;
    CompressorEffect m_compLowMid;
    CompressorEffect m_compMid;
    CompressorEffect m_compHighMid;
    CompressorEffect m_compHigh;
    public:

    MultibandCompressor(LowPassFilter lowCrossower, LowPassFilter lowMidCrossover, LowPassFilter midCrossover, LowPassFilter MidHighCrossover,
                    CompressorEffect compLow,CompressorEffect compLowMid,CompressorEffect compMid, CompressorEffect compHighMid, CompressorEffect compHigh)
                        :m_lowCrossover(lowCrossower), m_lowMidCrossover(lowMidCrossover),m_MidCrossover(midCrossover),m_HighMidCrossover(MidHighCrossover),
                        m_compLow (compLow), m_compLowMid(compLowMid),m_compMid(compMid),m_compHighMid(compHighMid),m_compHigh(compHigh)
                        {
                    
                        }
    void process(std::vector<float> &) override;
};


#endif //OFFLINEDSP_MULTIBANDCOMPRESSOR_H
