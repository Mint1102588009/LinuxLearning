/*************************************************************************
	> File Name: udp_server.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月28日 星期日 18时09分14秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<strings.h>
#include<ctype.h>

#define SERV_PORT 7777
#define SERV_IP "127.0.0.1"

int main(){
	int lfd;
	struct sockaddr_in sa, client_addr;
	socklen_t client_addr_len;
	char buf[BUFSIZ];
	
	lfd = socket(AF_INET, SOCK_DGRAM, 0);
	sa.sin_family = AF_INET;
	sa.sin_port = htons(SERV_PORT);
	inet_pton(AF_INET, SERV_IP, &sa.sin_addr.s_addr);
	bind(lfd, (struct sockaddr *)&sa, sizeof(sa));
	while(1){
		client_addr_len = sizeof(client_addr);
		bzero(&client_addr, client_addr_len);
		int rdn = recvfrom(lfd, buf, sizeof(buf), 0, 
				(struct sockaddr *)&client_addr, &client_addr_len);
		if(rdn > 0){
			for(int i = 0; i < rdn; i++)
				buf[i] = toupper(buf[i]);
		}
		sendto(lfd, buf, sizeof(buf), 0,
				(struct sockaddr *)&client_addr, client_addr_len);
	}
	close(lfd);

	return 0;	
}
