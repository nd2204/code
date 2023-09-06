#include "stdio.h"

int main() {
  int n;
  printf("Nhap n: "); scanf("%d",&n);
  float a[n];

  for(int i=0; i<n; i++) {
    printf("a[%d] = ", i); scanf("%f",&a[i]);
  }

  printf("Mang vua nhap la:\n");
  for(int i=0; i<n; i++) {
     printf("%8.2f",a[i]);
  }

  float tong=0;
  for(int i=0; i<n; i++) {
    tong+=a[i];
  }
  printf("\nTong cac phan tu trong mang: %.2f",tong);

  float x;
  int kt;
  printf("\nNhap x: "); scanf("%f",&x);
  for (int i=0; i<n; i++) {
    if (x==a[i]) {
      kt=1;
      a[i]=0;
    }
  }
  if (kt) printf("\nCo ton tai x trong mang");
  else printf("\nKhong ton tai x trong mang");
}
