#include "../include/chip8.hpp"
#include <cstdint>
#include <fstream>
#include <iosfwd>
#include <iostream>
void Chip8::LoadROM(char const *filename) {
  std::ifstream file(filename,
                     std::ios::binary |
                         std::ios::ate); // creating a varible "file" putting
                                         // the "filename" inside it
  //

  if (file.is_open()) {
    std::streampos size = file.tellg(); // size of the file
    char *buffer = new char[size];      // buffer to load the rom
    file.seekg(0, std::ios::beg); // make the pointer go back to the beggining
    file.read(buffer, size);
    file.close();

    for (long i = 0; i < size; i++) {
      Chip8::memory[START_ADDRESS + i] = buffer[i];
    }
    delete[] buffer;
  }
}

void Chip8::initialize() {
  Chip8::pc = START_ADDRESS;
  memory[0x200] = 0x65;
  memory[0x201] = 0x7A;
  // 0x610A
};

void Chip8::cycle() {
  // fetch
  Chip8::opcode = memory[pc] << 8 | memory[pc + 1];
  pc += 2;

  // decode //decones varibles done and i have to implement the cycle
  uint8_t x = (opcode & 0x0F00) >> 8; // 0x610A -> 1
  uint8_t y = (opcode & 0x00F0) >> 4; // 0x610A - > 0
  uint8_t n = opcode & 0x000F;        // 0x610A - > A
  uint8_t nn = opcode & 0x00FF;
  uint16_t nnn = opcode & 0x0FFF;
  std::cout << std::hex << static_cast<int>(nn) << std::endl;
  std::cout << std::hex << nnn << std::endl;
};
