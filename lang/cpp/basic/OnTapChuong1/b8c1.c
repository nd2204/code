#include <stdio.h>
#include <stdio.h>

int isRect(float a, float b) {
  if (a>0 && b>0) return 1;
  return 0;
}

int main() {
  float a, b;
  printf("Nhap a: "); scanf("%f",&a);
  printf("Nhap b: "); scanf("%f",&b);

  if(isRect(a,b)) {
    if (a>b) {
      printf("\nChieu dai HCN = %7.2f",a);
      printf("\nChieu dai HCN = %7.2f",b);
    } else {
      printf("\nChieu dai HCN = %7.2f", b);
      printf("\nChieu rong HCN = %7.2f", a);
    }
    printf("\nChu vi HCN = %.2f",(a+b)/2);
    printf("\nDien tich HCN = %.2f",a*b);
  } else printf("Kich thuoc khong hop le");
}
