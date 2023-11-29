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
    printf("%8.2f",a[i]);;
  }

  float temp;
  for (int i=0; i<n-1; i++) {
    for (int j=i+1; j<n; j++) {
      if (a[i]<a[j]) {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
      }
    }
  }

  printf("\nMang da duoc sap xep la:\n");
  for (int i=0; i<n; i++) {
    printf("%8.2f",a[i]);
  }
}
