//
// Created by KIM JINJAE on 2023/01/07.
//

#ifndef SOCKET_CLIENT_REQUEST_H
#define SOCKET_CLIENT_REQUEST_H

#include "library.h"

// 헤더에 들어가는 각종 내용들을 매크로로 정의하였습니다.
#define GET "GET"
#define POST "POST"
#define HTTP_VERSION "HTTP/1.1"
#define END_LINE    "\r\n"
#define MY_AGENT  "curl"
#define ACCEPT  "text/html"
#define ACCEPT_LANGUAGE "ko,en-US;q=0.9,en;q=0.8,ko-KR;q=0.7,ja;q=0.6"

void    requestController(int *localSocket, char *address, char *hierarchy);
void    createMessage(char *message, char *address, char *hierarchy);
void    receiveResponse(int *localSocket);

#endif //SOCKET_CLIENT_REQUEST_H
