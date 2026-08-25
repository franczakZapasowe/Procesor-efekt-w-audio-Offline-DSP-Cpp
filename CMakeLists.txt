cmake_minimum_required(VERSION 4.2)
project(OfflineDSP)

set(CMAKE_CXX_STANDARD 23)

add_executable(OfflineDSP main.cpp
        AudioEffect.cpp
        AudioEffect.h
        GainEffect.cpp
        GainEffect.h
        DistortionEffect.cpp
        DistortionEffect.h
        DelayEffect.cpp
        DelayEffect.h
        Riff.h
        LowPassEffect.cpp
        LowPassEffect.h
        CompressorEffect.cpp
        CompressorEffect.h
)
