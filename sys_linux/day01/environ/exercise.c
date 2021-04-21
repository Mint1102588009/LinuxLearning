/*************************************************************************
	> File Name: exercise.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年02月19日 星期五 16时18分46秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char *	val;
	const char * name = "ChenFengwei";
	val = getenv(name);
	printf("1,%s:%s\n", name, val);
	setenv(name, "ShanJing", 7);
	val = getenv(name);
	printf("2,%s:%s\n", name, val);
	setenv(name, "XiCi", 1);
	val = getenv(name);
	printf("3,%s:%s\n", name, val);
//	int ret = unsetenv("chen");
//	printf("ret = %d\n", ret);
	int	ret = unsetenv(name);
	printf("ret = %d\n", ret);
	ret = unsetenv(name);
	printf("ret = %d\n", ret);
	val = getenv(name);
	printf("4,%s:%s\n", name, val);

	return 0;
}

