#include "stdio.h"

int main() {
  int n;
  printf("Nhap n: "); scanf("%d",&n);
  int a[n];

  for (int i=0; i<n; i++) {
    printf("a[%d] = ",i); scanf("%d",&a[i]);
  }

  printf("\nMang vua nhap la:");
  for (int i=0; i<n; i++) {
    printf("%5d",a[i]);
  }

  int tong=0;
  for (int i=0; i<n; i++) {
    if (i%2==0) tong+=a[i];
  }
  printf("\nTong cac phan tu o vi tri chan trong mang la: %d",tong);

  printf("\nCac phan tu le trong mang la: ");
  for (int i=0; i<n; i++) {
    if (i%2!=0) printf("%5d",a[i]);
  }
}
