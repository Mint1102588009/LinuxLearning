/*************************************************************************
	> File Name: exercise1.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月06日 星期六 21时26分10秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void do_catch(int signo)
{
	printf("catched signo:%d\n", signo);
}

int main()
{
	sigset_t set, oldset, pset;
	int ret = sigfillset(&set);//创建信号集
	if(ret == -1){
		perror("sigemptyset err:");
	}
	ret = sigprocmask(SIG_BLOCK, &set, &oldset);//设置阻塞信号集
	if(ret == -1){
		perror("sigprocmask err:");
	}
	struct sigaction act;
	act.sa_handler = do_catch;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	sigaction(SIGINT, &act, NULL);
	sleep(5);
	ret = sigprocmask(SIG_UNBLOCK, &set, NULL);//设置阻塞信号集
	if(ret == -1){
		perror("sigprocmask err:");
	}


	return 0;
}
