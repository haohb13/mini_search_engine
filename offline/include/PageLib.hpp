 ///
 /// @file    PageLib.hpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2015-11-10 15:57:22
 ///


#ifndef _WD_PAGELIB_H_
#define _WD_PAGELIB_H_

#include <string>
#include <vector>


namespace wd
{

class Configuration;
class DirScanner;
class FileProcessor;

class PageLib
{
public:
	PageLib(Configuration & conf,
			DirScanner & dirScanner, 
			FileProcessor & fileProcessor);

	void create();
	void store();

private:
	Configuration &          conf_;
	DirScanner &             dirScanner_;
	FileProcessor &          fileProcessor_;
	std::vector<std::string> vecPages_;
};


}//end of namespace wd

#endif
