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

  int tong=0, dem=0;
  for(int i=0; i<n; i++) {
    if (a[i]%2!=0) {
      tong+=a[i];
      dem++;
    }
  }
  printf("\nTBC phan tu le o vi tri chan la: %d",tong/dem);
}
