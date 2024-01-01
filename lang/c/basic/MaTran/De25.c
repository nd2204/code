#include <stdio.h>

int main() {
	int n,k;
	int count=0;
	int array[50][50];
	
	do {
		printf("Nhap n (2<=n<=5): "); scanf("%d",&n);
	} while (n<2 || n>5);
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++)
		{
			printf("array[%d][%d]=",i,j); scanf("%d",&array[i][j]);
		}
	}
	
	printf("array[%d][%d]=\n",n,n);
	for (int i=0; i<n; i++) {
		printf("| ");
		for (int j=0; j<n; j++)
		{
			printf("%d ",array[i][j]);
		}
		printf("|\n");
	}	
	
	do {
		printf("Nhap k (1<=k<=%d): ",n); scanf("%d",&k);
	} while (k>n || k<1);
	
	for (int j=0; j<n; j++) {
		if (array[k-1][j]>0) count++;		
	}
	printf("\nCo %d so duong o hang k=%d trong ma tran",count,k);
}
