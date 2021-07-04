/*************************************************************************
	> File Name: test1.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月02日 星期二 00时12分40秒
 ************************************************************************/

#include<stdio.h>
#include"student.h"
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<string.h>

int main(){
	struct STU student;
	struct STU * st;
	int fd = open("test.txt", O_RDWR | O_CREAT, 0664);
	truncate("test.txt", sizeof(student));
	if(fd == -1){
		sys_err("open err:");
	}
	st = mmap(NULL, sizeof(student), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if(st == MAP_FAILED){
		sys_err("mmap err:");
	}
	close(fd);
	st->id = 1;
	strcpy(st->name, "Mint_7");
	st->sex = 'm';
	for(int i = 0; i < 100; i++){
		sleep(1);
		st->id++;
	}
	int ret = munmap(st, sizeof(student));
	if(ret == -1){
		sys_err("munmap err:");
	}


	return 0;
}
