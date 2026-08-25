//
// Created by mf on 8/25/26.
//

#ifndef OFFLINEDSP_COMPRESSOREFFECT_H
#define OFFLINEDSP_COMPRESSOREFFECT_H
#include <vector>
#include "Riff.h"
#include <cmath>
class CompressorEffect {
    float m_threshold;
    float m_ratio;
    float m_attack;
    float m_release;
    Riff m_riff;
    float m_currentGain = 1.0;
    float m_alphaAttack;
    float m_alphaRelease;
public:
    CompressorEffect(float threshold, float ratio, float attack, float release, Riff riff)
    :m_threshold(threshold), m_ratio(ratio),m_attack(attack),m_release(release),m_riff(riff) {
        m_alphaAttack = std::exp(-1000.0f / (riff.SampleRate *attack ) );
        m_alphaRelease = std::exp(-1000.0f / (riff.SampleRate *release));
    };
    void process(std::vector<float>& data);
};


#endif //OFFLINEDSP_COMPRESSOREFFECT_H
