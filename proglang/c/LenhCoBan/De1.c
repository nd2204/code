# include <stdio.h>
# include <conio.h>

int main() {
	int n,m; //n :thoi gian may gia cong 1 man hinh | m: so thiet bi can gia cong
    	int chiphi;
	
    while (1) { //yeu cau nhap dung
        printf("nhap thoi gian may gia cong 1 man (trong khoang 1<=n<=60): "); scanf("%d",&n);
        if (n >= 1 && n <= 60) break; else printf ("ban nhap sai\n");
    }
    	
    printf("\nnhap so thiet bi can gia cong: "); scanf("%d",&m);
	
    printf("Tong thoi gian may gia cong cho n thiet bi la: %d", m*n);
    
	//Dieu kien tinh chi phi gia cong
    if (n <= 30) chiphi=800*m;
    else chiphi=900*m;

    printf("\nTong chi phi cho m thiet bi la: %d", chiphi);
}

