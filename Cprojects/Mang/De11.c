#include <stdio.h>

int main(){
	int n,i;
	int array[n];
	
	printf("nhap so luong phan tu cua mang: ");
	scanf("%d",&n);
	
	for (i=0; i<n; i++) {
		printf("nhap gia tri cho array[%d] = ", i); scanf("%d",&array[i]); 
	}
	
	for (i=0; i<n; i++) {
		printf("\ngia tri cua phan tu thu %d trong mang la : %d", i, array[i]); 
	}
	
	int max = array[0];
	printf("\n(cac) so duong co trong mang la: ");
	for (i=0; i<n; i++) {
		if (array[i]>0) {
			printf("%d ", array[i]); 
		}
		if (array[i]>max) {
			max = array[i];
		}
	}
	printf("\nSo lon nhat trong mang la: %d",max);
	printf("\n");
}
