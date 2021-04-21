/*************************************************************************
	> File Name: zoombie.cpp
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年02月25日 星期四 12时01分07秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include<sys/types.h>
#include<unistd.h>

int main()
{
	pid_t id = fork();
	if(id != 0)
	{
		sleep(30);
		cout << "555,my son has dead!" << endl;
	}
	else
	{
		cout << "I am " << getpid() << "zoombie!" << endl;	
	}

	return 0;
}
