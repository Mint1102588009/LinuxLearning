/*************************************************************************
	> File Name: event.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月29日 星期一 16时12分10秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<event2/event.h>

void read_cb(evutil_socket_t fd, short what, void * arg){
	char buf[1024] = {0};
	int len = read(fd, buf, sizeof(buf));
	printf("what = %s, read from write :%s\n",
			what & EV_READ ? "read 满足" : "read 不满足", buf);
	sleep(1);
	return;
}

int main(){
	unlink("myfifo");
	mkfifo("myfifo", 0664);//创建命名管道

	int fd = open("myfifo", O_RDONLY | O_NONBLOCK);//打开管道文件
	struct event_base * base = event_base_new();//创建事件base

	struct event * ev = event_new(base, fd, EV_READ, read_cb, NULL);
	//创建事件
	event_add(ev, NULL);//添加监听事件

	event_base_dispatch(base);//循环监听时间

	event_free(ev);//释放事件
	event_base_free(base);//释放事件base
	close(fd);
	unlink("myfifo");

	return 0;
}
