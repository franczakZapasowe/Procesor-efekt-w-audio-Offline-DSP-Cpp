//
// Created by mf on 8/23/26.
//
#pragma once
#include "AudioEffect.h"
#include "Riff.h"

// tak napradwe to musimy skopiowac to co mamy w buforze
// w szufladce do tyłu o  offset, sciszyc to i dodac do tego co jest w aktualnym
    // sample rate - ile probek w sekunde - u nas 48000
    // ile probek(indeksow w tablicy) w miliskunde - sample rate / 1000
    // ile trwa delay - ilosc probek z punktu wyzej * delay TIme (na pokretlo ustawiam np 200ms)
    // mamyh plik stero - 2 kanały kazda klata to w wektorze 2 probki lewy kanal i prawy czyli * 2
class DelayEffect : public AudioEffect {
    float m_offset;
    float m_gain;
    float m_delay; // ile ms ma trwac
    Riff m_riff;
    public:
    DelayEffect(float gain, float delay, Riff riff)
        :m_gain(gain), m_delay(delay), m_riff(riff)
    {
        m_offset = (m_riff.SampleRate/1000) * m_delay * m_riff.NumChannels;
    }
    void process(std::vector<float> &) override;
};



