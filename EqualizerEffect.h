//
// Created by mf on 8/26/26.
//

#ifndef OFFLINEDSP_EQUALIZEREFFECT_H
#define OFFLINEDSP_EQUALIZEREFFECT_H
#include "AudioEffect.h"
#include "Riff.h"
#include <cmath>
#include <numbers>

// y[n] = (b_0  *x[n]) + (b_1 * x[n-1]) + (b_2 * [n-2]) - (a_1  *y[n-1]) - (a_2 * y[n-2])
class EqualizerEffect : public AudioEffect {
    float m_A;
    float m_w0;
    float m_alfa;

    float m_b0;
    float m_b1;
    float m_b2;
    float m_a0;
    float m_a1;
    float m_a2;

    float m_gain; //wzmocnienie
    float n_Fc; // CZESTOTLIWOSC
    float m_Q; // szerokosc

    //zmienne histroyczny
    float m_x1_L ={}; // poprzednia klatka wejsciowa
    float m_x2_L ={}; // orzedostania wejsciowa
    float m_y1_L ={}; // ostatnia wyjsciowa
    float m_y2_L ={}; // przedostania wyjsciowafloat

    float m_x1_R ={}; // poprzednia klatka wejsciowa
    float m_x2_R ={}; // orzedostania wejsciowa
    float m_y1_R ={}; // ostatnia wyjsciowa
    float m_y2_R ={}; // przedostania wyjsciowa


public:
    void process(std::vector<float> &) override;
    EqualizerEffect(float gain, float Fc, float Q):m_gain(gain), n_Fc(Fc),m_Q(Q) {
        m_A = std::pow(10, gain/40.0f);
        m_w0 = 2 * std::numbers::pi_v<float> *Fc/44100.0f; // czestotliowsc probkowania = 404100.0f
        m_alfa = std::sin(m_w0) / (2.0f * Q);
        m_b0 = 1 + m_alfa * m_A;
        m_b1 = -2 *std::cos(m_w0);
        m_b2 = 1 - m_alfa*m_A;
        m_a0 = 1 + m_alfa/m_A;
        m_a1 = -2 * std::cos(m_w0);
        m_a2 = 1 - m_alfa/m_A;

        m_b0 /= m_a0;
        m_b1 /= m_a0;
        m_b2 /= m_a0;
        m_a1 /= m_a0;
        m_a2 /= m_a0;
    }
};


#endif //OFFLINEDSP_EQUALIZEREFFECT_H
