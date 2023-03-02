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

  int temp;
  int dem=0;
  for (int i=0; i<n; i++) {
    if (a[i]<0) dem++;
  }
  for(int i=0; i<n; i++) {
    for (int j=i+1; j<n; j++) {
      if(a[i]>=0) break;
      else {
        if (a[j]>=0) {
          temp = a[i];
          a[i] = a[j];
          a[j] = temp;
          break;
        }
      }
    }
  }

  printf("\nMang moi sau khi xoa phan tu am la:\n");
  for(int i=0; i<n-dem; i++) {
    printf("%6d",a[i]);
  }
}




