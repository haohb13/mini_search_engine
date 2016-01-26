 ///
 /// @file    test_threadpool.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2015-11-03 16:08:30
 ///


#include "Threadpool.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

struct Task
{
	void operator()()
	{
		::srand(::time(NULL));
		int num = ::rand() % 100;
		std::cout << "produce a number: " << num << std::endl;
	}
};


int test_threadpool(void)
{
	wd::Threadpool threadpool(5, 10);
	threadpool.start();
	int count = 20;
	while(count --)
	{
		threadpool.addTask(Task());
		::sleep(1);
	}
	threadpool.stop();

	return 0;
}
