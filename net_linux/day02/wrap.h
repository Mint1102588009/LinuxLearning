/*************************************************************************
	> File Name: wrap.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月22日 星期一 00时08分58秒
 ************************************************************************/
#ifndef WRAP_H
#define WRAP_H
#include<unistd.h>
void perr_exit(const char * s);
int Socket(int domain, int type, int protocol);
int Bind(int sockfd, const struct sockaddr * addr, socklen_t addrlen);
int Listen(int sockfd, int backlog);
int Accept(int sockfd, struct sockaddr * addr, socklen_t * addrlen);
ssize_t Read(int fd, void * buf, size_t count);
int Close(int fd);
#endif

