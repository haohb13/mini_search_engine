 ///
 /// @file    test_offline.cpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2015-11-12 11:21:17
 ///

#include "GlobalDefine.hpp"
#include "Configuration.hpp"
#include "DirScanner.hpp"
#include "FileProcessor.hpp"
#include "PageLib.hpp"
#include "WordSegmentation.hpp"
#include "WebPage.hpp"
#include "PageLibPreprocessor.hpp"

#include <stdio.h>
#include <time.h>

int main(void)
{
	wd::Configuration conf("conf/my.conf");

	wd::DirScanner dirScanner(conf);
	dirScanner();

	wd::FileProcessor fileProcessor(conf);

	wd::PageLib pagelib(conf, dirScanner, fileProcessor);

	time_t t1 = time(NULL);
	pagelib.create();
	pagelib.store();
	time_t t2 = time(NULL);
	printf("raw lib create and store time: %d min\n", (t2 - t1));

	wd::PageLibPreprocessor libPreprocessor(conf);
	libPreprocessor.doProcess();

	return 0;
}
