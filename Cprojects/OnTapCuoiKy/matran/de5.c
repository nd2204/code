#include "stdio.h"

int main() {
  int n,m;
  printf("Nhap n: "); scanf("%d",&n);
  printf("Nhap m: "); scanf("%d",&m);

  int a[m][n];
  for (int i=0; i<m; i++) {
    for (int j=0; j<n; j++) {
      printf("a[%d][%d] = ",i,j); scanf("%d",&a[i][j]);
    }
  }

  printf("\nMa tran vua nhap la:\n");
  for (int i=0; i<m; i++) {
    for (int j=0; j<n; j++) {
      printf("%5d",a[i][j]);
    }
    printf("\n");
  }

  printf("Gia tri cac phan tu le trong ma tran la:");
  for (int i=1; i<m; i+=2) {
    for (int j=1; j<n; j+=2) {
      if(i%2!=0 || j%2!=0) printf("%5d",a[i][j]);
    }
  }
  printf("\n");

  int k;
  int tbc=0;
  do {
    printf("Nhap cot (0<K<=%d): ",n); scanf("%d",&k);
  } while (k<=0 || k>n);

  for (int i=0; i<m; i++) {
    tbc+=a[i][k-1];
  }
  printf("\nTBC cac phan tu thuoc cot %d la: %.2f",k,(float)tbc/m);
}
