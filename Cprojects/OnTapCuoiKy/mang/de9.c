#include "stdio.h"

int main() {
  int n;
  printf("nhap n: "); scanf("%d",&n);
  int a[n];

  for(int i=0; i<n; i++) {
    printf("a[%d] = ", i); scanf("%d",&a[i]);
  }

  printf("mang vua nhap la:\n");
  for(int i=0; i<n; i++) {
     printf("%6d",a[i]);
  }

  int tong=0;
  printf("\ncac phan tu chan co trong mang:\n");
  for(int i=0; i<n; i++) {
    if(a[i]%2==0) {
      printf("%8d",a[i]);
      tong+=a[i];
    }
  }
  printf("\ntong gia tri cac phan tu chan: %d",tong);
}
