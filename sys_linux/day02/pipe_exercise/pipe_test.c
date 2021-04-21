/*************************************************************************
	> File Name: pipe_test.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月01日 星期一 15时46分35秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<sys/wait.h>

int main()
{	
	int fd[2];
	int ret = pipe(fd);
	if(ret == -1)
	{
		perror("pipe:");
	}
	pid_t id = fork();
	if(id > 0)
	{
		close(fd[0]);
		write(fd[1], "hello pipe!", sizeof("hello pipe!"));
		wait(NULL);	
	}else if(id == 0)
	{
		close(fd[1]);
		char buf[1024];
		ret = read(fd[0], buf, sizeof(buf));
		if(ret == 0)
		{
			printf("-----\n");
		}
		write(STDOUT_FILENO, buf, ret);
	}

	return 0;
}
