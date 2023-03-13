#include "stdio.h"

int main() {
  int n;
  printf("Nhap n: "); scanf("%d",&n);
  int a[n][n];

  printf("Ma tran %dx%d\n",n,n);
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

  printf("Phan tu chan co trong ma tran la: ");
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      if (a[i][j]%2==0) printf("%6d",a[i][j]);
    }
  }

  int tong=a[0][0];
  for (int i=1; i<n; i++) {
    for (int j=1; j<n; i++) {
      if (i==j) tong+=a[i][j];
    }
  }
  printf("\nTong cac phan tu thuoc duong cheo chinh: %d",tong);
}
