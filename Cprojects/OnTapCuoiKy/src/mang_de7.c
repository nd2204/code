#include "stdio.h"

int main() {
  int n;
  printf("Nhap n: "); scanf("%d",&n);
  int a[n];

  for (int i=0; i<n; i++) {
    printf("a[%d] = ",i); scanf("%d",&a[i]);
  }

  printf("Mang vua nhap la:\n");
  for (int i=0; i<n; i++) {
    printf("%6d",a[i]);
  }

  printf("\nCac phan tu lon hon 9 trong mang:");
  for (int i=0; i<n; i++) {
    if (a[i]>9) printf("%6d",a[i]);
  }

  int tong=0, dem=0;
  for (int i=0; i<n; i++) {
    if (a[i]%7==0) {
      tong+=a[i];
      dem++;
    }
  }
  printf("\nTBC cac so chia het cho 7 la: %d",tong/dem);
}
