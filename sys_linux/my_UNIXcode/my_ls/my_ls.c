/*************************************************************************
	> File Name: my_ls.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年02月22日 星期一 20时14分10秒
 ************************************************************************/
#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	DIR *dp;
	struct dirent *dirp;
/*	if(argc != 2){
		err_quit("usage: ls directory_name");
	}
	if((dp = opendir(argv[1])) == NULL){
		err_sys("can't open %s'", argv[1]);
	}*/
	while((dirp = readdir(dp)) != NULL){
		printf("%s\n", dirp->d_name);
	}
	closedir(dp);
	exit(0);
}

