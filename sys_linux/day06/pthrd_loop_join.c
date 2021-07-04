/*************************************************************************
	> File Name: pthrd_loop_join.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月15日 星期一 02时24分06秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>

void* thrd_print(void* arg)
{
	int num = (int) arg;
	printf("I am %d thread, my id: %lu\n", num, pthread_self());
	return (void*)num;
}

int main(int arc, char* argv[])
{
	int t_num = atoi(argv[1]);
//	int t_num = 5;
	pthread_t tid[t_num];
	int ret;
	for(int i = 0; i < t_num; i++){
		ret = pthread_create(&tid[i], NULL, thrd_print, (void*)i);
		if(ret != 0){
			printf("pthread_create err:%s\n", strerror(ret));
			exit(1);
		}
	}
	for(int i = 0; i < t_num; i++){
		void* retval;
		ret = pthread_join(tid[i], &retval);
		if(ret != 0){
			printf("pthread_create err:%s\n", strerror(ret));
			exit(1);
		}
		printf("I have join the %d thread: %lu, it's retval: %d\n", i, tid[i],
				(int)retval);
	}
	return 0;
}
