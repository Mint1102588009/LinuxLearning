/*************************************************************************
	> File Name: zoombie_wait.cpp
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年02月25日 星期四 12时31分47秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<cstdlib>

int main()
{
	pid_t id = fork();
	if(id == 0)
	{
		sleep(60);
		cout << getpid() << "son has dead..." << endl;
		exit(777);
	}else
	{
		int stat;
		if(wait(&stat) == -1)
		{
			perror("error: wait failture!\n");
		}
		if(WIFEXITED(stat))
		{	
			cout << "Son exit with " << WEXITSTATUS(stat) << endl;
		}
		if(WIFSIGNALED(stat))
		{
			cout << "Son killed by " << WTERMSIG(stat) << endl;
		}
	}
	return 0;
}
