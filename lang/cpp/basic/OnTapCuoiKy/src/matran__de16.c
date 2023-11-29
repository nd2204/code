#include "stdio.h"
int main() {
  int m,n;
  float a[100][100];
  printf("Nhap so hang: "); scanf("%d",&m);
  printf("Nhap so cot: "); scanf("%d",&n);

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

  float aNew[100][100];
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      aNew[i][j]=a[j][i];
    }
  }

  printf("Ma tran chuyen vi cua ma tran tren la:\n");
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      printf("%8.2f",aNew[i][j]);
    }
    printf("\n");
  }
}
