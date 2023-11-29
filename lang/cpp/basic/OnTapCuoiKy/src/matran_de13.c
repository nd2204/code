#include "stdio.h"

int main() {
  int n,m;
  int a[100][100];
  printf("Nhap so hang: "); scanf("%d",&n);
  printf("Nhap so cot: "); scanf("%d",&m);

  printf("Ma tran %dx%d\n",n,m);
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

  printf("Cac phan tu le thuoc ma tran la:\n");
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      if (a[i][j]%2!=0) printf("%6d",a[i][j]);
    }
  }

  printf("\nCac phan tu chan co trong hang 1 cua ma tran la: ");
  for (int i=0; i<m; i++) {
    if(a[0][i]%2==0) printf("%d",a[0][i]);
  }
}

