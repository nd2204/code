#include <stdio.h>

int main (){
  float a,b;
  printf(("Giai phuong trinh ax+b=0\n"));

  printf("nhap a:"); scanf("%f",&a);
  if (a==0) printf("Pt vo nghiem");
  else {
    printf("nhap b:"); scanf("%f",&b);
    if (b==0) printf("Pt co nghiem duy nhat:x=0");
    else printf("Pt co nghiem x=%.2f",b/a);
  }
}
