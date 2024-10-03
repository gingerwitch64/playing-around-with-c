#include <stdio.h>

int gcd(int a, int b) {
  int t = 0;
  while (b != 0) {
    t = b;
    b = (a % b);
    a = t;
  }
  return a;
}

int main() {
  int testgcd = gcd(1071, 462);
  printf("%d\n", testgcd);
  return 0;
}
