/*************************************************************************
	> File Name: test.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年02月19日 星期五 15时08分35秒
 ************************************************************************/

#include<stdio.h>

extern char **environ;

int main(){
	for(int i = 0; environ[i]; i++){
		printf("%s\n", environ[i]);
	}

	return 0;
}
