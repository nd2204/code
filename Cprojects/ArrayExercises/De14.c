#include <stdio.h>

int main() {
	int n;
	int countPositive=0;
	int countX=0;
	float sum=0;
	float X;
	float array[50];
	
	printf("nhap so phan tu cho mang: "); scanf("%d",&n);
	
	for (int i=0; i<n; i++) {
		printf("Nhap gia tri cho phan tu thu %d: ",i); scanf("%f",&array[i]);
	}
	
	for (int i=0; i<n; i++) {
		printf("\nPhan tu thu %d = %.2f",i,array[i]);
	}
	printf("\nNhap gia tri cho X: "); scanf("%f",&X);
	for (int i=0; i<n; i++) {
		if (array[i]==X) {countX++;}
		if (array[i]>0) {
			sum+=array[i];
			countPositive++;
		}
	}
	
	if (countX==0) {
		printf("Khong ton tai so thuc X trong mang");
	} else printf("Co %d so thuc trong mang = so thuc X",countX);
	
	printf("\nTrung binh cong cac so duong trong mang la: %.2f", sum/countPositive);
	
}
