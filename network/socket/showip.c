#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

typedef struct addrinfo addrinfo;

int main(int argc, char *argv[]) {
  int status;
  addrinfo hints, *res, *p;
  char string_ip[INET6_ADDRSTRLEN];

  if (argc != 2) {
    fprintf(stderr, "Usage: showip [hostname]\n");
    return 1;
  }

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  status = getaddrinfo(argv[1], NULL, &hints, &res);
  if (status != 0) {
    fprintf(stderr, "getaddrinfo returns error: %s\n", gai_strerror(status));
    return 2;
  }

  printf("IP addresses for %s:\n\n", argv[1]);
  for (p = res; p != NULL; p = p->ai_next) {
    void *addr;
    char *ipver;

    // IF current node is IPV4
    if (p->ai_family == AF_INET) {
      struct sockaddr_in *ipv4 = (struct sockaddr_in*) p->ai_addr;
      addr = &(ipv4->sin_addr);
      ipver = "IPV4";
    }
    else {
      struct sockaddr_in6 *ipv6 = (struct sockaddr_in6*) p->ai_addr;
      addr = &(ipv6->sin6_addr);
      ipver = "IPV6";
    }

    inet_ntop(p->ai_family, addr, string_ip, sizeof string_ip);
    printf("  %s: %s\n", ipver, string_ip);
  }

  freeaddrinfo(res);
  return 0;
}
