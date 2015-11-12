 ///
 /// @file    test_offline.cpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2015-11-12 11:21:17
 ///


#include "Configuration.hpp"
#include "DirScanner.hpp"
#include "FileProcessor.hpp"
#include "PageLib.hpp"

int main(void)
{
	wd::Configuration conf("conf/my.conf");

	wd::DirScanner dirScanner(conf);
	dirScanner();

	wd::FileProcessor fileProcessor(conf);

	wd::PageLib pagelib(conf, dirScanner, fileProcessor);
	pagelib.create();
	pagelib.store();

	return 0;
}
