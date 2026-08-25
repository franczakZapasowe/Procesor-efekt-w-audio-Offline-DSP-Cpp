//
// Created by mf on 8/25/26.
//

#include "CompressorEffect.h"
#include <cmath>

// ogolnie najpierw robimy fabs bo wartosc -0.8 i 0.8 to to samo dla dzwieku tylko z innej strony fali
// jezeli nasze temp = 0 poimijamy bo byl crash log 10 (10)
// teraz sprawdzamy czy nasza waertosc db > threshold jezeli tak to liczymy o ile - overshoot
// nasz docelowy gain o jaki maamy sciszyc to overshot - overshot/ratio - gr

void CompressorEffect::process(std::vector<float> &t) {
    float temp = 0;
    float gr = 0;
    float overShoot= 0;
    float db = 0;
    float targetMultiplier = 1;
    for (int i=0; i<t.size(); i++) {
        temp = std::fabs(t[i]);
        if (temp ==0) targetMultiplier = 1.0f;
        else {
            db = 20 * std::log10(temp);
            if (db>m_threshold) {
                overShoot = db - m_threshold;
                gr = overShoot - overShoot/m_ratio;
                targetMultiplier = std::pow(10, -gr/20.0f);
            }else {
                targetMultiplier = 1.0f;
            }
        }
        if (targetMultiplier < m_currentGain) {
            m_currentGain = m_alfaAttack * m_currentGain + (1- m_alfaAttack)  * targetMultiplier;
        }else if (targetMultiplier > m_currentGain) {
            m_currentGain = m_alfaRelese* m_currentGain + (1- m_alfaRelese) * targetMultiplier ;
        }
        t[i]*=m_currentGain;
    }
}
