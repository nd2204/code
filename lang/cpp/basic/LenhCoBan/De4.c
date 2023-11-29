# include <stdio.h>

int main(){
	int n;
	int count=0,sumDiv10=0,sumDiv3=0;
	
	do {
		printf("nhap n: ");
		scanf("%d",&n);
	} while (n > 100 || n < 1);
	
	printf("cac so le tu 1 -> %d la: ",n);
	for (int i = 1; i<=n; i++) {
		if (i%2!=0) {printf("%d ",i);}
		if (i%3==0) {sumDiv3+=i;}
		if (i%10==0) {
			sumDiv10+=i;
			count++;
		}
	}
	printf("\ntong cac so chia het cho 3 trong khoang 1 -> %d la: %d",n,sumDiv3);
	printf("\ntrung binh cong cac so chan chia het cho 5 trong khoang 1 -> %d la: %.2f",n,(float)sumDiv10/count);
}
