#include <stdio.h>

int main(){
	
	int x,y,i;
	int sum = 0;
	
	/*
	do {
		//Typing Inputs for x and y
		printf("nhap x,y (x<y)\n");
		printf("x: "); scanf("%d",&x);
		printf("y: "); scanf("%d",&y);			
	}	while (x > y);
	*/
	
	while (1) {
		//Typing Inputs for x and y
		printf("nhap x,y (x<y)\n");
		printf("x: "); scanf("%d",&x);
		fflush(stdin);
		printf("y: "); scanf("%d",&y);			
		if (x<y) break;
	}	
	
	
	printf("Tong hai so x va y la: %d", x+y);
	
	i = x;
	printf("\nCac so chan trong khoang %d -> %d la:",x,y);
	while (i<=y) {
		if (i%2==0) printf("%d ",i);
		sum += i;
		i++;  		
	}
	printf("\nTong cua cac so trong khoang %d den %d la: %d",x,y,sum);
}
