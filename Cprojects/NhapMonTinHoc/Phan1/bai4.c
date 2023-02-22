#include <stdio.h>

//Bai 4: Tinh TBC cac so chan tu 2 den n (n nhap tu ban phim)
int main() {
  int n;
  int tong=0,dem=0;
  printf("Nhap n: "); scanf("%d",&n);
  for (int i=2; i<=n; i+=2) {
    tong+=i;
    dem++;
  }
  if(dem!=0) {
    printf("TBC cac so chan tu 2->%d la: %d",n,tong/dem);
  } else printf("Khong co so chan nao ngoai 2 thuoc khoang 2->%d",n);
}
