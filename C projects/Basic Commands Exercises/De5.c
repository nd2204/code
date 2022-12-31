#include <stdio.h>

int main(){
	int n,a;
	int initialIncome;
	int overtimeIncome;
	int totalIncome;
	
	while (1) {
		printf("nhap so ngay lam viec cua cong nhan: ");
		scanf("%d",&n);
		if (n<=30 && n>=0) {break;}
		else printf("Ban nhap sai! Nhap lai\n");
	}
	
	initialIncome = n*400;
	printf("Thu nhap cua cong nhan do la: %d", initialIncome);
	
	printf("\nnhap so gio cong nhan do lam them: "); scanf("%d",&a);
	if (a<=50) overtimeIncome =a*200;
	else overtimeIncome=a*250;
	printf("Cong nhan lam them dc %d tieng va nhan duoc them %d", a, overtimeIncome);
	
	totalIncome = initialIncome + overtimeIncome;
	printf("\nTong thu nhap cua cong nhan do la: %d", totalIncome);
}
