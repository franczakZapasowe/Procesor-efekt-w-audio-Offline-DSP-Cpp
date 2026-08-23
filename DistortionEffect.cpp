//
// Created by mf on 8/23/26.
//

#include "DistortionEffect.h"

#include <algorithm>
#include <functional>

void DistortionEffect::process(std::vector<float> &tab) {
    std::transform(tab.begin(), tab.end(), tab.begin(),[&](float v) {
        v*=m_gain;
        return std::clamp(v, -1.0f, 1.0f);
    });
}