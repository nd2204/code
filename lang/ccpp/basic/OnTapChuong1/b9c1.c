#include <stdio.h>
#include <ctype.h>

int main () {
  char ch;

  printf("Nhap ngau nhien 1 ky tu:"); scanf("%c",&ch);
  printf("Ky tu vua nhap la: %c\n",ch);

  if (islower(ch)) printf("Ky tu la chu thuong");
  else if (isupper(ch)) printf("Ky tu la chu hoa");
  else if (isalnum(ch)) printf("Ky tu la chu so");
  else printf("Ky tu dac biet");
}
