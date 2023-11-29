#include "stdio.h"
int main() {
  int n,m;
  float a[100][100];
  printf("Nhap so hang: "); scanf("%d",&n);
  printf("Nhap so cot: "); scanf("%d",&m);

  printf("Ma tran %dx%d\n",n,m);
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      printf("a[%d][%d] = ",i,j); scanf("%f",&a[i][j]);
    }
  }

  printf("Mang vua nhap la:\n");
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      printf("%8.2f",a[i][j]);
    }
    printf("\n");
  }

  int k;
  float tong=0;
  do {
    printf("Nhap k la hang cua ma tran (0<k<=%d): ",n); scanf("%d",&k);
  } while (k>n || k<1);

  for (int i=0; i<m; i++) {
    tong+=a[k-1][i];
  }
  printf("Tong cac phan tu tren hang k cua ma tran la: %.2f",tong);

  float max=a[0][0];
  int hang,cot;
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      if (a[i][j]>max) {
        hang = i; cot = j;
        max = a[i][j];
      }
    }
  }
  printf("\nGia tri lon nhat trong ma tran la: a[%d][%d] = %.2f",hang,cot,max);
}
