#include <stdio.h>

int main(){
	int m,n,k;
	int array[50][50];
	int sum=0,count=0;
	
	printf("Ma tran MxN\n");
	printf("Nhap so hang (M): "); scanf("%d",&m);
	printf("Nhap so cot (N): "); scanf("%d",&n);
	
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			printf("array[%d][%d]= ",i,j); scanf("%d",&array[i][j]);
		}
	}
	
	printf("\narray[%d][%d]=\n",m,n);
	for (int i=0; i<m; i++) {
		printf("|");
		for (int j=0; j<n; j++) {
			printf(" %8d",array[i][j]);
		}
		printf(" |\n");
	}
	
	printf("\nCac gia tri thuoc hang 1 trong ma tran la:\n|");
	for (int j=0; j<n; j++) {
		printf(" %8d",array[0][j]);
	}
	printf(" |\n");
	
	do {
		printf("\nNhap K (0<K<=%d): ",n); scanf("%d",&k);
	} while (k<=0 || k>n);
	
	for (int i=0; i<m; i++) {
			sum+=array[i][k-1];
			count++;
	}
	printf("Trung binh cong cac phan tu thuoc cot %d trong ma tran la: %.2f",k,(float)sum/count);
}
