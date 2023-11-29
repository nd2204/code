#include <stdio.h>

int main() {
	int n;
	float temp;
	float array[50];
		
	printf("Nhap so phan tu cua mang: "); scanf("%d",&n);
	for (int i=0; i<n; i++) {printf("Nhap gia tri thu %d cho mang: ",i); scanf("%f",&array[i]);}
	
	for (int i=0; i<n; i++) {printf("\nGia tri thu %d trong mang la: %.2f",i,array[i]);}
	
	for (int i=0; i<n; i++) { 
	//Bubble sorting algorithm
	//vong lap de so sanh tung phan tu
		for (int j=0; j<n-i; j++) {
			if (array[j]<array[j+1]) {
				//doi cho 2 phan tu cho nhau khi gia tri cua phan tu truoc < phan tu sau
				temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
		}
	}
	
	printf("\nMang da duoc sap xep theo thu tu giam dan la: ");
	for (int i=0; i<n; i++) {printf("%.2f ",array[i]);}
}
