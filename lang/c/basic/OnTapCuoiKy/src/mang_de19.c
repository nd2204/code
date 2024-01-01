#include "stdio.h"

/* int isPrime(int n) { */
/*   if (n<2) return 0; */
/*   else { */
/*     for(int i=2; i*i<=n; i++) { */
/*       if(n%i==0) return 0; */
/*     } */
/*   } */
/*   return 1; */
/* } */

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

  int isPrime=1;
  int dem=0;
  printf("\nSo nguyen to co trong mang la:");
  for(int i=0; i<n; i++) {
    if (a[i]>=2) {
      for(int j=2; j*j<=a[i]; j++) {
        if(a[i]%j==0) {
          isPrime = 0;
          break;
        } else isPrime = 1;
      }
      if (isPrime==1) {
        printf("%6d",a[i]);
        dem++;
      }
    }
  }
  //in ra man hinh va dem so nguyen to
  printf("\nCo %d so nguyen to o trong mang",dem);
}
