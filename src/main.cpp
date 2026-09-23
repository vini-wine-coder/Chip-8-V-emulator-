#include "../include/chip8.hpp"
int main() {
  Chip8 chip8;
  chip8.LoadROM("/home/wine/Projects/Chip8_emu/src/testefile.txt");
  chip8.initialize();
  chip8.cycle();
  return 0;
}
