#include <stdio.h>

int main() {
	int n;
	int array[50][50];
	int sum=0;
	
	printf("Nhap n:"); scanf("%d",&n);
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			printf("array[%d][%d]=",i,j); scanf("%d",&array[i][j]);
		}
	}
	
	printf("array[%d][%d]=\n",n,n);
	for (int i=0; i<n; i++) {
		printf("|");
		for (int j=0; j<n; j++) {
			printf(" %9d",array[i][j]);
		}
		printf(" |\n");
	}
	
	printf("\nCac phan tu chan co trong ma tran la: ");
	for (int i=0; i<n; i++)	{
		for (int j=0; j<n; j++) {
			if (array[i][j]%2==0) printf("%d ",array[i][j]);
			if (i==j) {sum+=array[i][j];}
		}
	}
	printf("\nTong cac phan tu thuoc duong cheo chinh la: %d", sum);
	
} 
