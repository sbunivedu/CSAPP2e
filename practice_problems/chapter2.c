#include <stdio.h>
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

void show_int(int x) {
  show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
  show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
  show_bytes((byte_pointer) &x, sizeof(void *));
}

void inplace_swap(int *x, int *y) {
  *y=*x^*y; /*Step1*/
  *x=*x^*y; /*Step2*/
  *y=*x^*y; /*Step3*/
}

void reverse_array(int a[], int cnt) {
  int first, last;
  for (first = 0, last = cnt-1;
       first < last; first++,last--) {
    inplace_swap(&a[first], &a[last]);
  }
}

void show_int_array(int a[], int len){
  int i;
  for (i = 0; i < len; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

int bis(int x, int m) {
  return x | m;
}

int bic(int x, int m) {
  return x & (~m);
}

/* Compute x|y using only calls to functions bis and bic */
int bool_or(int x, int y) {
  int result = bis(x, y);
  return result;
}
/* Compute x^y using only calls to functions bis and bic */
int bool_xor(int x, int y) {
  int result = bis(bic(x,y), bic(y,x));
  // a ^ b = (a & ~b) | (~a & b)
  return result;
}

/* if x == y return 1, otherwise return 0 */
int equal(int x, int y) {
  return !(x^y);
}

int main(void) {
/*
  int a = ~0x69;
  int b = ~0x55;
  int c = a&b;
  show_bytes((byte_pointer) &c, 1);
*/
/*
  int a[] = {1,2,3,4,5};
  show_int_array(a, 5);
  reverse_array(a, 5);
  show_int_array(a, 5);
*/
/*
  //int a = 0x87654321;
  //int a = 0x87654321 & 0xff;
  //int a = 0x87654321 & ~(0xff);
  int a = 0x87654321 | 0xff;
  show_bytes(&a, 4);
*/
/*
  int a = 0x87654321;
  show_bytes(&a, 4);
  int b = 0xffffffff;
  show_bytes(&b, 4);
  int c = bool_xor(a, b);
  show_bytes(&c, 4);
*/
/*
  int y = 0x39;
  //int y = !0x39;
  //show_bytes(&y, 4);
  int x = 0x66;
  //int y = !0x00;
  int z = x && ~y;
  show_bytes(&z, 4);
*/
/*
  int x = 0x39;
  //int y = 0x39;
  int y = 0x40;
  printf("equal? %d\n", equal(x,y));
*/
  return 0;
}