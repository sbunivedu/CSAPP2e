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

int fun1(unsigned word) {
  return (int) ((word << 24) >> 24);
}

int fun2(unsigned word) {
  return ((int) word << 24) >> 24;
}

/* WARNING: This is buggy code */
float sum_elements(float a[], unsigned length) {
  int i;
  float result = 0;

  for (i = 0; i <= length-1; i++) {
    result += a[i];
  }
  return result;
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
/*
  //int x = -2147483647-1;
  //show_bytes(&x, 4);
  //int y = 2147483648U;
  //show_bytes(&y, 4);
  //printf("%d", -2147483647-1 == 2147483648U);
  //printf("%d",-2147483647-1 < 2147483647);
  //printf("%d",-2147483647-1 < 2147483647);
  //printf("%d\n",-2147483647-1U < 2147483647);
  //int a = -2147483647-1U;
  //show_bytes(&a, 4);
  //printf("%d\n",-2147483647-1 < 2147483647);
  //printf("%d\n",-2147483647-1U < -2147483647);
*/
/*
  int x = 0xEDCBA987;
  //x = fun1(x);
  //printf("%d\n", x);
  //show_bytes(&x, 4);
  x = fun2(x);
  printf("%d\n", x);
  show_bytes(&x, 4);
*/
  float a[] = {1.0,2.0,3.0,4.0,5.0};
  printf("%f\n", sum_elements(a, 0));
  return 0;
}
