#include <stdio.h>

int main(){
	int n,x;
	int count=0;
	int sum=0;
	
	do {
		printf("nhap n (1<=n<=500): ");
		scanf("%d",&n);
	} while (n>500 || n<1);
	
	printf("cac so tu 1->n la: ");
	for (int i = 1; i<=n; i++) {printf("%d ", i);}
	
	do {
		printf("\nnhap x (1<=x<=n): ");
		scanf("%d",&x);
	} while (x>n || x<1);
	
	for (x ; x<=n; x++) {
		count++;
		sum+=x;
	}
	printf("\nTrung binh cong cac so tu x->n la: %d", sum/count);
}
