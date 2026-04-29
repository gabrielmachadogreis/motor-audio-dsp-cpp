cmake_minimum_required(VERSION 3.20)

# O nome do nosso projeto
project(Pedalboard)

# Força o uso do C++ moderno
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. CORREÇÃO AQUI: Componentes com Letra Maiúscula e sem exigir versão 3.
find_package(SFML COMPONENTS Graphics Window Audio System REQUIRED)

# 2. Pega todos os seus arquivos .cpp da pasta src magicamente
file(GLOB_RECURSE SOURCES "src/*.cpp")

# 3. CORREÇÃO AQUI: Removida a duplicação do main.cpp que o CLion fez
add_executable(Pedalboard ${SOURCES})

# 4. Pluga os cabos da SFML no seu executável
target_link_libraries(Pedalboard PRIVATE SFML::Graphics SFML::Window SFML::Audio SFML::System)