#include "stdio.h"

int main() {
  int n;
  int a[100][100];
  printf("Nhap n: "); scanf("%d",&n);

  printf("Ma tran vuong %dx%d\n",n,n);
  for (int i=0; i<n; i++)  {
    for (int j=0; j<n; j++) {
      printf("a[%d][%d] = ",i,j); scanf("%d",&a[i][j]);
    }
  }

  printf("Ma tran vua nhap la:\n");
  for (int i=0; i<n; i++)  {
    for (int j=0; j<n; j++) {
      printf("%6d",a[i][j]);
    }
    printf("\n");
  }

  printf("Phan tu thuoc duong cheo phu la: ");
  for (int i=0; i<n; i++) {
    printf("%6d",a[i][n-i-1]);
  }
}
