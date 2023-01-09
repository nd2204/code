#include <stdio.h> 

int main() {
	int n,m;
	float array[50][50];
	float max;
	
	printf("Nhap hang (n): "); scanf("%d",&n);
	printf("Nhap cot (m): "); scanf("%d",&m);
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {printf("array[%d][%d]=",i,j); scanf("%f",&array[i][j]);}
	}
	
	printf("Ma tran kich thuoc nxm =\n");
	for (int i=0; i<n; i++) {
		printf("| ");
		for (int j=0; j<m; j++) {
			printf("%10.2f ",array[i][j]);
		}
		printf("|\n");
	}
	
	max=array[0][0];
	printf("\nCac so nguyen chia het cho 5 co trong ma tran la: ");
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if ((int)array[i][j]==array[i][j] && (int)array[i][j]%5==0) printf("%.2f ",array[i][j]);
			if (max<array[i][j] && i==0) max=array[i][j];
		}
	}
	printf("\nGia tri lon nhat trong hang 1 cua ma tran la: %.2f", max);
}



