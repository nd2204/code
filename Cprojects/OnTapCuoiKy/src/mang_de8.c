#include "stdio.h"

int main() {
  int n;
  printf("Nhap n: "); scanf("%d",&n);
  float a[n];

  for (int i=0; i<n; i++) {
    printf("a[%d] = ",i); scanf("%f",&a[i]);
  }

  printf("Mang vua nhap la:\n");
  for (int i=0; i<n; i++) {
    printf("%8.2f",a[i]);
  }

  float min=a[0];
  for (int i=0; i<n; i++) {
    if (a[i]<min) min=a[i];
  }
  printf("\nGia tri nho nhat trong mang la: %.2f",min);
}
