/*************************************************************************
	> File Name: rwlock_test.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月16日 星期二 16时38分34秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>

int counter = 0;
pthread_rwlock_t rwl;

void* thrd_read(void* arg)
{
	int num = (int)arg;
	while(1){
		pthread_rwlock_rdlock(&rwl);
		printf("I am %d thread: I readed : %d\n", num, counter);
		pthread_rwlock_unlock(&rwl);
		usleep(100);
	}
	return arg;
}

void* thrd_write(void* arg)
{
	int num = (int)arg;
	while(1){
		pthread_rwlock_wrlock(&rwl);
		printf("I am %d thread: I writed : %d\n", num, ++counter);
		pthread_rwlock_unlock(&rwl);
	}
	return arg;
}

int main()
{	
	int i;
	pthread_t tid[8];
//	pthread_rwlock_init(&rwl, NULL);
	for(; i < 3; i++){
		int ret = pthread_create(&tid[i], NULL, thrd_write, (void*)i);
		if(ret != 0)
		{
			printf("pthread_create err:%s\n", strerror(ret));
			exit(1);
		}
	}
	for(; i < 8; i++){
		int ret = pthread_create(&tid[i], NULL, thrd_read, (void*)i);
		if(ret != 0)
		{
			printf("pthread_create err:%s\n", strerror(ret));
			exit(1);
		}
	}
	for(int j = 0; j < i; j++)
	{
		void* retval;
		int ret = pthread_join(tid[i], &retval);
		printf("%d has joined.", (int)retval);
		if(ret != 0)
		{
			printf("pthread_join err:%s\n", strerror(ret));
			exit(1);
		}
	}

//	while(1);
//	pthread_rwlock_destroy(&rwl);
	return 0;
}
