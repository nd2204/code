#include "stdio.h"

int main() {
  int n;
  printf("Nhap n"); scanf("%d",&n);
  int a[n][n];

  printf("Ta co ma tran %dx%d\n",n,n);
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      printf("a[%d][%d] = ",i,j); scanf("%d",&a[i][j]);
    }
  }

  printf("Ma tran vua nhap la:\n");
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      printf("%6d",a[i][j]);
    }
    printf("\n");
  }

  int max=a[0][0];
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      if (max<a[i][j]) max=a[i][j];
    }
  }
  printf("\nGia tri nho nhat trong ma tran la: %d",max);

  int tong=0;
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      if (i==j) tong+=a[i][j];
    }
  }
  printf("\nTong cac phan tu thuoc duong cheo chinh la: %d",tong);
}
