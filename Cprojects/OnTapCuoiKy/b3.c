#include <stdio.h>

int main() {
  int a,b,c,d;
  int tamthoi;
  if (a<b && a<c && a<d) {
    tamthoi = a;
    a = b;
    b = tamthoi;
  } else if(b<c) {
    tamthoi = b;
    b = c;
    b = tamthoi;
  }
}
