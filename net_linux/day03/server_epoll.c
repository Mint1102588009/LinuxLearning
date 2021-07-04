/*************************************************************************
	> File Name: server_epoll.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月24日 星期三 02时18分55秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<sys/epoll.h>
#include<strings.h>
#include<ctype.h>

#define SERV_PORT 7777
#define SERV_IP "127.0.0.1"
#define OPEN_MAX 1024

int main()
{
	int lfd, cfd, sfd, efd;
	int nready, nrd;
	struct sockaddr_in sa, client_addr;
	struct epoll_event tep, ep[OPEN_MAX];
	socklen_t client_len;
	char str[INET_ADDRSTRLEN], buf[BUFSIZ];

	lfd = socket(AF_INET, SOCK_STREAM, 0);

	int opt = 1;
	setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));//设置端口复用

	sa.sin_family = AF_INET;
	sa.sin_port = htons(SERV_PORT);
	inet_pton(AF_INET, SERV_IP, &sa.sin_addr.s_addr);
	bind(lfd, (struct sockaddr *)&sa, sizeof(sa));
	listen(lfd, 128);
	efd = epoll_create(OPEN_MAX);
	tep.events = EPOLLIN;
	tep.data.fd = lfd;
	epoll_ctl(efd, EPOLL_CTL_ADD, lfd, &tep);
	while(1){
		nready = epoll_wait(efd, ep, OPEN_MAX, -1);
		for(int i = 0; i < nready; i++){
			if(!(ep[i].events & EPOLLIN))
				continue;
			if(ep[i].data.fd == lfd){
				bzero(&client_addr, sizeof(client_addr));
				client_len = sizeof(client_addr);
				cfd = accept(lfd, (struct sockaddr *)&client_addr, &client_len);
				printf("received from %s at PORT:%d\n",
						inet_ntop(AF_INET, &client_addr.sin_addr, str, sizeof(str)),
						ntohs(client_addr.sin_port));
				tep.events = EPOLLIN;
				tep.data.fd = cfd;
				epoll_ctl(efd, EPOLL_CTL_ADD, cfd, &tep);
			}else{
				sfd = ep[i].data.fd;
				nrd = read(sfd, buf, sizeof(buf));
				if(nrd == 0){
					epoll_ctl(efd, EPOLL_CTL_DEL, sfd, NULL);
					close(sfd);
				}else{
					for(int j = 0; j < nrd; j++)
						buf[j] = toupper(buf[j]);
					write(sfd, buf, nrd);
					write(STDOUT_FILENO, buf, nrd);
				}
			}
		}
	}
	return 0;
}
