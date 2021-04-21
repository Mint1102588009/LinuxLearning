/*************************************************************************
	> File Name: server_fork.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月22日 星期一 01时49分39秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"wrap.h"
#include<strings.h>
#include<arpa/inet.h>
#include<signal.h>
#include<ctype.h>
#include<sys/wait.h>

#define SERV_PORT 7777
typedef void (*sighandler_t)(int);

void wait_child(int signo)
{
	while((waitpid(0, NULL, WNOHANG) > 0));
	return;
}

int main()
{
	int sfd, cfd;
	pid_t pid;
	struct sockaddr_in sa, client;
	socklen_t client_len;
	char buf[BUFSIZ];

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
		pid = fork();
		if(pid == -1){
			perr_exit("fork err:");
		}else if(pid == 0){
			break;
		}else if(pid > 0){
			signal(SIGCHLD, wait_child);
		}
	}
	if(pid == 0){
		Close(sfd);
		while(1){
			int ret = Read(cfd, buf, sizeof(buf));
			if(ret == 0){
				Close(cfd);
				return 0;
			}else{
				for(int i = 0; i < ret; i++)
					buf[i] = toupper(buf[i]);
				write(cfd, buf, ret);
				write(STDOUT_FILENO, buf, ret);
			}
		}
	}

	return 0;
}
