### Practice Problem 2.1
Perform the following number conversions:
* A. ```0x39A7F8``` to binary
* B. Binary ```1100100101111011``` to hexadecimal
* C. ```0xD5E4C``` to binary
* D. Binary ```1001101110011110110101``` to hexadecimal

### Practice Problem 2.2
Fill in the blank entries in the following table, giving the decimal and
hexadecimal representations of different powers of 2:

| n | 2<sup>n</sup>(Decimal) | 2<sup>n</sup>(Hexadecimal) |
| :---: | :------------: | :----: |
| 9 | 512 | 0x200 |
| 19 | | |
| | 16,384 | |
| 17 | | |
| | 32 | |
| | | 0x80 |

### Practice Problem 2.3
A single byte can be represented by two hexadecimal digits. Fill in the missing
entries in the following table, giving the decimal, binary, and hexadecimal
values of different byte patterns:

| Decimal | Binary | Hexadecimal |
| :-----: | :----: | :---------: |
| 0 | 0000 0000 | 0x00 |
| 167 | | |
| 62 | | |
| 188 | | |
| | 0011 0111 | |
| | 1000 1000 | |
| | 1111 0011 | |
| | | 0x52 |
| | | 0xAC |
| | | 0xE7 |

### Practice Problem 2.4
Without converting the numbers to decimal or binary, try to solve the following
arithmetic problems, giving the answers in hexadecimal. __Hint__: Just modify the
methods you use for performing decimal addition and subtraction to use base 16.
* A. ```0x503c + 0x8 =```
* B. ```0x503c − 0x40 =```
* C. ```0x503c + 64 =```
* D. ```0x50ea − 0x503c =```


### Practice Problem 2.5
Consider the following three calls to show_bytes:
```
int val = 0x87654321;
byte_pointer valp = (byte_pointer) &val;
show_bytes(valp, 1); /* A. */
show_bytes(valp, 2); /* B. */
show_bytes(valp, 3); /* C. */
```
Indicate which of the following values will be printed by each call on a
little-endian machine and on a big-endian machine:
* A. Little endian:__________ Big endian:__________
* B. Little endian:__________ Big endian:__________
* C. Little endian:__________ Big endian:__________

### Practice Problem 2.6
Using show_int and show_float, we determine that the integer 3510593 has
hexadecimal representation ```0x00359141```, while the floating-point number
3510593.0 has hexadecimal representation ```0x4A564504```.
* A. Write the binary representations of these two hexadecimal values.
* B. Shift these two strings relative to one another to maximize the number of
  matching bits. How many bits match?
* C. What parts of the strings do not match?

### Practice Problem 2.7
What would be printed as a result of the following call to show_bytes?
```
const char *s = "abcdef";
show_bytes((byte_pointer) s, strlen(s));
```
Note that letters ‘a’ through ‘z’ have ASCII codes 0x61 through 0x7A.

### Practice Problem 2.8
Fill in the following table showing the results of evaluating Boolean operations
on bit vectors.

| Operation | Result |
| :-------: | :----: |
| a | [01101001] |
| b | [01010101] |
| ~a | |
| ~b | |
| a&b | |
| a&#124;b | |
| a^b | |

### Practice Problem 2.10
As an application of the property that ```a ^ a = 0``` for any bit vector a,
consider the following program:
```
void inplace_swap(int *x, int *y) {
  *y=*x^*y; /*Step1*/
  *x=*x^*y; /*Step2*/
  *y=*x^*y; /*Step3*/
}
```
As the name implies, we claim that the effect of this procedure is to swap the
values stored at the locations denoted by pointer variables x and y. Note that
unlike the usual technique for swapping two values, we do not need a third
location to temporarily store one value while we are moving the other. There is
no performance advantage to this way of swapping; it is merely an intellectual
amusement.

Starting with values a and b in the locations pointed to by x and y,
respectively, fill in the table that follows, giving the values stored at the
two locations after each step of the procedure. Use the properties of ^ to show
that the desired effect is achieved. Recall that every element is its own
additive inverse (that is, ```a ^ a = 0```).

