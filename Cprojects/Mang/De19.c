#include <stdio.h>

int main() {
	int n;
	int array[50];
	int sum=0;

	printf("Nhap so phan tu cho mang: "); scanf("%d", &n);

	for (int i=0; i<n; i++) {
		printf("array[%d]= ",i); scanf("%d", &array[i]);
	}

	printf("array[%d] = { ",n);
	for (int i=0; i<n; i++) {
		printf("%d", array[i]);
		if (i<n-1) printf(", ");
		if (i==n-1) printf(" }");
	}

	printf("\nCac phan tu co gia tri chan trong mang lan luot la: ");
	for (int i=0; i<n; i++) {
		if (array[i]%2==0) printf("%d ",array[i]);
		if (i%2==0){
			sum+=array[i];
		}
	}

	printf("Tong gia tri cac phan tu o vi tri chan trong mang la: %d", sum);
}
