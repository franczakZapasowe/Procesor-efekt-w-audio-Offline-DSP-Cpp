//
// Created by mf on 8/26/26.
//

#include "EqualizerEffect.h"
// y[n] = (b_0  *x[n]) + (b_1 * x[n-1]) + (b_2 * [n-2]) - (a_1  *y[n-1]) - (a_2 * y[n-2])

void EqualizerEffect::process(std::vector<float> & t) {
    int index = 0;
    for (int i = 0; i < t.size(); i++) {
        index = i%2;
        if (index == 0) { // lewe
            float temp = t[i];
            t[i] = (m_b0 * t[i]) + (m_b1 * m_x1_L) + (m_b2 * m_x2_L)  - (m_a1 * m_y1_L) - (m_a2 * m_y2_L);
            m_x2_L = m_x1_L;
            m_x1_L = temp;
            m_y2_L = m_y1_L;
            m_y1_L = t[i];
        }else { //prawe
            float temp = t[i];
            t[i] = (m_b0 * t[i]) + (m_b1 * m_x1_R) + (m_b2 * m_x2_R)  - (m_a1 * m_y1_R) - (m_a2 * m_y2_R);
            m_x2_R = m_x1_R;
            m_x1_R = temp;
            m_y2_R = m_y1_R;
            m_y1_R = t[i];
        }
    }
}
