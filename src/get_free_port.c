#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#ifdef _WIN32
# include <winsock2.h>
# include <ws2tcpip.h>
#else
# include <sys/socket.h>
# include <netinet/in.h>
# include <unistd.h>
# define closesocket close
# define WSACleanup() 0
#endif//

int main(int argc, char* argv[])
{
    struct sockaddr_in serv_addr;
    socklen_t len;
    int enable = 1;
    int sock;
    int port = 0;
#ifdef _WIN32
    WORD versionWanted = MAKEWORD(1, 1);
    WSADATA wsaData;
    WSAStartup(versionWanted, &wsaData);
#endif    
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0) {
        printf("%d\n", port);
        return -1;
    }
#ifdef _WIN32
    if (setsockopt(sock, SOL_SOCKET, SO_EXCLUSIVEADDRUSE , (char*)&enable, sizeof(enable)) < 0) {
        printf("%d\n", port);
        return -1;
    }
#else
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (char*)&enable, sizeof(enable)) < 0) {
        printf("%d\n", port);
        return -1;
    }
#endif /* _WIN32 */
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = 0;
    if (bind(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
            printf("%d\n", port);
            return -1;
    }
    len = sizeof(serv_addr);
    if (getsockname(sock, (struct sockaddr *)&serv_addr, &len) == -1) {
        printf("%d\n", port);
        return -1;
    }
    if (closesocket (sock) == 0 ) {
        port = ntohs(serv_addr.sin_port);
    }
    printf("%d\n", port);
    WSACleanup();
    return (port != 0 ? 0 : -1);
}
