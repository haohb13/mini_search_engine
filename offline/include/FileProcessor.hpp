 ///
 /// @file    FileProcessor.hpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2015-11-10 10:17:19
 ///


#ifndef _WD_FILEPROCESSOR_H_
#define _WD_FILEPROCESSOR_H_

#include <string>

namespace wd
{
class Configuration;

class FileProcessor
{
public:
	FileProcessor(Configuration & conf);

	std::string process(int idx, const std::string & filename);

private:
	void readfile(const std::string & filename,
				  std::string & title,
				  std::string & content);
private:
	std::string titleFeature_;
	Configuration & conf_;
};

}// end of namespace wd
#endif
