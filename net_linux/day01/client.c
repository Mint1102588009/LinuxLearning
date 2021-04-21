/*************************************************************************
	> File Name: client.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月20日 星期六 15时00分26秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<string.h>
#include<arpa/inet.h>

#define SERV_IP "127.0.0.1"
#define NETPORT 7777

int main()
{
	int cfd;
	struct sockaddr_in serv_addr;
	char buf[BUFSIZ];
	cfd = socket(AF_INET, SOCK_STREAM, 0);
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(NETPORT);
	inet_pton(AF_INET, SERV_IP, &serv_addr.sin_addr.s_addr);
	connect(cfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	while(1){
		int ret;
		fgets(buf, sizeof(buf), stdin);
		write(cfd, buf, strlen(buf));
		ret = read(cfd, buf, sizeof(buf));
		write(STDOUT_FILENO, buf, ret);
	}
	close(cfd);
	return 0;
}
