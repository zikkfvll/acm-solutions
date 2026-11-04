//time.cpp
//设置时间 
#include <iostream>
#include "time.h"
void Time::set_time()		//注意加“Time::” 
{
	cin >> h;
	cin >> m;
	cin >> s;
}
//输出时间 
void Time::show_time()
{
	printf("%02d : %02d : %02d\n", h, m, s); 
}
