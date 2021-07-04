/*************************************************************************
	> File Name: orphan.cpp
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年02月25日 星期四 12时14分39秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include<sys/types.h>
#include<unistd.h>

int main()
{
	pid_t id = fork();
	if(id == 0)
	{
		cout << "Son" << getpid() <<" has been orphon!My home is " << getppid()
			<< endl;
		sleep(30);
		cout << "Son" << getpid() <<" has been orphon!My new home is " << getppid()
			<< endl;
	}else
	{
		cout << "Father" << getpid() <<" has dead!" << endl;
	}
	return 0;
}
