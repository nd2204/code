#include "stdio.h"

int main()
{
  int n;
  printf("Nhap N: "); scanf("%d",&n);
  float a[n][n];
  float tong[n];

  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      printf("a[%d][%d] = ",i,j); scanf("%f",&a[i][j]);
    }
  }

  printf("\nMang vua nhap la:\n");
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      printf("%8.2f",a[i][j]);
    }
    printf("\n");
  }

  printf("\nPhan tu cua hang 1 la: ");
  for (int i=0; i<n; i++) {
    printf("%8.2f",a[0][i]);
  }

  tong[0]=a[0][0];
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      tong[i]+=a[i][j];
    }
    printf("\nTong cac phan tu cua hang %d la: %.2f",i+1,tong[i]);
  }
}
