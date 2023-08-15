#include <stdio.h>

int main(){
	int n;
	int count=0;
	int sumEvenNumber=0;
	int sumDiv6=0; 
	
	do {
		printf("nhap n (1<=n<=100): ");
		scanf("%d",&n);
	} while (n>100 || n<1);
	
	printf("cac so tu 1->n la: ");
	for (int i = 1; i<=n; i++) {
		printf("%d ",i);
		if (i%2==0) {sumEvenNumber+=i;}
		if (i%6==0) {
			sumDiv6+=i;
			count++;
		}	
	}
	printf("\nTong cac so chan tu 1->n la: %d", sumEvenNumber);
	printf("\nTrung binh cong cac so chan chia het cho 3 trong khoang 1->n la: %d", sumDiv6/count);
}
