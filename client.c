//
// Created by KIM JINJAE on 2023/01/03.
//

#include "client.h"

void    Client(void)
{
    printf("--------------- Client Program made by KIM JINJAE ---------------\n");
    char url[URL_MAX_SIZE];
    printf("Enter URL address (input must be \"IPv4:port/hierarchy\") (example: 127.0.0.1:50000/index.html) >> ");
    // URL 을 입력받음
    scanf("%s", url);

    // 입력받은 URL 을 분리
    // address == 127.0.0.1
    char *ptr = strtok(url, ":/");
    char *address = ptr;
    // port == 50000
    ptr = strtok(NULL, ":/");
    char *port = ptr;
    int portNumber = atoi(port);
    // hierarchy -> 최초 1계층의 내용 (해당 program 은 1계층까지 지원)
    ptr = strtok(NULL, ":/");
    char *hierarchy = ptr;

    printf("Address \"%s\" and port \"%d\" confirmed.\n", address, portNumber);

    int localSocket;
    struct sockaddr_in  serverAddress;

    printf("Setting server socket... ");
    /* socket function : parameters
     *  domain - Determines which domain that communication happens.
     *  type - Indicates semantics of communication. (TCP 연결)
     *  protocol - Determines which protocol to be used in the socket.
    */
    localSocket = socket(PF_INET, SOCK_STREAM, 0);
    // 성공적으로 열지 못하면 -1 반환
    if (localSocket == -1)
        throwException("SOCK_ERR");
    printf("done!\n");

    printf("Setting server address... ");
    // serverAddress 메모리 내용을 초기화
    memset(&serverAddress, 0, sizeof(serverAddress));
    // serverAddress 내용 설정
    // UDP or TCP
    serverAddress.sin_family = AF_INET;
    // 입력한 address 내용 가져옴 (127.0.0.1)
    // inet_addr 은 127.0.0.1 text 를 IPv4 주소로 인식하도록 변환
    serverAddress.sin_addr.s_addr = inet_addr(address);
    // 개방할 Port Number 설정
    serverAddress.sin_port = htons(portNumber);
    printf("done!\n");

    printf("Connecting client socket with server address... ");
    // client Socket 과 server 주소를 연결
    // 성공 시 0, 실패 시 -1 반환
    if (connect(localSocket, (struct sockaddr*) &serverAddress, sizeof(serverAddress)) == -1)
        throwException("CONNECT_ERR");
    printf("done!\n");

    printf("------------------ System Connection Completed ------------------\n");

    // 전송할 요청 메시지를 생성하는 requestController 함수 실행
    requestController(&localSocket, address, hierarchy);

    // 서버에서 처리한 결과 메시지를 수신하는 receiveResponse 함수 실행
    receiveResponse(&localSocket);

    // socket 닫기 (프로그램 종료)
    close(localSocket);
    printf("-------------------------- Program End --------------------------\n");
}
