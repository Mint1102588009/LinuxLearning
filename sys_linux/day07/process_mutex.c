/*************************************************************************
	> File Name: process_mutex.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月18日 星期四 17时04分14秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/types.h>
#include<string.h>
#include<sys/mman.h>
#include<sys/wait.h>

struct mt {//定义一个结构体
	int num;
	pthread_mutex_t mutex;
	pthread_mutexattr_t mutexattr;
};

int main()
{
	struct mt* mm;//创建一个结构体指针
	pid_t pid;
	mm = mmap(NULL, sizeof(*mm), PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANON, -1, 0);
	//建立一个匿名映射区，用于进程间IPC
	memset(mm, 0, sizeof(*mm));//用0填满mm指向的结构体
	pthread_mutexattr_init(&mm->mutexattr);//初始化进程间互斥量属性（attr）
	pthread_mutexattr_setpshared(&mm->mutexattr, PTHREAD_PROCESS_SHARED);
	//设置为进程共享
	pthread_mutex_init(&mm->mutex, &mm->mutexattr);

	pid = fork();
	if(pid == 0)
	{
		for(i = 0; i < 10; i++)
		{
			pthread_mutex_lock(&mm->mutex);
			(mm->num)++;
			printf("child:num++ %d\n", mm->num);
			pthread_mutex_unlock(&mm->mutex);
			sleep(1);
		}
	}else if(pid > 0)
	{
		for(i = 0; i < 10; i++)
		{
			sleep(1);
			pthread_mutex_lock(&mm->mutex);
			mm->num += 2;
			printf("parent:num+=2 %d\n", mm->num);
			pthread_mutex_unlock(&mm->mutex);
		}
		wait(NULL);
	}
	pthread_mutexattr_destroy(&mm->mutexattr);
	pthread_mutex_destroy(&mm->mutex);


	return 0;
}