| Step | *x | *y |
| :--: | :-: | :--: |
| Initially | a | b |
| Step 1 | | |
| Step 2 | | |
| Step 3 | | |

### Practice Problem 2.11
Armed with the function inplace_swap from Problem 2.10, you decide to write
code that will reverse the elements of an array by swapping elements from
opposite ends of the array, working toward the middle.
You arrive at the following function:
```
void reverse_array(int a[], int cnt) {
  int first, last;
  for (first = 0, last = cnt-1;
       first <= last; first++,last--) {
    inplace_swap(&a[first], &a[last]);
  }
}
```
When you apply your function to an array containing elements 1, 2, 3, and 4,
you find the array now has, as expected, elements 4, 3, 2, and 1. When you try
it on an array with elements 1, 2, 3, 4, and 5, however, you are surprised to
see that the array now has elements 5, 4, 0, 2, and 1. In fact, you discover
that the code always works correctly on arrays of even length, but it sets the
middle element to 0 whenever the array has odd length.
* A. For an array of odd length ```cnt = 2k + 1```, what are the values of
  variables ```first``` and ```last``` in the final iteration of function
  ```reverse_array```?
* B. Why does this call to function ```inplace_swap``` set the array element to 0?
* C. What simple modification to the code for ```reverse_array``` would
  eliminate this problem?

### Practice Problem 2.12
Write C expressions, in terms of variable ```x```, for the following values. Your
code should work for any word size ```w ≥ 8```. For reference, we show the
result of evaluating the expressions for ```x = 0x87654321```, with ```w = 32```.
* A. The least significant byte of ```x```, with all other bits set to 0.
  ```[0x00000021]```.
* B. All but the least significant byte of ```x``` complemented, with the least
  significant byte left unchanged. ```[0x789ABC21]```.
* C. The least significant byte set to all 1s, and all other bytes of ```x```
  left unchanged. ```[0x876543FF]```.

### Practice Problem 2.13
The Digital Equipment VAX computer was a very popular machine from the late
1970s until the late 1980s. Rather than instructions for Boolean operations
```And``` and ```Or```, it had instructions ```bis``` (bit set) and ```bic```
(bit clear). Both instructions take a data word ```x``` and a mask word ```m```.
They generate a result ```z``` consisting of the bits of ```x``` modified
according to the bits of ```m```. With ```bis```, the modification involves
setting ```z``` to ```1``` at each bit position where ```m``` is ```1```.
With ```bic```, the modification involves setting ```z``` to ```0``` at each
bit position where ```m``` is ```1```.

To see how these operations relate to the C bit-level operations, assume we
have functions ```bis``` and ```bic``` implementing the bit set and bit clear
operations, and that we want to use these to implement functions computing
bit-wise operations ```|``` and ```^```, without using any other C operations.
Fill in the missing code below. *Hint*: Write C expressions for the operations
```bis``` and ```bic```.
```
/* Declarations of functions implementing operations bis and bic */
int bis(int x, int m);
int bic(int x, int m);

/* Compute x|y using only calls to functions bis and bic */
int bool_or(int x, int y) {
  int result =     ;
  return result;
}
/* Compute x^y using only calls to functions bis and bic */
int bool_xor(int x, int y) {
  int result =     ;
  return result;
}
```

### Practice Problem 2.14
Suppose that x and y have byte values ```0x66``` and ```0x39```, respectively.
Fill in the following table indicating the byte values of the different C
expressions:

| Expression | Value | Expression | Value |
| :--: | :-: | :--: | :--: |
| x & y | | x && y | |
| x &#124; y | | x &#124;&#124; y | |
| ~x &#124; ~y | | !x &#124;&#124; !y | |
| x & !y | | x && ~y | |

