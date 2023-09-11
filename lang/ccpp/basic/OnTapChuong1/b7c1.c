#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int abs(int a) {
  if (a>0) return a;
  return -a;
}

int isTriangle(int a, int b, int c) {
  if (a>0 && b>0 && c>0) {
    if (a+b>c && a+c>b && b+c>a && abs(a-b)<c && abs(a-c)<b && abs(b-c)<a) return 1;
  }
  return 0;
}

double dienTichTamGiac(int a, int b, int c){
  double p = (double)(a+b+c)/2;
  double result = sqrt(p*(p-a)*(p-b)*(p-c));
  return result;
}

int main() {
  int a,b,c;
  printf("Nhap a: ");scanf("%d",&a);
  printf("Nhap b: ");scanf("%d",&b);
  printf("Nhap c: ");scanf("%d",&c);

  if (isTriangle(a,b,c)) {
    int chuvi;
    float dientich = dienTichTamGiac(a,b,c);
    chuvi=a+b+c;
    printf("Chu vi cua tam giac abc la: %d", chuvi);
    printf("\nDien tich cua tam giac abc la: %.2f", dientich);
  }
}
