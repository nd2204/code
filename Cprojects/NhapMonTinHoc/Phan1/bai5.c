#include <stdio.h>
//Bai 5: Tim n! (n>0 n la so nguyen)
int giaithua(int a) {
  int result=a;
  for (int i=a-1; i>0; i--) {
    result=result*i;
  }
  return result;
}
int main () {
  int n;
  printf("Nhap n: "); scanf("%d",&n);
  printf("%d! = %d",n,giaithua(n));
}
