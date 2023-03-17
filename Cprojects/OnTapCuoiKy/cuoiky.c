#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

//------------ EASY --------------

void cvdtTamGiac() {
    int a,b,c,cv;
    double p,dientich;
    printf("Nhap a: "); scanf("%d",&a);
    printf("Nhap b: "); scanf("%d",&b);
    printf("Nhap c: "); scanf("%d",&c);
    if (a>0 || b>0 || c>0) {
        if ( (a+b>c && a+c>b && b+c>a) && (abs(a-b)<c && abs(a-c)<b && abs(b-c)<a) ) {
            cv = a+b+c;
            p = (float)cv/2;
            dientich = sqrt(p*(p-a)*(p-b)*(p-c));
            printf("Chu vi tam giac la: %d", cv);
            printf("\nDien tich tam giac la: %.2f", dientich);
        }
    } else printf("Kich thuoc a,b,c khong phu hop");
}

void canBac2n() {
    float n;
    printf("Nhap n: "); scanf("%f",&n);
    while (n>1.01) {
        n=sqrt(n);
        printf("%.2f",n);
    }
}

void chuyenSangInHoa() {
    char ch;
    do {
        printf("Nhap ky tu thuong bat ky (a->z): "); scanf("%c",&ch);
    } while (!islower(ch) && !isalpha(ch));
    printf("chu in hoa cua %c la %c",ch, ch-32);
}

void sochinhphuong (int a) {
    if (sqrt(a)==(int)sqrt(a)) {
        printf("a la so chinh phuong");
    }
    else printf("a khong phai la so chinh phuong");
}

void ktDoiXung() {
    int size;
    printf("Nhap kich thuoc cua mang:"); scanf("%d",&size);
    const int n = size;
    int a[n];
    printf("Nhap %d so nguyen\n",n);
    for (int i=0; i<n; i++) {
        printf("a[%d] = ",i); scanf("%d",&a[i]);
    }

    int kt=1;
    for (int i=0; i<n/2; i++) {
        if (a[i]!=a[n-1-i]) {kt=0;break;}
    }
    if (kt==1) printf("Mang doi xung");
    printf("Mang khong doi xung");
}

void ptBacNhat() {
    int a,b;
    printf("Phuong trinh bac nhat 1 an ax+b=0:\n");
    printf("Nhap a:"); scanf("%d",&a);
    printf("Nhap b:"); scanf("%d",&b);

    if (a==0) {
        printf("Phuong trinh Vo nghiem");
    }
    else {
        printf("Phuong trinh co nghiem x=%.2f",(float)-b/a);
    }
}

//------------- MEDIUM -------------

void tachPhanTu() {
    int n,phandu;
    do {
        printf("Nhap n (n>1000): "); scanf("%d",&n);
    } while (n<=1000);

    printf("N=");
    int i=0;
    while (n>0) {
        phandu = n%10;
        n=(n-phandu)/10;
        printf("%d*10^%d",phandu,i);
        if (n!=0) printf(" + ");
        i++;
    }
}

void xoaPhanTuAm () {
    int n;
    int a[100];
    printf("Nhap n: "); scanf("%d",&n);
    for(int i=0; i<n; i++) {
        printf("a[%d] = ",i); scanf("%d",&a[i]);
    }
    int demSoDuong=0;
    for(int i=0; i<n; i++){
        if(a[i]>=0) a[demSoDuong++]=a[i];
    }
    printf("Mang moi la:");
    for(int i=0; i<demSoDuong; i++) {
        printf("%6d",a[i]);
    }
}

void themPhanTu () {
    int n;
    int a[100];
    printf("Nhap kich thuoc mang (toi da 100): "); scanf("%d",&n);

    printf("Nhap %d phan tu:\n",n);
    for(int i=0; i<n; i++) {
        printf("a[%d] = ",i); scanf("%d",&a[i]);
    }

    int vitri, giatri;
    printf("Nhap vi tri can them vao mang: "); scanf("%d",&vitri);
    printf("Nhap gia tri can them vao a[%d]:",vitri); scanf("%d",&giatri);
    for (int i=n-1; i>=vitri; i--) { 
        a[i+1] = a[i];
    }
    a[vitri]=giatri;
    printf("Mang moi la:");
    for (int i=0; i<=n; i++) {
        printf("%6d",a[i]);
    }
}

