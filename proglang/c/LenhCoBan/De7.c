#include <stdio.h>

int main() {
	int n;
	int sum=0;
	int sumEvenNumber=0;
	int count=0;
	
	do {
		printf("nhap n (1<=n<=100): "); scanf ("%d",&n);
	} while (n<1 || n>100);
	
	printf("cac so tu 1 -> %d la: ", n);
	for (int i = 1; i<=n; i++) {
		printf("%d ",i);
	}
	
	if (n>=5) {
		printf("\ncac so lon hon 5 tu 1->%d la: ", n);
		for (int j = 5; j<=n; j++) {
			printf("%d ",j);
			sum+=j;
			if (j%2==0) {
			count++;
			sumEvenNumber+=j;
			}
		}
	printf("\nTong cac so lon hon 5 trong khonag tu 1->%d la: %d", n, sum);
	printf("\nTrung binh cong cac so chan lon hon 5 trong khoang tu 1->%d la: %d", n, sumEvenNumber/count);
	} else printf("\nkhong co so nao >= 5 trong khoang tu 1->%d: ",n);
}
