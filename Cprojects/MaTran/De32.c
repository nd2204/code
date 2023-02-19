#include <stdio.h>

int main() {
	int m,n,k;
	double array[50][50];
	double tich=1;
	
	printf("Ma tran MxN\n");
	printf("Nhap so hang (M): "); scanf("%d",&m);
	printf("Nhap so cot (N): "); scanf("%d",&n);
	
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			printf("array[%d][%d]=",i,j); scanf("%lf", &array[i][j]);
		}
	}
	
	printf("array[%d][%d]=\n",m,n);
	for (int i=0; i<m; i++) {
		printf("|");
		for (int j=0; j<n; j++) {
			printf("%10.2lf",array[i][j]);
		}
		printf(" |\n");
	}
	
	printf("Cac phan tu tren cot 1 cua ma tran la:\n");
	for (int i=0; i<m; i++) {
		printf("|");
		printf("%10.2lf",array[i][0]);
		printf("|\n");
	}
	
	do {
		printf("Nhap row thu K (0<K<=%d):",m); scanf("%d",&k);
	} while (k>m || k<=0);
	for (int j=0; j<n; j++) {
		tich*=array[k-1][j];	
	}
	printf("\nTich cac phan tu thuoc hang K cua ma tran la: %.2lf",tich);
}





