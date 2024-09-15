#include <stdio.h>
#include <time.h>

float pfabs(float x) { if (x < 0.0f) { return x + x*2.0f; } else { return x; } }

float ipow(float x, int n) {
  unsigned int i;
  float y = (n < 0) ? 1.0f/x : x;
  float result = 1.0f;
  for (i = 0; i < pfabs(n); i++) { y *= y; }
  return result;
}

float nsqrt(float a) { // Newton's Method
  if (a == 0.0f) { return 0.0f; } else if (a < 0.0f) { return -1.0f; }
  unsigned short int i;
  float x = (1 + 3.0f*a)/(3.0f + a);
  //x = (x*x*x + 3.0f*a*x)/(3.0f*x*x + a);
  // A single iteration of Halley's Method in order to get a better approximate
  for (i = 0; i < 16; i++)
  {
    x = 0.5f * ( x + (a/x) );
    //printf("%.17f, iteration %d\n",x,i);
  }
  //x = (x*x*x + 3.0f*a*x)/(3.0f*x*x + a);
  return x;
}

float hnsqrt(float a) { // Halley's Method w/ 2 iterations of Newton's Method
  if (a == 0.0f) { return 0.0f; } else if (a < 0.0f) { return -1.0f; }
  unsigned short int i;
  float x = (1 + 3.0f*a)/(3.0f + a);
  for (i = 0; i < 4; i++)
  {
    x = (x*x*x + 3.0f*a*x)/(3.0f*x*x + a);
    //printf("%.17f, iteration %d (Halley)\n",x,i);
    x = 0.5f * ( x + (a/x) );
    //printf("%.17f, iteration %d (Newton 1)\n",x,i);
    x = 0.5f * ( x + (a/x) );
    //printf("%.17f, iteration %d (Newton 2)\n",x,i);
  }
  return x;
}

int main() {
  const float num = (3*3 + 4*3);
  float in = nsqrt(num);

  printf("%f\n",in);
}