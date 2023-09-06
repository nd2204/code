#include <stdio.h>

int main() {
	int n;
	int count;
	float array[50];
	
	printf("Nhap so phan tu cho mang: "); scanf("%d",&n);
	
	for (int i=0; i<n; i++) {printf("array[%d]=",i); scanf("%f",&array[i]);}
	
	printf("array[%d]={",n);
	for (int i=0; i<n; i++) {
		printf("%.2f",array[i]);
		if (i<n-1) printf(",");
		if (i==n-1) printf("}");
	}
	
	printf("\nCac gia tri am co trong mang lan luot la: ");
	for (int i=0; i<n; i++) {
		if (array[i]<0) printf("%.2f",array[i]);
		if (array[i]>=30 && array[i]<=150) count++;
	}
	
	printf("\nCo %d phan tu co gia tri nam trong khoang 30->150 co trong mang",count);

}
