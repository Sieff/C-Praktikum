#include <stdint.h>
#include <stdio.h>
#include <string.h>

void printBytes(void* data, int byteCount) {
  uint8_t* bytes = data;
  printf("%016zx:", (uintptr_t)data);
  for(int i = 0; i < byteCount; i++) {
    printf(" %02x", bytes[i]);
  }
  printf(" \"");
  for(int i = 0; i < byteCount; i++) {
    printf("%c", bytes[i]);
  }
  printf("\"\n");
}

int main(int argc, char** argv) {
  printf("argc:"); printBytes(&argc, sizeof(argc));
  printf("argv:"); printBytes(&argv, sizeof(argv));
  printf("*argv:"); printBytes(argv, argc*sizeof(*argv));
  for(int i = 0; i < argc; i++) {
    printf("*argv[%d]:", i); printBytes(argv[i], strlen(argv[i]) + 1);
  }
}
