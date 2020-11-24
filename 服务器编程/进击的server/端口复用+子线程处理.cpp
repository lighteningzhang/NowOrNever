// Common sense
// 1. create socket
// 2. set connection

// 3. epoll监听
//    直接处理
//    线程池处理
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
/***
char 1个字节
short 2个字节
int 4个字节

struct sockaddr{
    sa_family_t sa_family;
    char sa_data[14];
}
// 14 * 1
struct sockaddr_in {
    short int sin_family; 
    // 地址族，AF_xxx 在socket编程中只能是AF_INET 
    unsigned short int sin_port; 
    // 端口号 （使用网络字节顺序）
    struct in_addr sin_addr;  
    // 存储IP地址 4字节 
    unsigned char sin_zero[8]; 
    // 总共8个字节，实际上没有什么用，只是为了和struct sockaddr保持一样的长度
    };
    2 + 2 + 4 + 8 = 16字节
***/ 
const int maxn = 1e5;
#define SERV_PORT 1000
int main () {
    int listen_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    char buf[BUFSIZ], client_IP[BUFSIZ];// 8192
    socklen_t client_len = 10;
    //sizeof client_addr;

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1;
    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof opt);


    bzero(&server_addr, sizeof server_addr);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERV_PORT);
    
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    bind(listen_fd, (struct sockaddr*) &server_addr, sizeof server_addr);
    listen(listen_fd, maxn);
    printf("Waiting for client\n");
    // bind
    // listen
    // read
    // inet_ntop
    // ntohs
    

    char RECV[maxn];
    while (1) {
        client_fd = accept(listen_fd, (struct sockaddr*) &client_addr, &client_len);
        printf("Client IP: %s\tClient Port: %d\n", 
        inet_ntop(AF_INET, &client_addr.sin_addr.s_addr, client_IP, sizeof client_IP), 
        ntohs(client_addr.sin_port));
        int pid = fork();
        if (pid == 0) {
            while (1) {
                int n = read(client_fd, buf, sizeof buf);
                if (n == 0) {
                    break;
                }
                for (int i = 0; i < n; i ++) {
                    buf[i] = toupper(buf[i]);
                }
                
                write(client_fd, buf, n);
                printf("Client IP: %s\tClient Port: %d ", 
        inet_ntop(AF_INET, &client_addr.sin_addr.s_addr, client_IP, sizeof client_IP), 
        ntohs(client_addr.sin_port));
                printf("sends the information: %s\n", buf);
            }
        } else {
            continue;
        }
        // sprintf(RECV, buf);
        
    }
    shutdown(listen_fd, SHUT_RDWR);
    shutdown(client_fd, SHUT_RDWR);
    return 0;
}