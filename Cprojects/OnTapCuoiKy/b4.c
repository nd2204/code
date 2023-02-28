#include <stdio.h>
#include <math.h>

int main() {
  float a;
  printf("Nhap a: "); scanf("%f",&a);
  printf("So vua nhap la: %8.2f",a);
  printf("Gia tri bieu thuc B = %f",log10(a*a)-tanf(3*a));
}
