/*************************************************************************
	> File Name: test2.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月02日 星期二 00时35分26秒
 ************************************************************************/

#include<stdio.h>
#include"student.h"
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/mman.h>

int main(){
	struct STU student;
	struct STU* st;
	int fd = open("test.txt", O_RDONLY);
	if(fd == -1){
		sys_err("open err:");
	}
	st = mmap(NULL, sizeof(student), PROT_READ, MAP_SHARED, fd, 0);
	if(st == MAP_FAILED){
		sys_err("mmap err:");
	}
	close(fd);
	while(1){
		printf("%d,%s,%c\n", st->id, st->name, st->sex);
	}
	int ret = munmap(st, sizeof(student));
	if(ret == -1){
		sys_err("munmap err:");
	}


	return 0;
}