void soNguyenTo() {
    int size;
    printf("Nhap kich thuoc cua mang: "); scanf("%d",&size);
    const int n = size;
    int a[size];
    printf("Nhap %d so nguyen:\n",n);
    for (int i=0; i<n; i++) {
        printf("a[%d] = ",i); scanf("%d",&a[i]);
    }

    int kt;
    int dem=0;
    printf("So nguyen to co trong mang la: ");
    for (int i=0; i<n; i++) {
        if (a[i]>2 && a[i]%2!=0) {
            kt = 1;
            for (int j=3; j*j<=a[i]; j+=2) {
                if (a[i]%j==0) {
                    kt=0;
                    break;
                }
            }
            if (kt==1) {
                dem++;
                printf("%6d",a[i]);
            }
        }
    }
    printf("Co %d so nguyen to trong mang",dem);
}

void maTranChuyenVi() {
    int m,n;
    printf("Nhap m: "); scanf("%d",&m);
    printf("Nhap n: "); scanf("%d",&n);
    int a[m][n];
    printf("Ma tran %dx%d\n",m,n);
    for(int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            printf("a[%d][%d] = ",i,j); scanf("%d",&a[i][j]);
        }
    }
    printf("Ma tran vua nhap la:\n");
    for(int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            printf("%6d",a[i][j]);
        }
        printf("\n");
    }
    printf("Ma tran chuyen vi cua ma tran tren la:\n");
    for(int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            printf("%6d",a[j][i]);
        }
        printf("\n");
    }
}

void UclnBcnn() {
    int a,b,ucln,bcnn;
    do {
        printf("Nhap a: "); scanf("%d",&a);
        printf("Nhap b: "); scanf("%d",&b);
    } while (a<=0 || b<=0);

    for(int i=a; i>=1; i--) {
        if (a%i==0 && b%i==0) {
            ucln = i; 
            break;
        }
    }

    bcnn = (a*b)/ucln;
    printf("UCLN: %d\n",ucln);
    printf("BCNN: %d",bcnn);
}

//------------- SPECIAL -------------

void ptBac2() {
    float a,b,c;
    float x1,x2,delta;

    printf("Bat phuong trinh bac 2:\n");

    printf("Nhap a,b,c: "); scanf("%f%f%f",&a,&b,&c);

    delta = b*b-4*a*c;

    if (delta > 0) {
        x1 = (-b-sqrt(delta))/(2*a);
        x2 = (-b+sqrt(delta))/(2*a);
        printf("Phuong trinh co nghiem phan biet:\nx1 = %.2f\nx2 = %.2f",x1,x2);
    } else if (delta == 0) {
            x1 = -b/(2*a);
            printf("Phuong trinh co nghiem duy nhat: x1 = x2 = %.2f",x1);
    } else printf("Phuong trinh vo nghiem");
}


void hePT() {
    int a,b,c,d,e,f;
    float x,y,Det,DetX,DetY;

    printf("He phuong trinh bac nhat 2 an:\n");
    printf("ax+by=c\n");
    printf("dx+ey=f\n");

    printf("Nhap a,b,c: "); scanf("%d%d%d",&a,&b,&c);
    printf("Nhap d,e,f: "); scanf("%d%d%d",&d,&e,&f);

    Det = a*e-b*d;
    DetX = c*e-b*f;
    DetY = a*f-c*d;

    if (Det == 0) {
        if (DetX+DetY == 0) {
            printf("He phuong trinh co vo so nghiem"); 
        } else printf("He phuong trinh vo ngiem");
    } else {
        x = DetX/Det;
        y = DetY/Det;
        printf("Phuong trinh co ngiem:\nx = %.2f\ny = %.2f",x,y);
    }
}

void tamGiacPascal () {
    int n;
    printf("Tam giac PASCAL\n");
    printf("Nhap chieu cao: "); scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        int k=1;
        for (int j=1; j<n*2; j++) {
            if (j>n-i && j<n+i) {
                if (j==n) printf("%d",i);
                else {
                    if (j<n) {
                        printf("%d",k);
                        k++;
                    }
                    if (j>n) {
                        k--;
                        printf("%d",k);
                    }
                }
            }
            else printf(" ");
        }
        printf("\n");
    }
}

//------------- MAIN -------------

int main() {
    ptBac2();
}
