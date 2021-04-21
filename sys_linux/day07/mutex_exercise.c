/*************************************************************************
	> File Name: mutex_exercise.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月15日 星期一 20时20分46秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

//pthread_mutex_t mutex;

void* tfn(void* arg)
{
	while(1){
//		pthread_mutex_lock(&mutex);
		printf("Hello,");
		sleep(rand() % 3);
		printf("mint_7!\n");
		sleep(rand() % 3);
//		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

int main()
{
	pthread_t tid;
	srand(time(NULL));
//	pthread_mutex_init(&mutex, NULL);
	pthread_create(&tid, NULL, tfn, NULL);
	pthread_detach(tid);
	while(1){
//		pthread_mutex_lock(&mutex);
		printf("Hello,");
		sleep(rand() % 3);
		printf("mint_7!\n");
		sleep(rand() % 3);
//		pthread_mutex_unlock(&mutex);
	}
	return 0;
}
