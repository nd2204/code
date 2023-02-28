#include <stdio.h>

int main(){
  float a,b;
  printf("Nhap a: "); scanf("%f",&a);
  printf("Nhap b: "); scanf("%f",&b);
  printf("Cac so da nhap la:\na=%5f\nb=%12f",a,b);

  printf("\na+b=%f",a+b);
  printf("\na-b=%f",a-b);
  printf("\na*b=%f",a*b);
  printf("\na/b=%f",a/b);
}
