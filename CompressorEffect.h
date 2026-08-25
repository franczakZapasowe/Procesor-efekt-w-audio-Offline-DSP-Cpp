//
// Created by mf on 8/25/26.
//
#pragma once

#include <vector>
#include "Riff.h"
#include <cmath>

#include "AudioEffect.h"

class CompressorEffect : public AudioEffect {
    float m_attack;
    float m_relese;
    float m_threshold;
    float m_ratio;
    float m_alfaAttack;
    float m_alfaRelese;
    float m_currentGain = 1.0f;
    Riff m_riff;
    public:
    CompressorEffect(float atack, float relese, float threshold, float ratio, Riff riff)
        : m_attack(atack),m_relese(relese),m_threshold(threshold),m_ratio(ratio),m_riff(riff)
    {
        m_alfaAttack = std::exp(-1000.0f /(riff.SampleRate * atack) );
        m_alfaRelese = std::exp(-1000.0f / (riff.SampleRate * relese) );
    }
    void process(std::vector<float> &) override;

};

