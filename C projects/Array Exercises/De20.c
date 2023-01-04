#include <stdio.h>

int main() {
	int n;
	int count=0;
	float sum=0;
	float x;
	float array[50];
	 
	printf("Nhap so phan tu cho mang array: "); scanf("%d",&n);
	
	for (int i=0; i<n; i++) {
		printf("array[%d]= ",i); scanf("%f",&array[i]);
	}
	
	printf("array[%d]={",n);
	for (int i=0; i<n; i++) {
		printf("%.2f",array[i]);
		if (i<n-1) printf(",");
		if (i==n-1) printf("}");
		sum+=array[i];	
	}
	printf("\nTong cac phan tu trong mang la: %d",sum);
	
	printf("\nNhap X: "); scanf("%f",&x);
	for (int i=0; i<n; i++) {
		if (array[i]==x) {
			count++;
			array[i]=0;
		}
	}
	printf("Co %d phan tu trong mang bang X\nMang moi co dang: array[%d]={",count,n);
		for (int i=0; i<n; i++) {
		printf("%.2f",array[i]);
		if (i<n-1) printf(",");
		if (i==n-1) printf("}");
		sum+=array[i];	
	}
}
