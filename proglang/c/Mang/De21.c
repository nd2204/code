#include <stdio.h>

int main(){
	int n;
	int max;
	float sum=0;
	int count=0;
	int array[50];
	
	printf("Nhap so phan tu cho mang: "); scanf("%d",&n);
	
	for (int i=0; i<n; i++) {
		printf("array[%d]= ",i); scanf("%d",&array[i]);
	}
	
	max=array[0];
	printf("array[%d]={",n);
	for (int i=0; i<n; i++) {
		printf("%d",array[i]);
		if (i<n-1) printf(",");
		if (i==n-1) printf("}");
		
		if (array[i]>max){
			max=array[i];
		}
		if (i%2!=0) {
			sum+=array[i];
			count++;
		}
	}
	printf("\nGia tri lon nhat cua mang la: %d", max);
	printf("\nTrung binh cong cac phan tu tai vi tri le trong mang la: %.2f", sum/count);
	
}
