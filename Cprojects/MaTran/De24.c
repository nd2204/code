#include <stdio.h>

int main() {
	int m,n;
	int min;
	int count=0;
	int array[50][50];
	
	printf("Ma tran MxN\n");
	printf("Nhap M: "); scanf("%d",&m);
	printf("Nhap N: "); scanf("%d",&n);
	
	for (int row=0; row<m; row++) {
		for (int column=0; column<n; column++) {
			printf("array[%d][%d]=",row,column); scanf("%d",&array[row][column]);
		}
	}
	
	min=array[0][0];
	printf("array[%d][%d]=\n",m,n);
	for (int row=0; row<m; row++) {
		printf("| ");
		for (int column=0; column<n; column++) {
			printf("%10d ",array[row][column]);
			if (array[row][column]<min) min=array[row][column];
		}
		printf("|\n");
	}
	printf("\nGia tri nho nhat trong ma tran la: %d", min);
	
	printf("\nVi tri va gia tri cac phan tu la so am chia het cho 5 la:");
	for (int row=0; row<m; row++) {
		for (int column=0; column<n; column++) 
		{
			if (array[row][column]%5==0 && array[row][column]<0) {
				printf("\narray[%d][%d]=%d",m,n,array[row][column]);
				count++;
			}
		}	
	}
	if (count==0) printf("\nTrong ma tran khong co phan tu am chia het cho 5");		
	
	
}
