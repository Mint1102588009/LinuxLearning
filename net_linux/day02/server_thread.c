/*************************************************************************
	> File Name: server_thread.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月22日 星期一 03时24分07秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<arpa/inet.h>
#include<ctype.h>
#include"wrap.h"

#define SERV_PORT 7777

void * thr_child(void * arg)
{
	int cfd = (int)arg;
	char buf[BUFSIZ];
	while(1){
		int ret = Read(cfd, buf, sizeof(buf));
		if(ret == 0){
			Close(cfd);
			break;
		}
		for(int i = 0; i < ret; i++)
			buf[i] = toupper(buf[i]);
		write(STDOUT_FILENO, buf, ret);
		write(cfd , buf, ret);
	}
	return NULL;
}

int main()
{
	int sfd, cfd;
	struct sockaddr_in sa, client;
	socklen_t client_len;
//	char buf[BUFSIZ];

	sfd = Socket(AF_INET, SOCK_STREAM, 0);
	sa.sin_family = AF_INET;
	sa.sin_port = htons(SERV_PORT);
	sa.sin_addr.s_addr = htonl(INADDR_ANY);
	Bind(sfd, (struct sockaddr *)&sa, sizeof(sa));
	Listen(sfd, 128);
	while(1){
		bzero(&client, sizeof(client));
		client_len = sizeof(client);
		cfd = Accept(sfd, (struct sockaddr *)&client, &client_len);
		pthread_t tid;
		pthread_create(&tid, NULL, thr_child, (void *)cfd);
		pthread_detach(tid);
	}

	return 0;
}
