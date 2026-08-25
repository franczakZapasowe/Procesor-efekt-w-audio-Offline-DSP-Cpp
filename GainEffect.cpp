//
// Created by mf on 8/23/26.
//

#include "GainEffect.h"
#include <algorithm>
void GainEffect::process(std::vector<float> &t) {
    for (int i = 0; i < t.size(); i++) t[i]*=m_gain;
}

