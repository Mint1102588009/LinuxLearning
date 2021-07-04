/*************************************************************************
	> File Name: thread_test.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月14日 星期日 21时35分59秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

void* my_thread(void* argc)
{
	printf("In thread: my thread id: %lu my process id: %d\n", pthread_self(), 
			getpid());
	return 0;
}

int main()
{
	printf("In main thread: my thread id: %lu my process id: %d\n", pthread_self(), 
			getpid());
	pthread_t thrd;
	pthread_create(&thrd, NULL, my_thread, NULL);
	sleep(1);
	printf("In main thread: my thread id: %lu my process id: %d\n", pthread_self(), 
			getpid());


	return 0;
}
