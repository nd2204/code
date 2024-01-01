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

  printf("\n");

  //Chuyen tu mang cu sang mang moi
  int aNew[n+1];
  int k;

  do {
    printf("k la vi tri cua gia tri can nhap trong mang moi (k=[1,%d])\n",n+1);
    printf("Nhap k): "); scanf("%d",&k);
  } while (k<=0 || k>n+1);

  printf("Nhap gia tri cua vi tri [%d] trong mang moi: ",k-1); scanf("%d",&aNew[n]); //Dat gia tri vua nhap vao vi tri cuoi cung trong mang moi
  for(int i=0; i<n; i++) aNew[i]=a[i]; //Gan cac phan tu cua mang cu sang mang moi

  //Sap xep phan tu k ve dung vi tri
  int temp;
  for(int i=n; i>k-1; i--) {
    temp=aNew[i];
    aNew[i]=aNew[i-1];
    aNew[i-1]=temp;
  }

  //In ra mang moi
  printf("Mang moi la:\n");
  for (int i=0; i<=n; i++) {
    printf("%6d",aNew[i]);
  }
}
