/*************************************************************************
	> File Name: myopen.cpp
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年02月27日 星期六 16时12分11秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<cstdlib>

int main()
{
	int fd;
	fd = open("./hello",O_RDWR);
	if(fd == -1)
	{
		perror("open file");
		exit(1);
	}

	int ret = close(fd);
	cout << "ret = " << ret << endl;
	if(ret = -1)
	{
		perror("open file");
	}
	return 0;
}
