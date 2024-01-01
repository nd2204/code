#include <stdio.h>

int main() {
	int n; //so ngay lam viec cua 1 cong nhan
	int initialIncome;
	int bonusIncome;
	int totalIncome;
	
	do {
		printf("nhap so ngay lam viec cua cong nhan (0->31): ");
		scanf("%d",&n);
	} while (n<0 || n>31);
	
	initialIncome = n * 850;
	printf("Luong cua cong nhan do la: %d\n", initialIncome);
	
	if (n>=24) bonusIncome = (n-24)*200; //could be refactored in real situation with 24 will be changed as a variable
	else bonusIncome = 0;
	
	printf("so tien cong nhan do duoc thuong them la: %d\n", bonusIncome);
	totalIncome = initialIncome + bonusIncome; 
	printf("Tong thu nhap cua cong nhan do la: %d", totalIncome);
	
}

