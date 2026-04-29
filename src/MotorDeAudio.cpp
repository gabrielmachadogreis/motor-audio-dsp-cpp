#include "MotorDeAudio.h"


MotorDeAudio::MotorDeAudio() {
    
    cursorDeReproducao = 0;
    estaLigado =false;
    std::cout << "A planta do motor foi construida na memoria!"<<std::endl;

    initialize(1, 44100, {sf::SoundChannel::Mono});
}

void MotorDeAudio::iniciarTeste() {
  sf::InputSoundFile arquivoOriginal;

  if(!arquivoOriginal.openFromFile("assets/teste.wav")){
    std::cout << "ERRO FATAL: Arquivo nao encontrado!" << std::endl;
    return;
  }

  bufferDeAudio.resize( arquivoOriginal.getSampleCount() );
  uint64_t amostrasLidas = arquivoOriginal.read(bufferDeAudio.data(), arquivoOriginal.getSampleCount());

    // 3. Valida se a leitura foi perfeita
    if (amostrasLidas != arquivoOriginal.getSampleCount()) {
        std::cout << "AVISO: O arquivo nao foi lido por completo!" << std::endl;
    }

    // 4. Imprime o sucesso
    std::cout << "Tamanho do buffer carregado: " << amostrasLidas << " amostras." << std::endl;
    play();
}

bool MotorDeAudio::onGetData(Chunk& data) {
    if(cursorDeReproducao >= bufferDeAudio.size()){
        return false;
    }

    data.sampleCount = bufferDeAudio.size() - cursorDeReproducao;
    
    bufferDeProcessamento.resize(data.sampleCount);
    for(int i = 0; i <bufferDeProcessamento.size(); i++){
        bufferDeProcessamento[i] = bufferDeAudio[cursorDeReproducao +i];
    }

    for(Pedal* pedal : pedais){
        pedal->processar(bufferDeProcessamento);
    }
    data.samples = bufferDeProcessamento.data();
    cursorDeReproducao += data.sampleCount;
    return true;
    
}

void MotorDeAudio::onSeek(sf::Time timeOffset){

}

void MotorDeAudio::adicionarPedal(Pedal* pedal) {
    pedais.push_back(pedal);
}

