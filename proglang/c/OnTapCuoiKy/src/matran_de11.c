#include "stdio.h"
int main() {
  int m,n;
  printf("Nhap so hang: "); scanf("%d",&m);
  printf("Nhap so cot: "); scanf("%d",&n);
  int a[m][n];

  printf("Ta co ma tran %dx%d\n",m,n);
  for (int i=0; i<m; i++) {
    for (int j=0; j<n; j++) {
      printf("a[%d][%d] = ",i,j); scanf("%d",&a[i][j]);
    }
  }

  printf("Ma tran vua nhap la:\n");
  for (int i=0; i<m; i++) {
    for (int j=0; j<n; j++) {
      printf("%6d",a[i][j]);
    }
    printf("\n");
  }

  int tong=0;
  for (int i=0; i<m; i++) {
    for (int j=0; j<n; j++) {
      tong+=a[i][j];
    }
  }
  printf("Tong cac phan tu trong ma tran la: %d",tong);

  int max=a[0][0],hang;
  for (int i=0; i<m; i++) {
    if (max<a[i][0]) {
      hang=i;
      max=a[i][0];
    }
  }
  printf("\nPhan tu co gia tri lon nhat tren cot 1 la a[%d][%d]= %d",hang,0,max);
}
