//
// Created by mf on 8/23/26.
//

#ifndef OFFLINEDSP_DISTORTIONEFFECT_H
#define OFFLINEDSP_DISTORTIONEFFECT_H
#include "AudioEffect.h"

//hard cliper 
class DistortionEffect: public AudioEffect{
    float m_gain;
    public:
    DistortionEffect(float gain):m_gain(gain){};
    void process(std::vector<float>&) override;
};


#endif //OFFLINEDSP_DISTORTIONEFFECT_H
