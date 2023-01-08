//
// Created by KIM JINJAE on 2023/01/07.
//

#ifndef SOCKET_CLIENT_REQUEST_H
#define SOCKET_CLIENT_REQUEST_H

#include "library.h"

#define GET "GET"
#define HTTP_VERSION "HTTP/1.1"
#define END_LINE    "\r\n"
#define KEEP_ALIVE "keep-alive"
#define MY_AGENT  "curl"
#define ACCEPT  "text/html"
#define ACCEPT_LANGUAGE "ko,en-US;q=0.9,en;q=0.8,ko-KR;q=0.7,ja;q=0.6"

void    requestController(int *localSocket, char *address, char *hierarchy);
void    receiveResponse(int *localSocket);

#endif //SOCKET_CLIENT_REQUEST_H
