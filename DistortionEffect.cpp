//
// Created by mf on 8/23/26.
//

#include "DistortionEffect.h"
#include <algorithm>
#include <functional>

void DistortionEffect::process(std::vector<float> &t) {
    std::transform(t.begin(), t.end(), t.begin(),
        [=](float val) {
        val*= m_gain;
        return std::clamp(val,-1.0f,1.0f);
    });
}
