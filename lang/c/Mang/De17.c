#include <stdio.h>

int main() {
	int n;
	int count=0,sum=0;
	int array[50];
	
	printf("Nhap so phan tu cua mang: ");scanf("%d",&n);
	
	for (int i=0; i<n; i++) {printf("Nhap gia tri cho phan tu %d cua mang: ",i); scanf("%d",&array[i]);} 
	
	printf("Gia tri cac phan tu cua mang lan luot la: ");
	for (int i=0; i<n; i++) {
		printf("%d ",array[i]);
	} 
	
	printf("\nCac phan tu co gia tri lon hon 9 trong mang lan luot la: ");
	for (int i=0; i<n; i++) {
		if (array[i]>9) printf("%d ",array[i]);
		if (array[i]%7==0) {
			sum+=array[i];
			count++;
		}
	} 
	
	printf("\nTrung binh cong cac phan tu chia het cho 7 co trong mang la: %d",sum/count);
}
