#include <stdio.h>

int main() {
	int m,n,k;
	int count=0;
	float array[50][50];
	float sum=0;
	float min;
	
	
	printf("Ma tran NxM\n");
	printf("Nhap so hang (N): "); scanf("%d",&n);
	printf("Nhap so cot (M): "); scanf("%d",&m);
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			printf("array[%d][%d] = ",i,j); scanf("%f",&array[i][j]);
		}
	}
	
	min=array[0][0];
	printf("array[%d][%d] =\n",n,m);
	for (int i=0; i<n; i++) {
		printf("|");
		for (int j=0; j<m; j++) {
			printf("%10.2f", array[i][j]);
			if (min>array[i][j]) {
				min=array[i][j];
			}
		}
		printf(" |\n");
	}
	printf("Gia tri nho nhat trong mang la: %.2f\n", min);
	
	do {
		printf("Nhap K (0<K<=%d): ",n); scanf("%d",&k);
	} while (k>m || k<=0);
	for (int i=0; i<m; i++) {
		sum+=array[i][k-1];
	}
	printf("\nTong cac phan tu tren cot %d la: %.2f",k,sum);
}
