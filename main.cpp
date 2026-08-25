#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

#include "DelayEffect.h"
#include "GainEffect.h"
#include "Riff.h"
#include "DistortionEffect.h"
#include "LowPassEffect.h"

int main() {
    Riff riff;
    FILE * plik = fopen("Bell 6 (IIInfinite).wav", "rb");
    if (plik==nullptr) {
        std::cerr<<"NIe mozna otworzyc pliku\n";
        return 0;
    }
    fread(&riff, sizeof(riff), 1, plik);
    int numSample = riff.SubChunk2Size/sizeof(float);   // nasz plik wav jest 32 - bitowy
    std::vector<float> data(numSample);
    fread(data.data(), sizeof(float), numSample, plik);
    fclose(plik);
    std::cout<<"Sample rate: "<<riff.SampleRate<<" Num. Chanel: "<<riff.NumChannels<<"\n";
    /*
        Pomnożenie próbki przez 1.0 zostawia dźwięk bez zmian.
        Pomnożenie próbki przez 0.5 ścisza dźwięk o połowę (ok. -6 dB).
        Pomnożenie próbki przez 2.0 podgłaśnia go dwukrotnie (ok. +6 dB - tu uwaga,
        bo na głośnym pliku przesterujesz sygnał powyżej cyfrowego zera, czyli wartości 1.0 lub -1.0).
    */

   // GainEffect gEffect(0.5);
    //gEffect.process(data);

    // DelayEffect delay(0.5,riff,200);
    // delay.process(data);

    // DistortionEffect distrotion(5.0);
    // distrotion.process(data);

    LowPassEffect lowPass (1);
    lowPass.process(data);

    plik = fopen("Sciszony_Bell.wav", "wb");
    if (plik==nullptr) {
        std::cerr<<"NIe mozna otworzyc pliku\n";
        return 0;
    }
    fwrite(&riff, sizeof(riff), 1, plik);
    fwrite(data.data(), sizeof(float), numSample, plik);
    fclose(plik);

}