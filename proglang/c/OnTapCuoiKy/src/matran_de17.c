#include "stdio.h"
int main() {
  int m,n;
  float a[100][100];
  float b[100][100];
  printf("Nhap so hang cho ma tran A va B: "); scanf("%d",&m);
  printf("Nhap so cot cho ma tran A va B: "); scanf("%d",&n);

  printf("Ma tran A(%dx%d)\n",m,n);
  for (int i=0; i<m; i++) {
    for (int j=0; j<n; j++) {
      printf("a[%d][%d] = ",i,j); scanf("%f",&a[i][j]);
    }
  }

  printf("Ma tran B(%dx%d)\n",m,n);
  for (int i=0; i<m; i++) {
    for (int j=0; j<n; j++) {
      printf("b[%d][%d] = ",i,j); scanf("%f",&b[i][j]);
    }
  }

  printf("Ma tran C=A+B:\n");
  for (int i=0; i<m; i++) {
    for (int j=0; j<n; j++) {
      printf("%8.2f",a[i][j]+b[i][j]);
    }
    printf("\n");
  }
}
