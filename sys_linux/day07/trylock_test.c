/*************************************************************************
	> File Name: dead_lock.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月16日 星期二 00时47分28秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

pthread_mutex_t mutA, mutB;

void* thrd_f(void* arg)
{
	while(1){
		pthread_mutex_trylock(&mutA);
		pthread_mutex_lock(&mutB);
		printf("I am child thread.\n");
//		sleep(2);
		pthread_mutex_unlock(&mutA);
		pthread_mutex_unlock(&mutB);
	}
	return NULL;
}

int main()
{	
	pthread_t tid;
	pthread_create(&tid, NULL, thrd_f, NULL);
	pthread_detach(tid);
	pthread_mutex_init(&mutA, NULL);
	pthread_mutex_init(&mutB, NULL);
	while(1){
		pthread_mutex_trylock(&mutB);
		pthread_mutex_lock(&mutA);
		printf("I am parent thread.\n");
//		sleep(2);
		pthread_mutex_unlock(&mutA);
		pthread_mutex_unlock(&mutB);	
	}

	return 0;
}
