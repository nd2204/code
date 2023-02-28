#include <stdio.h>
#include <math.h>

int main() {
  float a;
  printf("Nhap a: "); scanf("%f",&a);
  printf("so vua nhap la: %12.4f",a);
  printf("\nGia tri cua bieu thuc B = %f",(float)5*fabs(a)-pow(a,5));
}
