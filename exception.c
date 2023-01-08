//
// Created by KIM JINJAE on 2022/12/29.
//
#include "exception.h"

void    throwException(char *exception) {
    printf("kernel error: ");
    if (!(strcmp(exception, "SOCK_ERR"))) {
        printf("Socket Error\n");
    }
    if (!(strcmp(exception, "CONNECT_ERR"))) {
        printf("Connection Error\n");
    }
    if (!(strcmp(exception, "READ_ERR"))) {
        printf("Message Read Error\n");
    }
    return;
}