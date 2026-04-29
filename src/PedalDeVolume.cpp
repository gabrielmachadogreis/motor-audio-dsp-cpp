#include "PedalDeVolume.h"

PedalDeVolume::PedalDeVolume(){
    nivelVolume = 1.0f; // Volume padrão
}

void PedalDeVolume::setVolume(float novoVolume){
    nivelVolume = novoVolume;
}

void PedalDeVolume::processar(std::vector<int16_t>& bufferDeAudio){
    for(int i = 0; i < bufferDeAudio.size(); i++){
        bufferDeAudio[i] = bufferDeAudio[i] * nivelVolume; // Aplica o volume
    }
}