### Practice Problem 2.15
Using only bit-level and logical operations, write a C expression that is
equivalent to ```x == y```. In other words, it will return 1 when ```x``` and
```y``` are equal, and 0 otherwise.

### Practice Problem 2.16
Fill in the table below showing the effects of the different shift operations
on single-byte quantities. The best way to think about shift operations is to
work with binary representations. Convert the initial values to binary, perform
the shifts, and then convert back to hexadecimal. Each of the answers should be
8 binary digits or 2 hexadecimal digits.

| x | x << 3 | x >> 2 (Logical) | x >> 2 (Arithmetic) |
| :--: | :--: | :--: | :--: |
| 0111 0101 | | | |
| 1000 0111 | | | |
| 0110 0110 | | | |

### Practice Problem 2.17
Assuming ```w = 4```, we can assign a numeric value to each possible hexadecimal
digit, assuming either an unsigned or a two’s-complement interpretation.
Fill in the following table according to these interpretations by writing out
the nonzero powers of two in the summations:

| Hexadecimal | Binary | Unsigned | 2’s-complement |
| :--: | :--: | :--: | :--: |
| 0xE | [1110] | 2<sup>3</sup>+2<sup>2</sup>+2<sup>1</sup>=14 | −2<sup>3</sup>+2<sup>2</sup>+2<sup>1</sup>=−2 |
| 0x0 | | | |
| 0x5 | | | |
| 0x8 | | | |
| 0xD | | | |
| 0xF | | | |

### Practice Problem 2.21
Assuming the expressions are evaluated on a 32-bit machine that uses
two’s-complement arithmetic, fill in the following table describing the effect
of casting and relational operations, in the style of Figure 2.18:

| Expression | Type | Evaluation |
| :--: | :-: | :--: |
| -2147483647-1 == 2147483648U | | |
| -2147483647-1 < 2147483647 | | |
| -2147483647-1U < 2147483647 | | |
| -2147483647-1 < -2147483647 | | |
| -2147483647-1U < -2147483647 | | |

### Practice Problem 2.22
Show that each of the following bit vectors is a two’s-complement representation
of −5 by applying Equation 2.3:
* A. [1011]
* B. [11011]
* C. [111011]

Observe that the second and third bit vectors can be derived from the first by
sign extension.

### Practice Problem 2.23
Consider the following C functions:
```
int fun1(unsigned word) {
  return (int) ((word << 24) >> 24);
}

int fun2(unsigned word) {
  return ((int) word << 24) >> 24;
}
```
Assume these are executed on a machine with a 32-bit word size that uses
two’s-complement arithmetic. Assume also that right shifts of signed values are
performed arithmetically, while right shifts of unsigned values are performed
logically.
* A. Fill in the following table showing the effect of these functions for
  several example arguments. You will find it more convenient to work with a
  hexadecimal representation. Just remember that hex digits 8 through F have
  their most significant bits equal to 1.

| w | fun1(w) | fun2(w) |
| :--: | :-: | :--: |
| 0x00000076 | | |
| 0x87654321 | | |
| 0x000000C9 | | |
| 0xEDCBA987 | | |
* B. Describe in words the useful computation each of these functions performs.

###  Practice Problem 2.25
Consider the following code that attempts to sum the elements of an array a,
where the number of elements is given by parameter length:
```
/* WARNING: This is buggy code */
float result = 0;
for (i = 0; i <= length-1; i++) {
  result += a[i];
}
return result;
```
When run with argument length equal to 0, this code should return 0.0. Instead
it encounters a memory error. Explain why this happens. Show how this code can
be corrected.

### Practice Problem 2.26
You are given the assignment of writing a function that determines whether one
string is longer than another. You decide to make use of the string library
function strlen having the following declaration:
```
/* Prototype for library function strlen */
size_t strlen(const char *s);
```
Here is your first attempt at the function:
```
/* Determine whether string s is longer than string t */
/* WARNING: This function is buggy */
int strlonger(char *s, char *t) {
  return strlen(s) - strlen(t) > 0;
}
```
When you test this on some sample data, things do not seem to work quite right.
You investigate further and determine that data type ```size_t``` is defined
(via ```typedef```) in header file ```stdio.h``` to be ```unsigned int```.
* A. For what cases will this function produce an incorrect result?
* B. Explain how this incorrect result comes about.
* C. Show how to fix the code so that it will work reliably.

