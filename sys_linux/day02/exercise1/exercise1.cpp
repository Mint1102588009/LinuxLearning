/*************************************************************************
	> File Name: exercise1.cpp
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年02月25日 星期四 15时31分16秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<cstdlib>

int main()
{
	pid_t id;
	int i = 3;
	int n = i;
	for(;i > 0; i--)
	{
		id = fork();
		if(id == 0)
		{
			break;
		}else if(id == -1)
		{
			perror("no process create:\n");
		}
	}
	if(i == 1){
		execlp("ps","ps","aux",NULL);
	}else if(i == 2)
	{
		execl("./hello","hello",NULL);
	}else if(i == 3)
	{
		execl("./error","error",NULL);
	}
	while(n > 0)
	{
		pid_t pid = waitpid(-1,NULL,0);
		if(pid == 0)
			n--;
	}
	cout << "Parent process finished!" << endl;

	return 0;
}
