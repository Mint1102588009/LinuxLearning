/*************************************************************************
	> File Name: execl_test.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年02月22日 星期一 20时51分09秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
	pid_t id;
	int i = 0;
	for(;i < 2; i++){
		id = fork();
		if(id == 0){
			execlp("./mint","mint",NULL);
			break;
		}else{
//			sleep(3);
			printf("father...\n");
		}
	}

	return 0;
}
