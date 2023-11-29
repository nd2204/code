#include <stdio.h>
//bai 2
void hpt2an (float a, float b, float c , float d, float e , float f) {
  float det  = a*e - d*b;
  float detX = c*e - f*b;
  float detY = a*f - d*c;

  if (det==0) {
    if (detX==0 && detY==0) {
      printf("\nHe co vo so nghiem");
    } else printf("\nHe vo nghiem");
  }
  else {
    printf("\nHe co nghiem duy nhat:");
    printf("\nx = %f",detX/det);
    printf("\ny = %f",detY/det);
  }
}

int main() {
  float a,b,c,d,e,f;
  printf("Nhap a,b,c,d,e,f: "); scanf("%f%f%f%f%f%f",&a,&b,&c,&d,&e,&f);
  printf("Day so vua nhap la \na=%10.2f b=%10.2f c=%10.2f\nd=%10.2f e=%10.2f f=%10.2f",a,b,c,d,e,f);
  hpt2an(a,b,c,d,e,f);
}
