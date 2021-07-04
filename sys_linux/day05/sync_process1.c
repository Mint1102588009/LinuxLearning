/*************************************************************************
	> File Name: sync_process.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月07日 星期日 21时13分51秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>

int n, flag = 0;

void parent(int signo)
{
	printf("I am parent %d:%d\n", getpid(), n);
	n += 2;
	flag = 1;
}

void child(int signo)
{
	printf("I am child %d:%d\n", getpid(), n);
	n += 2;
	flag = 1;
}


int main()
{
	//设置屏蔽信号集
	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	sigprocmask(SIG_BLOCK, &set, NULL);
	//fork子进程	
	pid_t pid = fork();
	//父子进程注册
	if(pid == -1){
		perror("fork err:");
		exit(1);
	}else if(pid > 0){
		n = 1;
		struct sigaction act;
		act.sa_handler = parent;
		act.sa_flags = 0;
		sigemptyset(&act.sa_mask);
		parent(0);
		sigaction(SIGUSR2, &act, NULL);
		sigprocmask(SIG_UNBLOCK, &set, NULL);
		while(1){
			if(flag == 1)
				kill(pid, SIGUSR1);
		}
	}else{
		n = 2;
		struct sigaction act;
		sigemptyset(&act.sa_mask);
		act.sa_handler = child;
		act.sa_flags = 0;
		//child(0);
		sigaction(SIGUSR1, &act, NULL);
		sigprocmask(SIG_UNBLOCK, &set, NULL);
		while(1){
			if(flag = 1)
				kill(getppid(), SIGUSR2);
		}
	}

	return 0;
}
