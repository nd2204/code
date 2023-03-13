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

  int min=a[0][0];
  for (int i=0; i<m; i++) {
    for (int j=0; j<n; j++) {
      if (min>a[i][j]) min=a[i][j];
    }
  }
  printf("\nGia tri nho nhat trong ma tran la: %d",min);

  int dem=0;
  printf("\nCac phan tu am chia het cho 5 la:");
  for (int i=0; i<m; i++) {
    for (int j=0; j<n; j++) {
      if (a[i][j]<0 && a[i][j]%5==0) {
        printf("\na[%d][%d] = %d",i,j,a[i][j]);
        dem++;
      }
    }
  }
  if (dem==0) printf("\nTrong ma tran khong co phan tu am chia het cho 5");
}
