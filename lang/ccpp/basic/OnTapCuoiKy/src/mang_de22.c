#include "stdio.h"

int main() {
  int n;
  printf("Nhap n: "); scanf("%d",&n);
  int a[n];

  for (int i=0; i<n; i++) {
    printf("a[%d] = ",i); scanf("%d",&a[i]);
  }

  printf("Mang vua nhap la:\n");
  for (int i=0; i<n; i++) {
    printf("%6d",a[i]);
  }

  int kt;
  for (int i=0; i<n/2; i++) {
    if (a[i]!=a[n-i-1]) {
      printf("\nMang vua nhap khong doi xung");
      break;
    }
    else kt=1;
  }
  if (kt==1) printf("\nMang vua nhap doi xung");
}
