//
// Created by mf on 8/23/26.
//

#ifndef OFFLINEDSP_DELAYEFFECT_H
#define OFFLINEDSP_DELAYEFFECT_H
#include "AudioEffect.h"
#include "Riff.h"

// tak napradwe to musimy skopiowac to co mamy w buforze
// w szufladce do tyłu o  offset, sciszyc to i dodac do tego co jest w aktualnym
class DelayEffect: public AudioEffect{
    float m_delayGain;
    Riff m_riff;
    float m_delayTime; // w millisekundach
    int m_offset;
public:
    // sample rate - ile probek w sekunde - u nas 48000
    // ile probek(indeksow w tablicy) w miliskunde - sample rate / 1000
    // ile trwa delay - ilosc probek z punktu wyzej * delay TIme (na pokretlo ustawiam np 200ms)
    // mamyh plik stero - 2 kanały kazda klata to w wektorze 2 probki lewy kanal i prawy czyli * 2
    DelayEffect(float delayGain,Riff riff,float delayTime)
    :m_delayGain(delayGain),m_riff(riff), m_delayTime(delayTime) {
        float ileProbek = riff.SampleRate/1000.0f;  //ile probek w jednej milisekundzie
        m_offset = ileProbek * delayTime * riff.NumChannels;
    };

    void process(std::vector<float> &) override;

};


#endif //OFFLINEDSP_DELAYEFFECT_H
