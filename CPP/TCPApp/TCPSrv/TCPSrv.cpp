#include <WinSock2.h>
#include <iostream>

using namespace std;


void main()
{
    WORD wVersionRequested;
    WSADATA wsaData;
    int err;

    wVersionRequested=MAKEWORD(1,1);

    err=WSAStartup(wVersionRequested,&wsaData);
    if (err)
    {
        return;
    }

    if (1!=LOBYTE(wsaData.wVersion)||1!=HIBYTE(wsaData.wVersion))
    {
        WSACleanup();
        return;
    }

    SOCKET sockSrv=socket(AF_INET,SOCK_STREAM,0);

    SOCKADDR_IN addrSrv;
    addrSrv.sin_addr.S_un.S_addr=htonl(INADDR_ANY);
    addrSrv.sin_family=AF_INET;
    addrSrv.sin_port=htons(6000);

    bind(sockSrv,(SOCKADDR *)&addrSrv,sizeof(SOCKADDR));
    listen(sockSrv,5);

    SOCKADDR_IN addrClient;
    int len=sizeof(SOCKADDR);

    while (TRUE)
    {
        SOCKET sockConn=accept(sockSrv,(SOCKADDR *)&addrClient,&len);
        char sendBuf[100];
        sprintf(sendBuf,"Wellcome %s",inet_ntoa(addrClient.sin_addr));
        send(sockConn,sendBuf,strlen(sendBuf)+1,0);
        char recvBuf[100];
        recv(sockConn,recvBuf,100,0);
        cout<<recvBuf<<endl;
        closesocket(sockConn);
    }
}