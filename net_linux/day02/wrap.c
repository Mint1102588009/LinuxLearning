/*************************************************************************
	> File Name: wrap.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月22日 星期一 00时08分58秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<errno.h>
#include"wrap.h"

void perr_exit(const char * s)
{
	perror(s);
	exit(-1);
}

int Socket(int domain, int type, int protocol)
{
	int ret = socket(domain, type, protocol);
	if(ret == -1)
		perr_exit("socket err:");
	return ret;
}

int Bind(int sockfd, const struct sockaddr* addr, socklen_t addrlen)
{
	int ret = bind(sockfd, addr, addrlen);
	if(ret == -1)
		perr_exit("bind err:");
	return ret;
}

int Listen(int sockfd, int backlog)
{
	int ret = listen(sockfd, backlog);
	if(ret == -1)
		perr_exit("listen err:");
	return ret;
}

int Accept(int sockfd, struct sockaddr* addr, socklen_t* addrlen)
{
	int ret;
again:
	ret = accept(sockfd, addr, addrlen);
	if(ret == -1)
	{
		if((errno == ECONNABORTED) || (errno == EINTR))
			goto again;
		else
			perr_exit("accept err:");
	}
	return ret;
}

ssize_t Read(int fd, void* buf, size_t count)
{
	ssize_t ret;
again:
	ret = read(fd, buf, count);
	if(ret == -1)
	{
		if(errno == EINTR)
			goto again;
		else
			perr_exit("read err:");
	}
	return ret;
}

int Close(int fd)
{
	int ret = close(fd);
	if(ret == -1)
		perr_exit("close err:");
	return ret;
}


