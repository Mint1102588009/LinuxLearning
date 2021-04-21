/*************************************************************************
	> File Name: setpgid_exercise.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月13日 星期六 16时39分40秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	pid_t pid = fork();
	if(pid == -1){
		perror("fork err:");
		exit(1);
	}else if(pid == 0){
		pid_t grp = getpgid(getppid());
		printf("I am child:%d,my groupid:%d\n", getpid(), grp);
		setpgid(getpid(), getpid());
		printf("I am child:%d,my groupid:%d\n", getpid(), getpgrp());
		return 0;
	}else{
		printf("I am parent:%d,my groupid:%d\n", getpid(), getpgrp());
		sleep(7);
		setpgid(getpid(), pid);
		printf("I am parent:%d,my groupid:%d\n", getpid(), getpgrp());
	}
	return 0;
}
