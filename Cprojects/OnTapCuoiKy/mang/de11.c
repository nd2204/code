#include "stdio.h"

int main() {
  int n;
  printf("nhap n: "); scanf("%d",&n);
  int a[n];

  for(int i=0; i<n; i++) {
    printf("a[%d] = ", i); scanf("%d",&a[i]);
  }

  printf("mang vua nhap la:\n");
  for(int i=0; i<n; i++) {
     printf("%6d",a[i]);
  }

  int max=a[0];
  for(int i=0; i<n; i++) {
    if(max<a[i]) max=a[i];
  }
  printf("\nGia tri lon nhat cua mang: %d",max);

  int tong=0, dem=0;
  for(int i=0; i<n; i++) {
    if(i%2!=0) {
      tong+=a[i];
      dem++;
    }
  }
  printf("\nTBC gia tri tai cac phan tu vi tri le: %.2f",(float)tong/dem);
}
