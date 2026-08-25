//
// Created by mf on 8/25/26.
//

#include "CompressorEffect.h"
#include <cmath>

// ogolnie najpierw robimy fabs bo wartosc -0.8 i 0.8 to to samo dla dzwieku tylko z innej strony fali
// jezeli nasze temp = 0 poimijamy bo byl crash log 10 (10)
// teraz sprawdzamy czy nasza waertosc db > threshold jezeli tak to liczymy o ile - overshoot
// nasz docelowy gain o jaki maamy sciszyc to overshot - overshot/ratio - gr
void CompressorEffect::process(std::vector<float> &data) {
    float temp = 0;
    float db = 0;
    float overshot = 0;
    float gr;
    float multiplier = 1.0;
    for (int i = 0; i < data.size(); i++) {
        temp = std::fabs(data[i]);
        if (temp == 0) multiplier = 1.0f;
        else {
            db = 20.0f * std::log10(temp);
            if (db >  m_threshold) {
                overshot = db - m_threshold;    // o ile
                gr = overshot - overshot/m_ratio; // tu pracujemy na decybelach
                multiplier = std::pow(10 , (-gr/20)); // przeliczamy z db na jezyk 0 - 1
            } else multiplier = 1.0f;
        }
        if (multiplier < m_currentGain) { // atack
            m_currentGain = (m_alphaAttack * m_currentGain) + ((1.0f - m_alphaAttack)*multiplier);
        }else if (multiplier > m_currentGain) { //relese
            m_currentGain = (m_alphaRelease * m_currentGain) + ((1.0f - m_alphaRelease)*multiplier);
        }
        data[i] *=m_currentGain;
    }
}
