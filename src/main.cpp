#include <iostream>
#include <SFML/Audio.hpp>
#include "MotorDeAudio.h"
#include "PedalDeVolume.h"



int main() {
    std::cout << "--- Inicializando o Google Atrator ---" << std::endl;

    MotorDeAudio meuMotor;
    PedalDeVolume meuPedalDeVolume;
    meuPedalDeVolume.setVolume(1.0f);
    meuMotor.adicionarPedal(&meuPedalDeVolume);
    meuMotor.iniciarTeste();

    std::cout << "Motor rodando. Pressione ENTER no terminal para desligar." << std::endl;
    std::cin.get(); // Aguarda o usuário pressionar ENTER
    return 0;
}