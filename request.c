//
// Created by KIM JINJAE on 2023/01/07.
//

#include "request.h"

void    requestController(int *localSocket, char *address, char *hierarchy)
{
    // message 문자열을 생성합니다.
    char	message[BUFFER_SIZE] = "";
    int	sendClientSocket = *(int *) localSocket;

    // 요청에 맞는 메시지를 생성합니다.
    createMessage(message, address, hierarchy);

    // server 에 해당 요청을 전송합니다.
    if (send(sendClientSocket, message, BUFFER_SIZE - 1, 0) <= 0)
        throwException("SEND_ERR");
}

void    createMessage(char *message, char *address, char *hierarchy)
{
    // client 에서 요청할 때 login.html 을 조회할 때에는 POST 요청, 아닌 경우에는 GET 요청을 하는 것으로 가정하였습니다.
    if (hierarchy != NULL && !strcmp(hierarchy, "login.html"))
    {
        // POST /login.html
        strcat(strcat(message, POST), " ");
        strcat(strcat(message, "/"), hierarchy);
        strcat(message, " ");
    }
    else
    {
        // GET /{hierarchy}
        strcat(strcat(message, GET), " ");
        strcat(message, "/");
        if (hierarchy != NULL)
            strcat(message, hierarchy);
        strcat(message, " ");
    }

    // HTTP/1.1
    strcat(strcat(message, HTTP_VERSION), END_LINE);
    // 각종 헤더들입니다.
    strcat(strcat(strcat(message, "Host: "), address), END_LINE);
    strcat(strcat(strcat(message, "User-Agent: "), MY_AGENT), END_LINE);
    strcat(strcat(strcat(message, "Accept: "), ACCEPT), END_LINE);
    strcat(strcat(strcat(message, "Accept-Language: "), ACCEPT_LANGUAGE), END_LINE);

    // 헤더의 끝을 알립니다.
    strcat(message, END_LINE);
}

void    receiveResponse(int *localSocket)
{
    int	sendClientSocket = *(int *) localSocket;
    char html[BUFFER_SIZE];

    // 서버로부터 response 메시지를 받아서 출력합니다.
    recv(sendClientSocket, html, BUFFER_SIZE - 1, 0);
    printf("%s\n", html);
}
