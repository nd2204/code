#include <stdio.h>

int main(){
	int n;
	float array[50][50];
	float tong[50];
	
	printf("Ma tran NxN\n");
	printf("Nhap N: "); scanf("%d",&n);
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			printf("array[%d][%d]=",i,j); scanf("%f",&array[i][j]);
		}
	}
	
	printf("\narray[%d][%d]=\n",n,n);
	for (int i=0; i<n; i++) {
		printf("|");
		for (int j=0; j<n; j++) {
			printf(" %10.2f",array[i][j]);
			tong[i]+=array[i][j];
		}
		printf(" |\n");
	}
	
	printf("\nCac phan tu thuoc hang 1 cua ma tran la:\n|");
	for (int j=0; j<n; j++) {
		printf(" %10.2f",array[0][j]);
	}
	printf(" |\n\n");
	
	for (int i=0; i<n; i++) {
		printf("Tong hang %d cua ma tran la: %.2f\n",i+1,tong[i]);
	}
}
