#include <stdio.h>

int main() {
	int m,n;
	int array[50][50];
	int sum=0, k=0;
	int max;
	
	printf("Ma tran MxN\n");
	printf("Nhap so hang (M): "); scanf("%d",&m);
	printf("Nhap so cot (N): "); scanf("%d",&n);
	
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			printf("array[%d][%d] = ",i,j); scanf("%d",&array[i][j]);
		}
	}
	
	printf("\narray[%d][%d]=\n",m,n);
	for (int i=0; i<m; i++) {
		printf("|");
		for (int j=0; j<n; j++) {
			printf("%8d",array[i][j]);
			sum+=array[i][j];
		}
		printf(" |\n");
	}
	printf("Tong cac phan tu trong ma tran la: %d", sum);
	
	max=array[0][0];
	for (int i=0; i<m; i++) {
		if (max<array[i][0]) {
			max=array[i][0];
			++k;
		}
	}
	printf("\nPhan tu co gia tri lon nhat cot 1 trong ma tran la: array[%d][%d]=%d",k,0,max);
}
