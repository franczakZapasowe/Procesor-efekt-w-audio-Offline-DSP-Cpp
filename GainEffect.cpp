//
// Created by mf on 8/23/26.
//

#include "GainEffect.h"
#include <algorithm>
void GainEffect::process(std::vector<float> &data) {
    std::transform(data.begin(), data.end(), data.begin(),[=](float x) {
    return x * m_gainMultiply;
});
}
