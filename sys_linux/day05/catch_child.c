/*************************************************************************
	> File Name: catch_child.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月12日 星期五 23时57分53秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void catch_child(int signo){
	pid_t pid;
	int status;
	while((pid = waitpid(0, &status, WNOHANG)) > 0){
		if(WIFEXITED(status)){
			printf("catch child %d\n", WEXITSTATUS(status));
		}else if(WIFSIGNALED(status)){
			printf("has been signaled by %d\n", WTERMSIG(status));
		}
	}
}

int main()
{	
	pid_t pid;
	int i = 0;
	sigset_t newset, oldset;
	sigemptyset(&newset);
	sigaddset(&newset, SIGCHLD);
	sigprocmask(SIG_BLOCK, &newset, &oldset);
	for(; i < 5; i++){
		pid = fork();
		if(pid == 0){
			printf("I am child %d\n", getpid());
			return i;
		}else if(pid == -1){
			perror("fork err:");
			exit(1);
		}
	}
	struct sigaction act;
	act.sa_handler = catch_child;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	sigaction(SIGCHLD, &act, NULL);
	sigprocmask(SIG_UNBLOCK, &newset, NULL);
//	sleep(1);
	printf("I am father %d\n", getpid());
	while(1);

	return 0;
}
