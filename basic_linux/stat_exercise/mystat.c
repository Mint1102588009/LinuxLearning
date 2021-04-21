/*************************************************************************
	> File Name: mystat.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月01日 星期一 15时08分27秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		printf("./a.out filename\n");
	}
	struct stat f_info;
	int ret = stat(argv[1], &f_info);
	if(ret == -1)
	{
		perror("stat");
		exit(1);
	}
	int size = (int)f_info.st_size;
	printf("file size = %d\n", size);

	return 0;
}
