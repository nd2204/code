#include <stdio.h>
#include <math.h>

void SoChinhPhuong (int a) {
  if (sqrt(a)==(int)sqrt(a)) {
    printf("A la so chinh phuong");
  } else printf("A khong phai la so chinh phuong");
}

void SoNguyenTo() {
  int n;
  printf("Nhap n: "); scanf("%d",&n);
}

void xoaPhanTuAm () {
  int n;
  int a[100];
  printf("Nhap n: "); scanf("%d",&n);
  for(int i=0; i<n; i++) {
    printf("a[%d] = ",i); scanf("%d",&a[i]);
  }

  int demSoDuong=0;
  for(int i=0; i<n; i++){
    if(a[i]>=0) a[demSoDuong++]=a[i];
  }

  printf("Mang moi la:");
  for(int i=0; i<demSoDuong; i++) {
    printf("%6d",a[i]);
  }
}

void themPhanTu () {
  int n;
  int a[100];
  printf("Nhap kich thuoc mang (toi da 100): "); scanf("%d",&n);

  printf("Nhap %d phan tu:\n",n);
  for(int i=0; i<n; i++) {
    printf("a[%d] = ",i); scanf("%d",&a[i]);
  }

  int vitri, giatri;
  printf("Nhap vi tri can them vao mang: "); scanf("%d",&vitri);
  printf("Nhap gia tri can them vao a[%d]:",vitri); scanf("%d",&giatri);
  for (int i=n-1; i>=vitri; i--) {
    a[i+1] = a[i];
  }
  a[vitri]=giatri;
  printf("Mang moi la:");
  for (int i=0; i<=n; i++) {
    printf("%6d",a[i]);
  }
}

void tamGiacPascal () {

}

int main() {
  themPhanTu();
}
