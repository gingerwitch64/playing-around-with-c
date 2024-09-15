#include <stdio.h>

// Primitive Float ABsolute Value
float pfabs(float x) { if (x < 0.0f) { return x + x*-2.0f; } else { return x; } }

// Integer POWer
float ipow(float x, int n) {
  unsigned int i;
  float y = (n < 0) ? 1.0f/x : x;
  float result = 1.0f;
  for (i = 0; i < pfabs(n); i++) { result *= y; }
  return result;
}

unsigned long long int factorial(int x) {
  if (x > 20) { return 0; }
  /* Numbers over 20 exceed the 64 bit unsigned integer's maximum value.
    0! will return 1, so by returning 0 a programmer will [have to]
    know that they inputted an unsupported value. */
  unsigned long long int result = 1;
  unsigned short int i;
  for (i = 0; i < x; i++) {
    result *= (x - i);
  }
  return result;
}

// Newton's method SQuare RooT
float nsqrt(float a) {
  if (a == 0.0f) { return 0.0f; } else if (a < 0.0f) { return -1.0f; }
  unsigned short int i;
  /* A single iteration of Halley's Method where the initial
    guess is 1 in order to get a better approximate */
  float x = (1.0f + 3.0f*a)/(3.0f + a);
  for (i = 0; i < 16; i++) {
    x = 0.5f * ( x + (a/x) );
    printf("%.17f, iteration %d\n",x,i);
  }
  return x;
}

// Halley's Method w/ 2 iterations of Newton's Method
float hnsqrt(float a) {
  if (a == 0.0f) { return 0.0f; } else if (a < 0.0f) { return -1.0f; }
  unsigned short int i;
  float x = (1.0f + 3.0f*a)/(3.0f + a);
  // In my testing, 4 iterations is enough; this will run 5 iterations.
  for (i = 0; i < 4; i++) {
    x = (x*x*x + 3.0f*a*x)/(3.0f*x*x + a);
    x = 0.5f * ( x + (a/x) );
    x = 0.5f * ( x + (a/x) );
  }
  return x;
}

int main() {}