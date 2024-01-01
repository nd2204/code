#include <stdio.h>

int main() {
  float x;
  printf("Nhap x: "); scanf("%f",&x);
  printf("So da nhap la: %.3f",x);
  printf("Gia tri cua bieu thuc B = %f",5*x*x*x-4*x*x+3*x-2);
}
