/*************************************************************************
	> File Name: mydaemon.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月14日 星期日 19时33分19秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{	
	int ret, fd;
	ret = fork();
	if(ret == -1){//创建子进程
		perror("fork err:");
		exit(1);
	}else if(ret > 0){//终止父进程
		exit(0);
	}
	ret = setsid();//创建新会话
	if(ret == -1){
		perror("setsid err:");
		exit(1);
	}
	ret = chdir("/home/mint");//改变守护进程工作路径
	if(ret == -1){
		perror("chdir err:");
		exit(1);
	}
	umask(0022);//改变文件权限掩码
	close(STDIN_FILENO);//关闭标准写
	fd = open("/dev/null", O_RDWR);//重定向文件读写错误
	if(fd == -1){
		perror("open err:");
		exit(1);
	}
	dup2(fd, STDOUT_FILENO);
	dup2(fd, STDERR_FILENO);
	while(1); //模拟守护进程工作流程


	return 0;
}
