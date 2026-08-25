//
// Created by mf on 8/25/26.
//

#ifndef OFFLINEDSP_COMPRESSOREFFECT_H
#define OFFLINEDSP_COMPRESSOREFFECT_H
#include <vector>
#include "Riff.h"

class CompressorEffect {
    float m_threshold;
    float m_ratio;
    float m_attack;
    float m_release;
    Riff riff;
    float m_currentGain = 1.0;
public:
    CompressorEffect(float threshold, float ratio, float attack, float release)
    :m_threshold(threshold), m_ratio(ratio),m_attack(attack),m_release(release){};
    void process(std::vector<float>& data);
};


#endif //OFFLINEDSP_COMPRESSOREFFECT_H
