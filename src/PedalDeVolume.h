#pragma once
#include "Pedal.h"

class PedalDeVolume : public Pedal {
public:
    PedalDeVolume();

    void setVolume(float novoVolume);

    void processar(std::vector<int16_t>& bufferDeAudio) override;

private:
    float nivelVolume;
};