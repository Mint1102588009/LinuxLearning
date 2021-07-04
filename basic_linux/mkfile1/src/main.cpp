/*************************************************************************
	> File Name: main.cpp
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年02月13日 星期六 17时00分56秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include"myPlus.h"
#include"mySub.h"

int main(){
	int a,b;
	a = 1;
	b = 6;
	cout << myPlus(a,b) << endl;
	cout << mySub(a,b) << endl;
	return 0;
}
