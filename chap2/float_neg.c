#include "stdio.h"

typedef union {
  unsigned i;
  float f;
 } u;

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len) {
  int i, j;
  printf("%s", "bytes: ");
  for (i = 0; i < len; i++) {
    printf("%.2x ", start[i]);
  }
  printf("\n");

  // print binary representation
  // most significant bit first
  printf("%s", "bits:  ");
  for (i = len-1; i >= 0; i--) {
    for (j = 7; j >= 0; j--) {
      unsigned char bit = (start[i] >> j) & 1;
      printf("%u", bit);
    }
    printf("%s", " ");
  }
  printf("\n");
}

int main(void) {
  u x;
/*
  x.f = -1;
  show_bytes((byte_pointer) &x, 4);
  printf("%f\n", x.f);

  unsigned mask = 1 << 31;
  x.i = x.i ^ mask;
  show_bytes((byte_pointer) &x, 4);
  printf("%f\n", x.f);
*/

/*
  // +0
  x.f = 0;
  show_bytes((byte_pointer) &x, 4);
  printf("%f\n", x.f);

  unsigned mask = 1 << 31;
  x.i = x.i ^ mask;
  show_bytes((byte_pointer) &x, 4);
  printf("%f\n", x.f);

  x.i = 0x80000000;
  show_bytes((byte_pointer) &x, 4);
  printf("%f\n", x.f);
*/

/*
  // -0
  x.i = 0x80000000;
  show_bytes((byte_pointer) &x, 4);
  printf("%f\n", x.f);

  unsigned mask = 1 << 31;
  x.i = x.i ^ mask;
  show_bytesa((byte_pointer) &x, 4);
  printf("%f\n", x.f);
*/

/*
  // -1.0x2^(-127)
  x.i = 0x80800000;
  show_bytes((byte_pointer) &x.i, 4);
  printf("%.100f\n", x.f);

  unsigned mask = 1 << 31;
  x.i = x.i ^ mask;
  show_bytes((byte_pointer) &x, 4);
  printf("%.100f\n", x.f);
*/

/*
  // Infinity: 0111 1111 1000 0000 0000 0000 0000 0000
  x.i = 0x7f800000;
  show_bytes((byte_pointer) &x, 4);
  printf("%f\n", x.f);

  unsigned mask = 1 << 31;
  x.i = x.i ^ mask;
  show_bytes((byte_pointer) &x, 4);
  printf("%f\n", x.f);
*/

/*
  // NaN: 0111 1111 1000 0000 0000 0000 0000 0001
  x.i = 0x7f800001;
  show_bytes((byte_pointer) &x, 4);
  printf("%f\n", x.f);

  unsigned mask = 1 << 31;
  x.i = x.i ^ mask;
  show_bytes((byte_pointer) &x, 4);
  printf("%f\n", x.f);
*/
}
