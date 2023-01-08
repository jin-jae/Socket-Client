//
// Created by KIM JINJAE on 2023/01/03.
//

#include "client.h"
#include <stdlib.h>

void    Client(void)
{
    printf("--------------- Client Program made by KIM JINJAE ---------------\n");
    char url[URL_MAX_SIZE];
    printf("Enter URL address (input must be \"IPv4:port\") (default: 127.0.0.1:49000) >> ");
    scanf("%s", url);

    char *ptr = strtok(url, ":/");
    char *address = ptr;
    ptr = strtok(NULL, ":/");
    char *port = ptr;
    int portNumber = atoi(port);
    ptr = strtok(NULL, ":/");
    char *hierarchy = ptr;

    printf("%s\n", hierarchy);

    printf("Address \"%s\" and port \"%d\"\n", address, portNumber);

    int localSocket;
    struct sockaddr_in  serverAddress;

    localSocket = socket(PF_INET, SOCK_STREAM, 0);
    if (localSocket == -1)
        throwException("SOCK_ERR");

    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr(address);
    serverAddress.sin_port = htons(portNumber);

    if (connect(localSocket, (struct sockaddr*) &serverAddress, sizeof(serverAddress)) == -1)
        throwException("CONNECT_ERR");

    requestController(&localSocket, address, hierarchy);
    receiveResponse(&localSocket);

    close(localSocket);
}
