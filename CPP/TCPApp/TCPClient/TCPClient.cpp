#include <iostream>
#include <WinSock2.h>
using namespace std;

void main()
{
    WORD wVersionRequested;
    WSADATA wsaData;

    wVersionRequested=MAKEWORD(1,1);

    int err=WSAStartup(wVersionRequested,&wsaData);
    if (err)
    {
        return;
    }
    if (1!=LOBYTE(wsaData.wVersion)||1!=HIBYTE(wsaData.wVersion))
    {
        WSACleanup();
        return;
    }

    SOCKET sockClient=socket(AF_INET,SOCK_STREAM,0);

    SOCKADDR_IN addrSrv;
    addrSrv.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
    addrSrv.sin_family=AF_INET;
    addrSrv.sin_port=htons(6000);

    connect(sockClient,(SOCKADDR *)&addrSrv,sizeof(SOCKADDR));
    char recvBuf[100];
    recv(sockClient,recvBuf,100,0);
    cout<<recvBuf<<endl;
    char sendBuf[100];
    cin>>sendBuf;
    send(sockClient,sendBuf,strlen(sendBuf)+1,0);
    closesocket(sockClient);
    WSACleanup();

}