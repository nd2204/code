#include "stdio.h"

int main() {
  int m,n,k;
  printf("Nhap m: "); scanf("%d",&m);
  printf("Nhap n: "); scanf("%d",&n);
  int a[m][n];

  for(int i=0; i<m; i++) {
    for (int j=0; j<n; j++) {
      printf("a[%d][%d] = ",i,j); scanf("%d",&a[i][j]);
    }
  }

  printf("Mang vua nhap la\n");
  for(int i=0; i<m; i++) {
    for (int j=0; j<n; j++) {
      printf("%6d",a[i][j]);
    }
    printf("\n");
  }

  printf("\nCac phan tu thuoc hang 1:\n");
  for(int j=0; j<n; j++) {
    printf("%6d",a[0][j]);
  }
  printf("\n");

  int tong=0;
  do {
    printf("Nhap cot (0<K<=%d): ",n); scanf("%d",&k);
  } while (k<=0 || k>n);
  for (int i=0; i<m; i++) tong+=a[i][k-1];
  printf("\nTBC cac phan tu thuoc cot %d la: %d",k,tong/m);
}
