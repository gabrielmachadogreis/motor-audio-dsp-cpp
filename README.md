# Motor de Processamento Digital de Sinais (DSP) em C++

Este repositório contém a fundação arquitetural de um motor de áudio de baixo nível em desenvolvimento. O objetivo do sistema é atuar como uma *Pedalboard* virtual, interceptando, processando e modulando sinais de áudio por meio de algoritmos matemáticos antes do roteamento para a saída física.

## ⚙️ Arquitetura e Engenharia Aplicada
* **Linguagem:** C++ (Foco em gerenciamento manual de memória e performance de processamento em tempo real).
* **Toolchain:** Compilação nativa via `MinGW-w64` / `UCRT64` em ambiente MSYS2.
* **Orquestração:** `CMake` para estruturação e linkagem de bibliotecas externas (SFML).
* **Estado Atual:** Infraestrutura de I/O de áudio validada. Leitura e alocação de *buffers* de áudio na memória em funcionamento. Implementação dos algoritmos matemáticos de modulação (ganho, atenuação, delay) em andamento.
