#pragma once

#include <iostream>
#include <SFML/Audio.hpp>
#include <vector>
#include <cstdint>
#include "Pedal.h"

class MotorDeAudio : public sf::SoundStream{
public:

    MotorDeAudio();

    void iniciarTeste();

    void adicionarPedal(Pedal* pedal);

protected:

    virtual bool onGetData(Chunk& data) override;
    virtual void onSeek(sf::Time timeOffset) override;

private:
    bool estaLigado;
    std::vector<int16_t> bufferDeAudio;
    std::vector<int16_t> bufferDeProcessamento;
    uint64_t cursorDeReproducao;
    std::vector<Pedal*> pedais;
};