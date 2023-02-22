#include <stdio.h>
#include <conio.h>

int main() {
    float a,b;
    printf("nhap a: "); scanf("%f",&a);
    printf("nhap b: "); scanf("%f",&b);

    printf("\nTong cua a va b: %.2f", a+b);
    printf("\nHieu cua a va b: %.2f", a-b);
    printf("\nTich cua a va b: %.2f", a*b);
    if (b==0) {
        printf("\nMau so = 0");
    } else printf("\nThuong cua a va b: %.2f", a/b);
    getch();
}
