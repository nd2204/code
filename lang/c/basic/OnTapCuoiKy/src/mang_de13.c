#include "stdio.h"

int main() {
  int n;
  printf("Nhap n: "); scanf("%d",&n);
  int a[n];

  for(int i=0; i<n; i++) {
    printf("a[%d] = ", i); scanf("%d",&a[i]);
  }

  printf("Mang vua nhap la:\n");
  for(int i=0; i<n; i++) {
     printf("%6d",a[i]);
  }

  int aNew[n];
  for (int i=0; i<n; i++) {
    aNew[i]=a[n-i-1];
  }

  printf("\nMang dao cua mang vua nhap la:\n");
  for (int i=0; i<n; i++) {
    printf("%6d",aNew[i]);
  }
}
