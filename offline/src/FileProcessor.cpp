 ///
 /// @file    FileProcessor.cpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2015-11-10 09:25:30
 ///


#include "FileProcessor.hpp"
#include "Configuration.hpp"
#include "GlobalDefine.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

namespace wd
{

FileProcessor::FileProcessor(Configuration & conf)
	  : conf_(conf)
{
	std::map<std::string, std::string> & confMap = conf_.getConfigMap();
	std::string titleFeatureFilePath = confMap[TITLEFEATURE_KEY];
	std::ifstream ifs(titleFeatureFilePath.c_str());
	if(ifs)
	{
		getline(ifs, titleFeature_);
	}
	std::cout << "titleFeature_ = " << titleFeature_ << std::endl;
}


std::string FileProcessor::process(int idx, const std::string & filename)
{
	std::string page;
	std::string id;
	std::string url;
	std::string title;
	std::string content;

	std::ostringstream oss;
	oss << (idx + 1);
	id = oss.str();

	url = filename;

	readfile(filename, title, content);

	page.append("<doc>\n<docid>")
		.append(id).append("</docid>\n<docurl>")
		.append(url).append("</docurl>\n<doctitle>\n")
		.append(title).append("\n</doctitle>\n<doccontent>\n")
		.append(content).append("\n</doccontent>\n</doc>\n");
		
	return page;
}

void FileProcessor::readfile(
		const std::string & filename, 
		std::string & title, 
		std::string & content)
{
	std::ifstream ifs(filename.c_str());
	if(!ifs)
	{
		std::cout << "ifstream open error!" << std::endl;
	}
	else
	{
		ifs.seekg(0, ifs.end);
		int length = ifs.tellg();
		ifs.seekg(0, ifs.beg);

		content.resize(length, ' ');
		ifs.read(&*content.begin(), length);

		//get title
		ifs.seekg(0, ifs.beg);
		title.resize(1024, ' ');
		int count = 11;
		bool flag = false;
		while(getline(ifs, title) && count > 0)
		{
			std::string::size_type pos = title.find(titleFeature_);
			if(pos != std::string::npos)
			{
				pos += titleFeature_.size();
				title = title.substr(pos);
				flag = true;
				break;
			}
			--count;
		}
		if(count > 0 && flag == false)
		{// 如果文档没有12行，将第一行作为标题
			ifs.seekg(0, ifs.beg);
			getline(ifs, title);
		}
		else if(count == 0 && flag == false)
		{//如果有12行，则将12行作为标题
			getline(ifs, title);
		}

		size_t sz = title.size();
		if(title[sz - 1] == '\n')
		{	
			title[sz - 1] = '\0';
		}
	}//end else
}


}// end of namespace wd
