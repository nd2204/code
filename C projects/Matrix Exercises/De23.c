#include <stdio.h>

int main() {
	int n;
	int max;
	int sum=0;
	int array[50][50];
	
	printf("Nhap so nguyen N cho ma tran kich thuoc N x N: "); scanf("%d",&n);
	
	for (int row=0; row<n; row++) {
		for (int column=0; column<n; column++) {printf("array[%d][%d]=",row,column); scanf("%d",&array[row][column]);}
	}
	
	max=array[0][0];
	printf("array[%d][%d]=\n",n,n);
	for (int row=0; row<n; row++) {
		printf("| ");
		for (int column=0; column<n; column++) 
		{
			printf("%d ",array[row][column]);
			if (array[row][column]>max) max=array[row][column];
			if (row==column) sum+=array[row][column];
		}
		printf("|\n");
	}
	printf("\nSo lon nhat trong mang la: %d",max);
	printf("\nTong gia tri cac phan tu thuoc duong cheo chinh la: %d", sum);
}
