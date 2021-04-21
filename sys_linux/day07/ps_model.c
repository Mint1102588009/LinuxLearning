/*************************************************************************
	> File Name: ps_model.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月17日 星期三 17时05分53秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

struct msg{
	int num;
	struct msg* next;
};

struct msg* head = NULL;
struct msg* mp = NULL;

pthread_mutex_t mutex;
pthread_cond_t has_product;

void* pth_product(void* arg)
{
	while(1){
		mp = malloc(sizeof(struct msg));
		mp->num = rand() % 400 + 1;
		printf("---produced---%d\n", mp->num);
		pthread_mutex_lock(&mutex);
		mp->next = head;
		head = mp;
		pthread_mutex_unlock(&mutex);
		pthread_cond_signal(&has_product);
	}
	return NULL;
}

void* pth_consume(void* arg)
{
	while(1){
		pthread_mutex_lock(&mutex);
		while(head == NULL){
			pthread_cond_wait(&has_product, &mutex);
		}
		mp = head;
		head = mp->next;
		printf("---consume---%d\n", mp->num);
		free(mp);
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

int main()
{
	pthread_t ptid, ctid;
	pthread_create(&ptid, NULL, pth_product, NULL);
	pthread_create(&ctid, NULL, pth_consume, NULL);
	pthread_join(ptid, NULL);
	pthread_join(ctid, NULL);

	return 0;
}
