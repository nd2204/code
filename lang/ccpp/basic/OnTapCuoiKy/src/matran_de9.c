#include "stdio.h"

int main() {
  int n,m;
  printf("Nhap n: "); scanf("%d",&n);
  printf("Nhap m: "); scanf("%d",&m);
  int a[n][m];

  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      printf("a[%d][%d] = ",i,j); scanf("%d",&a[i][j]);
    }
  }

  printf("Mang vua nhap la:\n");
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      printf("%6d",a[i][j]);
    }
    printf("\n");
  }

  int tong=0;
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      tong+=a[i][j];
    }
  }
  printf("\nTong cac phan tu: %d",tong);

  int min=a[0][0];
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      if (min>a[i][j]) min=a[i][j];
    }
  }
  printf("\nGia tri nho nhat trong ma tran la: %d", min);
}












