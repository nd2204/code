#include <stdio.h>

int main() {
	int n,m;
	int array[50][50];
	int sum=0;
	int min;
	
	printf("Ma tran NxM\n");
	printf("Nhap so hang (N): "); scanf("%d",&n);
	printf("Nhap so cot (M): "); scanf("%d",&m);
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			printf("array[%d][%d]=",i,j); scanf("%d",&array[i][j]);
		}
	}
	
	printf("array[%d][%d]=\n",n,m);
	for (int i=0; i<n; i++) {
		printf("|");
		for (int j=0; j<m; j++) {
			printf(" %8d",array[i][j]);
			sum+=array[i][j];
		}
		printf(" |\n");
	}
	printf("Tong cac phan tu cua ma tran la: %d",sum);
	
	min=array[0][0];
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (array[i][j]<min) min=array[i][j];
		}
	}
	printf("\nGia tri nho nhat cua ma tran la: %d",min);
	
}
