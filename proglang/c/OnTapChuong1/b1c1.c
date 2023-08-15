#include <stdio.h>
#include <math.h>
//bai 1
void ptbac2(float a, float b, float c){
  float delta = pow(b,2)-(4*a*c);
  if (delta < 0) printf("\nPT vo nghiem");
  else if (delta == 0 ) printf("\nPT co nghiem kep x_1=x_2= %.2f", (-b)/(2*a));
  else {
    printf("\nPT co hai nghiem phan biet");
    printf("\nx_1 = %.2f",(-b+sqrt(delta))/(2*a));
    printf("\nx_2 = %.2f",(-b-sqrt(delta))/(2*a));
  }
}

int main (){
  float a,b,c;
  printf("Nhap a: "); scanf("%f",&a);
  printf("Nhap b: "); scanf("%f",&b);
  printf("Nhap c: "); scanf("%f",&c);

  printf("ba so vua nhap la %10.3f %10.3f %10.3f",a,b,c);
  ptbac2(a,b,c);
}
