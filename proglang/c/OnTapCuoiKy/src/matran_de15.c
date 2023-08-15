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

  printf("Ma tran vua nhap la:\n");
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      printf("%8.2f",a[i][j]);
    }
    printf("\n");
  }

  float min=a[0][0];
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      if (min>a[i][j]) min=a[i][j];
    }
  }
  printf("Gia tri nho nhat cua mang la: %.2f\n",min);

  int k;
  float tong=0;
  do {
    printf("Nhap k la cot cua ma tran (0<k<=%d): ",m); scanf("%d",&k);
  } while (k>m || k<1);

  for (int i=0; i<n; i++) {
    tong+=a[i][k-1];
  }
  printf("Tong cac phan tu tren cot k cua ma tran la: %.2f",tong);
}
