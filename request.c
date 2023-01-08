//
// Created by KIM JINJAE on 2023/01/07.
//

#include "request.h"

void    requestController(int *localSocket, char *address, char *hierarchy)
{
    char	message[BUFFER_SIZE] = "";
    int	sendClientSocket = *(int *) localSocket;

    strcat(message, GET);
    strcat(message, " ");
    strcat(message, "/");
    if (hierarchy != NULL)
        strcat(message, hierarchy);
    strcat(message, " ");
    strcat(message, HTTP_VERSION);
    strcat(message, " ");
    strcat(message, END_LINE);

    strcat(message, "Host: ");
    strcat(message, address);
    strcat(message, END_LINE);

    strcat(message, "Connection: ");
    strcat(message, KEEP_ALIVE);
    strcat(message, END_LINE);

    strcat(message, "User-Agent: ");
    strcat(message, MY_AGENT);
    strcat(message, END_LINE);

    strcat(message, "Accept: ");
    strcat(message, ACCEPT);
    strcat(message, END_LINE);

    strcat(message, "Accept-Language: ");
    strcat(message, ACCEPT_LANGUAGE);
    strcat(message, END_LINE);

    strcat(message, END_LINE);

    printf("%s", message);

    if (send(sendClientSocket, message, BUFFER_SIZE - 1, 0) <= 0)
        throwException("SEND_ERR");
}

void    receiveResponse(int *localSocket)
{
    int	sendClientSocket = *(int *) localSocket;
    char html[BUFFER_SIZE];

    recv(sendClientSocket, html, BUFFER_SIZE - 1, 0);
    printf("%s\n", html);
}
