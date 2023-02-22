#include <stdio.h>
#include <math.h>
//Bai 3: Kiem tra so chinh phuong
void isSquareNumber() {
  int a;
  printf("nhap a: "); scanf("%d",&a);
  int a_sqrt = (float)sqrt(a);
  if (a==pow(a_sqrt,2)) {
    printf("%d la so chinh phuong",a);
  } else printf("%d khong phai la so chinh phuong",a);
}
int main() {
  isSquareNumber();
}

