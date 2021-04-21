/*************************************************************************
	> File Name: pthrd_detach.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月15日 星期一 03时07分04秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>

void* thrd_detach(void* arg)
{
	int i = (int)arg;
	printf("I am %d detached thread\n",i);
	return arg;
}

int main(int argc, char* argv[])
{
	int t_num = atoi(argv[1]);
	pthread_t tid[t_num];
	for(int i = 0; i < t_num; i++){
		pthread_create(&tid[i], NULL, thrd_detach, (void*)i);
		pthread_detach(tid[i]);
	}
	sleep(1);
	for(int i = 0; i < t_num; i++){
		int ret;
		void* retval;
		ret = pthread_join(tid[i], &retval);
		if(ret != 0){
			printf("pthread_join err:%s\n", strerror(ret));
		}
	}
	return 0;
}
