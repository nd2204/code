#include <stdio.h>

int main() {
  int n;
  do {
    printf("Nhap n: "); scanf("%d",&n);
  } while (n<2 || n>5);
  int a[n][n];

  printf("Ma tran %dx%d\n",n,n);
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      printf("a[%d][%d] = ",i,j); scanf("%d",&a[i][j]);
    }
  }

  printf("Ma tran vua nhap la:\n");
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      printf("%6d",a[i][j]);
    }
    printf("\n");
  }

  int k, dem=0;
  do {
    printf("Nhap k (1<=k<=%d): ",n); scanf("%d",&k);
  } while (k>n || k<1);
  for (int i=0; i<n; i++) {
    if(a[k-1][i]>0) dem++;
  }
  printf("So cac so duong tren hang k cua ma tran la: %d",dem);
}
