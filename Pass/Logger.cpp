#include <stdio.h>


extern "C" void trace(const char* instr1, const char* instr2) {
  printf("%s -> %s\n", instr1, instr2);
}
