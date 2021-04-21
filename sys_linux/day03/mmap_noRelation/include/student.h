/*************************************************************************
	> File Name: student.h
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月02日 星期二 00时07分54秒
 ************************************************************************/

#include<stdlib.h>

struct STU{
	int id;
	char name[20];
	char sex;
};

void sys_err(char* str){
	perror(str);
	exit(1);
}
