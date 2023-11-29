#include <stdio.h>

int main() {
  float x;
  printf("Nhap x: "); scanf("%f",&x);
  if (x>=0) {
    printf("x = %7.2f",x);
  } else printf("x la so am khong co gia tri can bac 2");
}
