#ifndef OFFLINEDSP_GAINEFFECT_H
#define OFFLINEDSP_GAINEFFECT_H
#include "AudioEffect.h"
class GainEffect: public AudioEffect {
    float m_gain;
public:
    GainEffect(float gain):m_gain(gain){};
    void process(std::vector<float> &) override;
};
#endif //OFFLINEDSP_GAINEFFECT_H
