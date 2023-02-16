#include <stdio.h>

int main() {
	int n;
	float array[50];
	float min;
	
	printf("Nhap so phan tu cho mang: "); scanf("%d",&n);
	
	for (int i=0; i<n; i++) {printf("Nhap gia tri thu %d cho mang: ",i); scanf("%f",&array[i]);}
	
	min = array[0];
	printf("Cac gia tri trong mang lan luot la: ");
	for (int i=0; i<n; i++) {
		printf("%.2f ",array[i]);
		if (array[i]<min) min=array[i];	
	}	
	printf("\nGia tri nho nhat trong mang la: %.2f", min);
}
