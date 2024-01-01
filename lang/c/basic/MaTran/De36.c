#include <stdio.h>

int main() {
	int m,n,k;
	int max_i, max_j;
	int count=0;
	float array[50][50];
	float sum=0;
	float max;
	
	
	printf("Ma tran NxM\n");
	printf("Nhap so hang (N): "); scanf("%d",&n);
	printf("Nhap so cot (M): "); scanf("%d",&m);
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			printf("array[%d][%d] = ",i,j); scanf("%f",&array[i][j]);
		}
	}
	
	max=array[0][0];
	printf("array[%d][%d] =\n",n,m);
	for (int i=0; i<n; i++) {
		printf("|");
		for (int j=0; j<m; j++) {
			printf("%10.2f", array[i][j]);
			if (max<array[i][j]) {
				max=array[i][j];
				max_i=i;
				max_j=j;
			}
		}
		printf(" |\n");
	}
	
	do {
		printf("Nhap K (0<K<=%d): ",n); scanf("%d",&k);
	} while (k>n || k<=0);
	for (int j=0; j<m; j++) {
		sum+=array[k-1][j];
	}
	printf("Tong ket qua tren hang %d la: %.2f",k,sum);
	printf("\nGia tri lon nhat trong ma tran la: array[%d][%d] = %.2f", max_i, max_j, max);
	
}
