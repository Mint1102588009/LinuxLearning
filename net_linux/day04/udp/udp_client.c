/*************************************************************************
	> File Name: udp_client.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月28日 星期日 19时38分10秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<strings.h>
#include<arpa/inet.h>
#include<unistd.h>

#define SERV_PORT 7777
#define SERV_IP "127.0.0.1"

int main(){
	int sfd;
	struct sockaddr_in servaddr;
	char buf[BUFSIZ];

	sfd = socket(AF_INET, SOCK_DGRAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	inet_pton(AF_INET, SERV_IP, &servaddr.sin_addr.s_addr);
	bind(sfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	while(fgets(buf, sizeof(buf), stdin)){
		sendto(sfd, buf, sizeof(buf), 0,
				(struct sockaddr *)&servaddr, sizeof(servaddr));
		int rdn = recvfrom(sfd, buf, sizeof(buf), 0, NULL, 0);
		write(STDOUT_FILENO, buf, rdn);
	}
	close(sfd);

	return 0;
}
