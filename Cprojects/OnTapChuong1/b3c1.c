#include <stdio.h>
//Bai 3
void zero2nineInText(int a) {
  char english[10][6] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
  char vietnamese[10][6] = {"khong","mot","hai","ba","bon","nam","sau","bay","tam","chin"};
  char japanese[10][6] = {"zero","ichi","ni","san","shi","go","roku","nana","hachi","kyu"};
//char chinese
  int input;
    printf("chon ngon ngu (1)Tieng Anh (2)Tieng Viet (3)Tieng Nhat:");
    scanf("%d",&input);

    switch (input) {
      case 1:
        printf("%s",english[a]);
      break;
      case 2:
        printf("%s",vietnamese[a]);
      break;
      case 3:
        printf("%s",japanese[a]);
      break;
      default: printf("%s",vietnamese[a]);
  }
}

int main() {
  int a;
  do {
    printf("Nhap a: "); scanf("%d",&a);
  } while(a>9 || a<0);
  zero2nineInText(a);
}
