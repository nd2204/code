#include <stdio.h>

int main() {
	int n,m; 
	int count=0;
	int array[50][50];
	
	printf("Ma tran NxM\n");
	printf("Nhap so hang (N): "); scanf("%d",&n);
	printf("Nhap so cot (M): "); scanf("%d",&m);
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			printf("array[%d][%d] = ",i,j); scanf("%d",&array[i][j]);
		}
	}
	
	printf("array[%d][%d]=\n",n,m);
	for (int i=0; i<n; i++) {
		printf("|");
		for (int j=0; j<m; j++) {
			printf("%8d",array[i][j]);
			if (array[i][j]%2!=0) {count++;}
		}
		printf(" |\n");
	}
	printf("Co %d phan tu le trong ma tran",count);
	
	printf("\nCac phan tu chan co trong hang 1 cua ma tran la:\n |");
	for (int j=0; j<m; j++) {
		if(array[0][j]%2==0) printf("%8d",array[0][j]);
	}
	printf(" |");
}
