#pragma once

#include <cstdint>

class Chip8 {
public:
  void initialize();
  void cycle();
  void LoadROM(char const *filename);

private:
  const unsigned int START_ADDRESS = 0x200;
  uint8_t registers[16]{};
  uint8_t memory[4096]{};
  uint16_t index_register{};
  uint16_t pc{};
  uint16_t opcode;
  uint16_t stack[16]{};
  uint8_t sp{};
};
