#pragma once
#include <vector>
#include <cstdint>  


class Pedal{
public:

    virtual void processar(std::vector<int16_t>& bufferDeAudio) =0;

    virtual ~Pedal() = default;
};