#include "stdio.h"

int main() {
  int n;
  printf("Nhap n: "); scanf("%d",&n);
  int a[n];

  for (int i=0; i<n; i++) {
    printf("a[%d] = ",i); scanf("%d",&a[i]);
  }
  printf("Mang vua nhap la: ");
  for (int i=0; i<n; i++) {
    printf("%5d",a[i]);
  }

  printf("\nSo duong co trong mang la: ");
  for (int i=0; i<n; i++) {
    if (a[i]>0) printf("%5d",a[i]);
  }

  int max=a[0];
  for (int i=0; i<n; i++) {
    if (a[i]>max) max=a[i];
  }
  printf("\nSo lon nhat trong mang la: %d",max);
}
