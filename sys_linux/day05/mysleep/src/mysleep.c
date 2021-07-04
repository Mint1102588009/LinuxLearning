/*************************************************************************
	> File Name: mysleep.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月07日 星期日 12时24分06秒
 ************************************************************************/

#include"mysleep.h"
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void catch(int signo)
{

}

int mysleep(int sec)
{
	struct sigaction act;
	act.sa_handler = catch;
	act.sa_flags = 0;
	alarm(sec);
	sigaction(SIGALRM, &act, NULL);
	pause();
	printf("I sleep %d secs!", sec);

	return 0;
}