### Practice Problem 2.27
Write a function with the following prototype:
```
/* Determine whether arguments can be added without overflow */
int uadd_ok(unsigned x, unsigned y);
```
This function should return 1 if arguments x and y can be added without causing
overflow.

### Practice Problem 2.30
Write a function with the following prototype:
```
/* Determine whether arguments can be added without overflow */
int tadd_ok(int x, int y);
```
This function should return 1 if arguments x and y can be added without causing
overflow.

### Practice Problem 2.31
Your coworker gets impatient with your analysis of the overflow conditions for
two’s-complement addition and presents you with the following implementation of
```tadd_ok```:
```
/* Determine whether arguments can be added without overflow */
/* WARNING: This code is buggy. */
int tadd_ok(int x, int y) {
  int sum = x+y;
  return (sum-x == y) && (sum-y == x);
}
```
You look at the code and laugh. Explain why.

### Practice Problem 2.32
You are assigned the task of writing code for a function ```tsub_ok```, with
arguments x and y, that will return 1 if computing ```x-y``` does not cause
overflow. Having just written the code for Problem 2.30, you write the
following:
```
/* Determine whether arguments can be subtracted without overflow */
/* WARNING: This code is buggy. */
int tsub_ok(int x, int y) {
  return tadd_ok(x, -y);
}
```
For what values of x and y will this function give incorrect results? Writing a
correct version of this function is left as an exercise (Problem 2.74).

### Practice Problem 2.40
For each of the following values of ```K```, find ways to express ```x * K```
using only the specified number of operations, where we consider both additions
and subtrac- tions to have comparable cost. You may need to use some tricks
beyond the simple form A and B rules we have considered so far.

| K | Shifts | Add/Subs | Expression |
| :--: | :-: | :--: | :--: |
| 6 | 2 | 1 | |
| 31 | 1 | 1 | |
| −6 | 2 | 1 | |
| 55 | 2 | 2 | |

### Practice Problem 2.42
Write a function div16 that returns the value ```x/16``` for integer argument
```x```. Your function should not use division, modulus, multiplication, any
conditionals (```if``` or ```?:```), any comparison operators (e.g., <, >, or
==), or any loops. You may assume that data type int is 32 bits long and uses a
two’s-complement representation, and that right shifts are performed
arithmetically.

### Practice Problem 2.43
In the following code, we have omitted the definitions of constants M and N:
```
#define M      /* Mystery number 1 */
#define N      /* Mystery number 2 */
int arith(int x, int y) {
  int result = 0;
  result = x*M + y/N; /* M and N are mystery numbers. */
  return result;
}
```
We compiled this code for particular values of M and N. The compiler optimized
the multiplication and division using the methods we have discussed. The
following is a translation of the generated machine code back into C:
```
/* Translation of assembly code for arith */
int optarith(int x, int y) {
  int t = x;
  x <<= 5;
  x -= t;
  if (y < 0) y += 7;
  y >>= 3;  /* Arithmetic shift */
  return x+y;
}
```
What are the values of M and N?

### Practice Problem 2.44
Assume we are running code on a 32-bit machine using two’s-complement arithmetic
for signed values. Right shifts are performed arithmetically for signed values
and logically for unsigned values. The variables are declared and initialized as
follows:
```
int x = foo();   /* Arbitrary value */
int y = bar();   /* Arbitrary value */
unsigned ux = x;
unsigned uy = y;
```
For each of the following C expressions, either (1) argue that it is true
(evaluates to 1) for all values of x and y, or (2) give values of x and y for
which it is false (evaluates to 0):
* A. `(x>0) || (x-1<0)`
* B. `(x&7)!=7 || (x<<29<0)`
* C. `(x*x)>=0`
* D. `x<0 || -x<=0`
* E. `x>0 || -x>=0`
* F. `x+y == uy+ux`
* G. `x*~y + uy*ux == -x`

