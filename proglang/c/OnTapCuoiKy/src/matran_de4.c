#include <stdio.h>

int main() {
  int n,m;
  printf("Nhap n: "); scanf("%d",&n);
  printf("Nhap m: "); scanf("%d",&m);
  float a[n][m];

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

  printf("Cac so chia het cho 5 co trong ma tran la:");
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      if ((int)a[i][j]==a[i][j] && (int)a[i][j]%5==0) printf("%8.2f",a[i][j]);
    }
  }

  float max=a[0][0];
  for (int i=0; i<m; i++) {
    if (max<a[0][i]) max=a[0][i];
  }
  printf("Gia tri lon nhat o hang 1 la: %.2f",max);
}
