//
// Created by mf on 8/23/26.
//

#ifndef OFFLINEDSP_RIFF_H
#define OFFLINEDSP_RIFF_H
#pragma pack(push, 1)
struct Riff {
    char ChunkID[4];        //SYGNATURA FORMATU RIFF
    uint32_t ChunkSize;     //RIZMIAR RESZTY PLIKU
    char Format[4];         //SYGNATURA FORMATU WAVE
    char SubChunk1ID[4];    //SYGNATURA FORMATU FMT
    uint32_t SubChunk1Size; //ROZMIAR SUBCHANK DLA PCM = 16
    uint16_t AudioFormat;   //FORMAT AUDIO (1 = NIESKOMPRESOWANE PCM)
    uint16_t NumChannels;   //LICZBA KANALOW (1 = MONO, 2 = STEREO)
    uint32_t SampleRate;    //SAMPLE RATE - ilosc probek na sekunde
    uint32_t ByteRate;      //ILE BYTE NA SEKUNDE TRZEBA CZYTAC
    uint16_t BlockAlign;    //ROZMIAR JEDNE RAMKI
    uint16_t BitsPerSample; //GLEBIA BITOWA
    char SubChunk2ID[4];    //SYGNATURA SEKCJI DANYCH - ZAWSZE DATA
    uint32_t SubChunk2Size; //ROZMIAR SAMYCH DANYCH AUDIO W BAJTACH ILE BAJTOW ZAJMUJA WSZYSTKIE PROBKI LACZNIE
};
#pragma pack(pop)
#endif //OFFLINEDSP_RIFF_H
