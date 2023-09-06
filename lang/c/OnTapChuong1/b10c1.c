#include "stdio.h"

int main () {
  int n;
  int i=0;
  do {
    printf("Nhap N (N>=0): "); scanf("%d",&n);
  } while (n<0);

  printf("N = %d", n);
  printf("\nCac so chan tu 0->%d la: ",n);
  while (i<=n) {
    printf("%d ",i);
    i+=2;
  }
}


