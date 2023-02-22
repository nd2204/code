#include <stdio.h>
//Bai 6: nhap n in hien thi ra man hinh hinh tam giac bang dau *
void starLadder(int a){
  for (int i=0; i<a; i++) {
    for (int j=0; j<i+1; j++) {
      printf("*");
    }
    printf("\n");
  }
}
int main(){
  int n;
  printf("Nhap n:"); scanf("%d",&n);
  starLadder(n);
}
