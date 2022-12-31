#include <stdio.h>

int main(){
	int t,m;
	
	do {
		printf("nhap thoi gian may gia cong cho 1 thiet bi man hinh [1;30]: ");
		scanf("%d",&t);
	} while (t>30 || t<1);
	
	printf("nhap so thiet bi can gia cong: ");
	scanf("%d",&m);
	
	printf("\nTong thoi gian may gia cong cho %d thiet bi la: %d", m, m*t);
	printf("\nTong chi phi gia cong cho %d thiet bi la: %d", m, m*500);
	
}
