#include <stdio.h>

int main(){
	int n;
	int array[50];
	
	printf("nhap so phan tu cua mang array:"); scanf("%d",&n);
	
	for (int i=0; i<n; i++) {printf("nhap gia tri cho phan tu thu %d cua mang array: ",i); scanf("%d",&array[i]);}
	
	int max=array[0];
	for (int i=0; i<n; i++) {
		printf("\nGia tri thu %d trong mang la: %d", i+1, array[i]);
		if (array[i]>max) {max=array[i];}	
	}
	printf("\nGia tri lon nhat trong mang la: %d", max);
}
