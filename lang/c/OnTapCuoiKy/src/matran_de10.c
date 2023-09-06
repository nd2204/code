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

  printf("Phan tu tren cot 1 cua ma tran la:\n");
  for (int i=0; i<m; i++) {
    printf("%8.2f",a[i][0]);
    printf("\n");
  }

  int k;
  do {
    printf("Nhap hang thu k trong mang (1<=k<=%d): ",m); scanf("%d",&k);
  } while (k<1 || k>m);
  printf("Cac phan tu thuoc hang k la:\n");
  for (int i=0; i<n; i++) {
    printf("%6.2f",a[k-1][i]);
  }
}
