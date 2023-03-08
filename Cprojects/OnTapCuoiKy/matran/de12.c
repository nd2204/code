#include "stdio.h"
int main() {
  int m,n;
  printf("Nhap m: "); scanf("%d",&m);
  printf("Nhap n: "); scanf("%d",&n);
  float a[m][n];

  printf("Ma tran %dx%d\n",m,n);
  for (int i=0; i<m; i++) {
    for (int j=0; j<n; j++) {
      printf("a[%d][%d] = ",i,j); scanf("%f",&a[i][j]);
    }
  }
  printf("Ma tran vua nhap la:\n");
  for (int i=0; i<m; i++) {
    for (int j=0; j<n; j++) {
      printf("%8.2f",a[i][j]);
    }
    printf("\n");
  }

  float tong=0;
  for (int i=0; i<m; i++) {
    for (int j=0; j<n; j++) {
      tong+=a[i][j];
    }
  }
  printf("\nTBC cac phan tu trong ma tran la: %.2f",tong/(m*n));

  int k;
  float tich=1;
  do {
    printf("\nNhap k (1<=k<=%d): ",m); scanf("%d",&k);
  } while (k<1 || k>m);
  for (int i=0; i<n; i++) {
    tich*=a[k-1][i];
  }
  printf("\nTich cac phan tu thuoc hang k la: %.2f",tich);
}
