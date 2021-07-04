/*************************************************************************
	> File Name: pc_sem.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月18日 星期四 15时40分15秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#define NUM 5

int queue[NUM];
sem_t blank_sem, product_sem;

void* thrd_productor(void* arg)
{
	int tail = 0;
	while(1)
	{
		sem_wait(&blank_sem);
		queue[tail] = rand();
		printf("prduct:%d\n", queue[tail]);
		tail = (tail + 1) % NUM;
		sem_post(&product_sem);
	}
	return NULL;
}

void* thrd_consumer(void* arg)
{
	int head = 0;
	while(1)
	{
		sem_wait(&product_sem);
		queue[head] = rand();
		printf("consume:%d\n", queue[head]);
		head = (head + 1) % NUM;
		sem_post(&blank_sem);
	}
	return NULL;
}

int main()
{
	pthread_t tid1,tid2;
	sem_init(&blank_sem, 0, NUM);
	sem_init(&product_sem, 0, 0);
	pthread_create(&tid1, NULL, thrd_productor, NULL);
	pthread_create(&tid2, NULL, thrd_consumer, NULL);
	sem_destroy(&blank_sem);
	sem_destroy(&product_sem);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	return 0;
}
