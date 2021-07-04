/*************************************************************************
	> File Name: more_pthread.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月14日 星期日 22时24分34秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>

void* my_thread(void* argv)
{
	int i = (int)argv;
	printf("I am %dth thread\n", i);
	return NULL;
}

int main()
{
	pthread_t thrd;
	int i;
	for(i = 0; i < 5; i++){
		int ret = pthread_create(&thrd, NULL, my_thread, (void*)i);
		if(ret != 0){
			printf("pthread_create err:%s\n", strerror(ret));
			exit(1);
		}
	}
//	sleep(i);
//	while(1);
//	pthread_exit(NULL);
	return 0;
}
