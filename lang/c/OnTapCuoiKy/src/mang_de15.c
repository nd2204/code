#include "stdio.h"

int main() {
  int n;
  printf("nhap n: "); scanf("%d",&n);
  int a[n];

  for(int i=0; i<n; i++) {
    printf("a[%d] = ", i); scanf("%d",&a[i]);
  }

  printf("mang vua nhap la:\n");
  for(int i=0; i<n; i++) printf("%6d",a[i]);

  int dem=0;
  for (int i=0; i<n; i++) { //Đếm phần tử âm có trong mảng
    if (a[i]<0) dem++;
  }
  for(int i=0; i<n-1; i++) { //Chạy từ phần tử i=(0,n-1)
    for (int j=i+1; j<n; j++) { //Chạy phần tử j=(1,n)
      while (a[i]<0) { //skip a[i]>=0 chỉ chạy khi a[i]<0
        if (a[j]>=0) { //đảo các phần tử âm xuống dưới khi a[j]>=0
          int temp = a[i];
          a[i] = a[j];
          a[j] = temp;
        } else break;
      }
    }
  } //Mảng sẽ có các phần tử âm nằm ở phía bên phải mảng

  printf("\nMang moi sau khi xoa phan tu am la:\n");
  // i<n-dem để bỏ qua những phần tử âm nằm phía bên phải mảng
  // thử thay i<n-dem -> i<n sẽ thấy các phần tử âm nằm bên phải mảng
  for(int i=0; i<n-dem; i++) printf("%6d",a[i]);
}

/* #include <stdio.h> */
/* int main(){ */ 
/*   int a[50], n; */
/*   printf("nhap n:"); scanf("%d", &n); */
/*   for(int i=0;i<n;i++) { */  
/*     printf("a[%d]=",i);scanf("%d", &a[i]); */
/*   } */
/*   printf("Mang vua nhap la : "); */
/*   for(int i=0;i<n;i++) printf("%5d", a[i]); */

/*   for(int i=0;i<n;i++) */
/*     while (a[i]<0) { */ 
/*       for(int j=i;j<n-1;j++) a[j]=a[j+1]; */
/*       n=n-1; */
/*     } */

/*   printf("\n Day so sau khi xoa la:"); */
/*   for(int i=0;i<n;i++) printf("%5d", a[i]); */
/* } */
