#include "stdio.h"
#include "math.h"
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

  int dem=0;
  printf("\nCac so chinh phuong co trong mang la:");
  for (int i=0; i<n; i++) {
    if (sqrt(a[i])==(int)sqrt(a[i])) {
      dem++;
      printf("%6d",a[i]);
    }
  }
  printf("\nCo %d so chinh phuong trong mang",dem);
}
