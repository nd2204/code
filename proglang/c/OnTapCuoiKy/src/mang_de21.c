#include "stdio.h"

int main() {
  int n;
  printf("Nhap n: "); scanf("%d",&n);
  int a[n];

  for(int i=0; i<n; i++) {
    printf("a[%d] = ", i); scanf("%d",&a[i]);
  }

  printf("Mang vua nhap la:\n");
  for(int i=0; i<n; i++) {
     printf("%6d",a[i]);
  }

  int kt;
  for(int i=0; i<n-1; i++) {
    if (a[i]>a[i+1]) {
      kt=0;
      break;
    } else kt=1;
  }
  if (kt) printf("\nMang vua nhap co tinh tang dan");
  else printf("\nMang vua nhap khong tang dan");
}
