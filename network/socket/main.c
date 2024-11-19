#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <errno.h>

#define MYPORT "3490"
#define BACKLOG 10

typedef unsigned int u32;
typedef struct addrinfo addrinfo;
typedef struct sockaddr_storage sockaddr_storage;
typedef struct sockaddr sockaddr;

inline int ai_bind(int sockfd, const addrinfo *restrict res) {
  return bind(sockfd, res->ai_addr, res->ai_addrlen);
}

inline int ai_socket(const addrinfo *restrict res) {
  return socket(res->ai_family, res->ai_socktype, res->ai_protocol);
}

int main() {
  addrinfo hints, *res;

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  int status;
  if ((status = getaddrinfo(NULL, MYPORT, &hints, &res)) != 0) {
    fprintf(stderr, "getaddrinfo return error: %s", gai_strerror(status));
    return 1;
  }

  // Create a listening socket
  int sockfd = ai_socket(res);
  if (sockfd == -1) {
    fprintf(stderr, "socket error: %s", strerror(errno));
    return 2;
  }
  ai_bind(sockfd, res);
  listen(sockfd, BACKLOG);

  // Accept incomming connection
  char in_msg[256];
  sockaddr_storage their_addr;
  u32 their_len = sizeof(sockaddr_storage);
  int newfd = accept(sockfd, (sockaddr *)&their_addr, &their_len);
  if (newfd == -1) {
    fprintf(stderr, "socket error: %s", strerror(errno));
    return 3;
  }

  int byte_recv = recv(newfd, in_msg, 255, 0);
}
