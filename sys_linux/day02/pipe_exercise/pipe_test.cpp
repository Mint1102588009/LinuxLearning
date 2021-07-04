/*************************************************************************
	> File Name: pipe_test.cpp
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年02月26日 星期五 00时13分04秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<cstdlib>
#include<cstring>

int main()
{
	pid_t id;
	int fd[2];
	int ret = pipe(fd);
	char * buf;
	if(ret == -1){
		perror("pipe error:");
		exit(1);
	}
	id = fork();
	if(id == -1){
		perror("fork error:");
		exit(1);
	}else if(id == 0){
		close(fd[1]);
		ret = read(fd[0],buf,sizeof(buf));
		write(STDOUT_FILENO, buf, ret);
	}else{
		close(fd[0]);
		write(fd[1], "hello pipe\n", strlen("hello pipe\n"));
	}

	return 0;
}