### Practice Problem 2.45
Fill in the missing information in the following table:

| Fractional value | Binary representation | Decimal representation |
| :--: | :-: | :--: |
| 1/8 | 0.001 | 0.125 |
| 3/4 | | |
| 25/16 | | |
| | 10.1011 | |
| | 1.001 | |
| | | 5.875 |
| | | 3.1875 |

### Practice Problem 2.48
The integer 3,510,593 has hexadecimal representation 0x00359141, while the
single-precision, floating-point number 3510593.0 has hexadecimal representation
0x4A564504. Derive this floating-point representation and explain the
correlation between the bits of the integer and floating-point representations.

### Practice Problem 2.49
A. For a floating-point format with an n-bit fraction, give a formula for the
smallest positive integer that cannot be represented exactly (because it would
require an n+1-bit fraction to be exact). Assume the exponent field size k is
large enough that the range of representable exponents does not provide a
limitation for this problem.

B. What is the numeric value of this integer for single-precision format
(n = 23)?

## Practice Problem 2.50
Show how the following binary fractional values would be rounded to the nearest
half (1 bit to the right of the binary point), according to the round-to-even
rule. In each case, show the numeric values, both before and after rounding.
* A. 10.010<sub>2</sub>
* B. 10.011<sub>2</sub>
* C. 10.110<sub>2</sub>
* D. 11.001<sub>2</sub>

## Practice Problem 2.52
Consider the following two 7-bit floating-point representations based on the
IEEE floating point format. Neither has a sign bit—they can only represent
nonnegative numbers.
1. Format A
  * There are k = 3 exponent bits. The exponent bias is 3.
  * There are n = 4 fraction bits.
2. Format B
  * There are k = 4 exponent bits. The exponent bias is 7.
  * There are n = 3 fraction bits.
Below, you are given some bit patterns in Format A, and your task is to convert
them to the closest value in Format B. If necessary, you should apply the
round-to-even rounding rule. In addition, give the values of numbers given by
the Format A and Format B bit patterns. Give these as whole numbers (e.g., 17)
or as fractions (e.g., 17/64).

| A Bits | A Value | B Bits | B Value |
| :--: | :-: | :--: | :--: |
| 011 0000 | 1 | 0111 000 | 1 |
| 101 1110 | | | |
| 010 1001 | | | |
| 110 1111 | | | |
| 000 0001 | | | |

### Practice Problem 2.53
Fill in the following macro definitions to generate the double-precision
values `+∞`, `−∞`, and `0`:
```
#define POS_INFINITY
#define NEG_INFINITY
#define NEG_ZERO
```
You cannot use any include files (such as `math.h`), but you can make use of the
fact that the largest finite number that can be represented with double
precision is around 1.8 × 10<sup>308</sup>.

### Practice Problem 2.54
Assume variables `x`, `f`, and `d` are of type `int`, `float`, and `double`,
respectively. Their values are arbitrary, except that neither `f` nor `d` equals`
`+∞`, `−∞`, or `NaN`. For each of the following C expressions, either argue that
it will always be true (i.e., evaluate to 1) or give a value for the variables
such that it is not true (i.e., evaluates to 0).
* A. `x == (int)(double) x`
* B. `x == (int)(float) x`
* C. `d == (double)(float) d`
* D. `f == (float)(double) f`
* E. `f == -(-f)`
* F. `1.0/2 == 1/2.0`
* G. `d*d >= 0.0`
* H. `(f+d)-f == d`

Note that solutions to all practice problems can be found in the CSAPP2e
starting from page 134.

Sample code can be found in chapter2.c and experimented with as follows:
```
gcc -o chapter2 -m32 chapter2.c
./chapter2

```