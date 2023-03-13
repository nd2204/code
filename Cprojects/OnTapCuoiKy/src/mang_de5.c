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

  printf("\nCac phan tu lon hon 2 trong mang:");
  for (int i=0; i<n; i++) {
    if (a[i]>0) printf("%8.2f",a[i]);
  }
}
