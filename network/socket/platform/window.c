#if defined(__MINGW32__) || defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)

// Prevent windows.h from including the older winsock.h header
#define WIN32_LEAN_AND_MEAN

#include "platform_socket.h"
#include "winsock2.h"
#include "ws2tcpip.h"

void sock_close() {
  closesocket();
}

#endif
