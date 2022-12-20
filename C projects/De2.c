#include <stdio.h>

int main(){
	int n;
	
	//vong lap do-while de in cac so tu 1 -> n 
	do { 	printf("nhap n (1<=n<=100): ");
		 	scanf("%d",&n);
			if (n < 1 || n > 100) printf("ban nhap sai.\n");
	} while (n < 1 || n > 100);
		
	
	printf("day so tu 1 -> %d: ", n);
	for (int i = 1; i<=n; i++) {
		printf("%d ",i);			
	}
	
	//Initialization 
	int count = 0;
	int sum = 0;
	printf("\nSo chia het cho 7 trong khoang 1 -> %d: ", n);
	
	for (int j = 1; j<=n; j++) { 
	
		//dieu kien de in ra cac so chia het cho 7
		if (j%7==0 ) printf("%d ",j);
		
		//dieu kien de tinh TBC cac so chan chia het cho 7
		if (j%14==0) { 
			count++;
			sum+=j;
		}
	}
	printf("\nTrung binh cong cac so chan chia het cho 7 trong khoang 1 -> %d la: %d",n,sum/count);
}
