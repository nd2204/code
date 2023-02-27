#include "stdio.h"
#include "math.h"

int main () {
  float n;
  do {
    printf("Nhap N (N>=100): "); scanf("%f",&n);
  } while (n<100);

  for (double i=n;i>1.01;i=sqrt(i)) {
    printf("\n%.2lf",i);
  }
}
