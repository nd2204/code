#include "stdio.h"

int main() {
  int n;
  printf("Nhap n: "); scanf("%d",&n);
  int a[n];

  for (int i=0; i<n; i++) {
    printf("a[%d] = ",i); scanf("%d",&a[i]);
  }

  printf("\nMang vua nhap la: ");
  for (int i=0; i<n; i++) {
    printf("%5d",a[i]);
  }

  int max=a[0];
  for (int i=0; i<n; i++) {
    if (max<a[i]) max=a[i];
  }
  printf("\nGia tri lon nhat trong mang la: %d",max);
}
