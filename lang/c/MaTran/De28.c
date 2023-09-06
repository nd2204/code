#include <stdio.h>

int main() {
	int m,n,k;
	int array[50][50];
	int sumAvg=0;
	int count=0;

	printf("Ma tran MxN\n");
	printf("Nhap so hang (M) = "); scanf("%d",&m);
	printf("Nhap so cot (N) = "); scanf("%d",&n);	
	
	//for loop - input
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			printf("array[%d][%d]=",i,j); scanf("%d",&array[i][j]);
		}
	}
	//for loop - print out matrix with rows and columns
	printf("array[%d][%d]=\n",m,n);
	for (int i=0; i<n; i++) {
		printf("|");
		for (int j=0; j<n; j++) {
			printf(" %9d",array[i][j]); 
		}
		printf(" |\n");
	}
	//for loop - checking and printing odd numbers
	printf("\nCac phan tu le co trong ma tran la: ");
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (array[i][j]%2!=0) printf("%d ",array[i][j]); 
		}
	}
	printf("\n");
	//do-while loop - input column k for reference
	do {
		printf("Nhap cot K (0<K<=%d):",n); scanf("%d",&k);
	} while (k>n || k<=0);
	//for loop - calculating the average of the values in the matrix in column k
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (j==k-1) {
				sumAvg+=array[i][j];
				count++; 
			}
		}
	}
	printf("Trung binh cong cac phan tu thuoc cot K cua ma tran la: %.2f",(float)sumAvg/count);
}









