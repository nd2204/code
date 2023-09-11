#include <stdio.h> 

int main() {
	int m,n,k;
	int count=0;
	double sum=0; 
	double array[50][50];
	double tich=1;
	
	
	printf("Ma tran MxN\n");
	printf("Nhap so hang (M): "); scanf("%d",&m);
	printf("Nhap so cot (N): "); scanf("%d",&n);
	
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			printf("array[%d][%d] = ",i,j); scanf("%lf",&array[i][j]);
		}
	}
	
	printf("\narray[%d][%d]=\n",m,n);
	for (int i=0; i<m; i++) {
		printf("|");
		for (int j=0; j<n; j++) {
			printf("%10.2lf",array[i][j]);
			sum+=array[i][j];
			count++;
		}
		printf(" |\n");
	}
	printf("Trung binh cong cac phan tu trong ma tran la: %.2lf\n", sum/count);
	
	do {
		printf("Nhap hang thu K (0<K<=%d): ",m); scanf("%d",&k);
	} while (k>m || k<=0);
	for (int j=0; j<n; j++) {
		tich*=array[k-1][j];
	}
	printf("Tich cua hang thu %d trong ma tran la: %.2lf",k,tich);
}





