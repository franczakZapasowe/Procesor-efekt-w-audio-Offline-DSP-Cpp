//
// Created by mf on 8/23/26.
//

#ifndef OFFLINEDSP_GAINEFFECT_H
#define OFFLINEDSP_GAINEFFECT_H
#include "AudioEffect.h"


class GainEffect: public AudioEffect {
    float m_gainMultiply;
    public:
    GainEffect(float gainMultiply):m_gainMultiply(gainMultiply) {};
    void process(std::vector<float> &) override;
};


#endif //OFFLINEDSP_GAINEFFECT_H
