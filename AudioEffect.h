//
// Created by mf on 8/23/26.
//

#ifndef OFFLINEDSP_AUDIOEFFECT_H
#define OFFLINEDSP_AUDIOEFFECT_H
#include <vector>

class AudioEffect {
    public:
    virtual void process(std::vector<float>&) = 0;
    virtual ~AudioEffect() {};
};


#endif //OFFLINEDSP_AUDIOEFFECT_H
