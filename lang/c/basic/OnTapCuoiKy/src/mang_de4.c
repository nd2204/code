#include "stdio.h"

int main() {
  int n;
  printf("Nhap n: "); scanf("%d",&n);
  float a[n];

  for (int i=0; i<n; i++) {
    printf("a[%d] = ",i); scanf("%f",&a[i]);
  }

  printf("Mang vua nhap la:");
  for (int i=0; i<n; i++) {
    printf("%8.2f",a[i]);
  }

  float x;
  printf("Nhap X"); scanf("%f",&x);
  for (int i=0; i<n; i++) {
    if (x==a[i]) {
      printf("\n%.2f co trong mang vua nhap",x);
      break;
    }
  }

  float tbc=0;
  int count=0;
  for (int i=0; i<n; i++) {
    if (a[i]>0) {
      tbc+=a[i];
      count++;
    }
  }
  printf("\nTBC cac so duong co trong mang la: %.2f",tbc/count);
}
