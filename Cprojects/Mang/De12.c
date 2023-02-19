#include <stdio.h>

int main(){
	int n;
	int array[50];
	int sum=0;

	printf("nhap so phan tu cua mang: "); scanf("%d",&n);

	for (int i=0; i<n; i++) {
		printf("nhap gia tri cho array[%d]: ",i); scanf("%d",&array[i]);
	}
	
	
	for (int i=0; i<n; i++) {
		printf("\ngia tri cua phan tu thu %d la: %d",i, array[i]);
	}
	
	for (int i=0; i<n; i++) {
		if (i%2==0) {sum+=array[i];} else printf("\ngia tri cua phan tu thu %d trong mang la: %d ",i,array[i]);
	}
	printf("\nTong gia tri cac phan tu chan trong mang la: %d", sum);
}
