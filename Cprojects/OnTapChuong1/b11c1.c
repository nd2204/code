#include "stdio.h"

int main() {
  int a,b;
  int temp;
  int ucln;
  int bcnn;
  do {
    printf("Nhap a,b (a,b>=0):\n"); scanf("%d%d",&a,&b);
    printf("Hai so vua nhap la: %d %d",a,b);
  } while (a<0 || b<0);

  if (a==0 && b!=0) {
    ucln = b;
    bcnn = 0;
  } else if (a!=0 && b==0) {
    ucln = a;
    bcnn = 0;
  } else if (a==0 && b==0) {
    ucln = 0;
    bcnn = 0;
  } else {

    if (a>b) temp=b;
    else temp=a;

    for (int i=a; i>0; i--) {
      if (a%i==0 && b%i==0) {
        ucln=i;
        break;
      }
    }
    bcnn = (a*b)/ucln;
 }
  printf("\nUCLN(a,b) = %d",ucln);
  printf("\nBCNN(a,b) = %d",bcnn);
}