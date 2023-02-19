#include <stdio.h>

int main() {
	int n;
	int count=0;
	float sum=0;
	float array[50];
	
	printf("Nhap so phan tu cua mang: "); scanf("%d",&n);
	
	for (int i=0; i<n; i++) {printf("Nhap gia tri cho phan tu %d: ", i); scanf("%f",&array[i]);}
	for (int i=0; i<n; i++) {printf("\nGia tri thu %d = %.2f",i,array[i]);}
	
	printf("\nCac phan tu duong lan luot la: ");
	for (int i=0; i<n; i++) {
		if (array[i]>0) {
			printf("%.2f ",array[i]);
			sum+=array[i];
			count++;
		}
	}
	printf("\nTrung binh cong cac so duong trong mang la: %.2f", sum/count);
}
