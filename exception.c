//
// Created by KIM JINJAE on 2022/12/29.
//
#include "exception.h"

/* client 프로그램 실행 과정에서 생기는 error를 처리하는 함수입니다.
 * 실제 상황에서는 프로그램 상으로 처리해야 할 내용이 있을 것이라는 가정 하에 분리해두었습니다. */
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