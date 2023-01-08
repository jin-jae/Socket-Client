//
// Created by KIM JINJAE on 2023/01/03.
//

#ifndef SOCKET_CLIENT_LIBRARY_H
#define SOCKET_CLIENT_LIBRARY_H

// read, write 등 저수준 함수를 포함하는 header 입니다.
#include <unistd.h>
// printf, 파일 입출력을 지원하는 header 입니다.
#include <stdio.h>
// atoi 를 지원하는 header 입니다.
#include <stdlib.h>
// socket 을 지원하는 header 입니다.
#include <sys/socket.h>
// inet_addr 함수를 이용해 IPv4 주소 조작을 하도록 지원하는 header 입니다.
#include <arpa/inet.h>
// strcmp, strcat 등 문자열 처리를 지원하는 header 입니다.
#include <string.h>

#include "client.h"
#include "exception.h"
#include "request.h"

// 메시지의 최대 사이즈는 1024, URL의 최대 길이는 256으로 임의로 지정하였습니다.
#define BUFFER_SIZE 1024
#define URL_MAX_SIZE    256

#endif //SOCKET_CLIENT_LIBRARY_H
