/*************************************************************************
	> File Name: alarm_exercise.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月04日 星期四 01时23分46秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	alarm(1);
	for(int i = 0;; i++){
		printf("%d\n", i);
	}

	return 0;
}

