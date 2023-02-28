#include <stdio.h>

int main(){
  float a;
  printf("\nNhap a: "); scanf("%f",&a);
  printf("\nSo da nhap a = %10.3f",a);
  printf("\nBieu thuc B co gia tri = %f",5*a*a*a-4*a*a+3*a-2);
}
