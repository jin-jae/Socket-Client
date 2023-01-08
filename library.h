//
// Created by KIM JINJAE on 2023/01/03.
//

#ifndef SOCKET_CLIENT_LIBRARY_H
#define SOCKET_CLIENT_LIBRARY_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#include "client.h"
#include "exception.h"
#include "request.h"

#define BUFFER_SIZE 1024
#define URL_MAX_SIZE    2083

#endif //SOCKET_CLIENT_LIBRARY_H
