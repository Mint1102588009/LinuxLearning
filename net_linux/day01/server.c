/*************************************************************************
	> File Name: server.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月20日 星期六 00时57分45秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<ctype.h>

#define SERV_IP "127.0.0.1"
#define NETPORT 7777

int main()
{
	int lfd, cfd;//创建两个socket文件描述符
	struct sockaddr_in serv_addr, clie_addr;//创建服务端与客户端套接字属性结构体
	char buf[BUFSIZ], clie_IP[BUFSIZ];//创建字符缓冲区
	int r_num;//read函数读取的字节数

	lfd = socket(AF_INET, SOCK_STREAM, 0);//创建一个套接字
	serv_addr.sin_family = AF_INET;//设置协议族为IPV4
	serv_addr.sin_port = htons(NETPORT);//设置端口号
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);//设置IP地址
	bind(lfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	//绑定一个客户端可知的IP地址
	listen(lfd, 128);//监听和设置同时最大连接数

	socklen_t clie_addrlen = sizeof(clie_addr);
	cfd = accept(lfd, (struct sockaddr*)&clie_addr, &clie_addrlen);
	//连接并返回客户端socket文件描述符
	printf("client IP: %s, client port: %d\n",
			inet_ntop(AF_INET, &clie_addr.sin_addr.s_addr, clie_IP, sizeof(clie_IP)),
			ntohs(clie_addr.sin_port));
	while(1)
	{
		r_num = read(cfd, buf, sizeof(buf));
		for(int i = 0; i< r_num; i++)
			buf[i] = toupper(buf[i]);
		write(cfd, buf, r_num);
	}
	close(cfd);
	close(lfd);

	return 0;
}
