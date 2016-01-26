 ///
 /// @file    PageLib.cpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2015-11-10 16:55:10
 ///


#include "Configuration.hpp"
#include "PageLib.hpp"
#include "DirScanner.hpp"
#include "FileProcessor.hpp"
#include "GlobalDefine.hpp"

#include <iostream>
#include <fstream>

namespace wd
{
PageLib::PageLib(Configuration & conf,
				 DirScanner & dirScanner,
			     FileProcessor & fileProcessor)
	: conf_(conf),
	  dirScanner_(dirScanner),
	  fileProcessor_(fileProcessor)
{}


void PageLib::create()
{
	std::vector<std::string> & vecFiles = dirScanner_.files();
	for(size_t idx = 0; idx != vecFiles.size(); ++idx)
	{
		std::string page = fileProcessor_.process(idx, vecFiles[idx]);
		vecPages_.push_back(page);
	}
}

void PageLib::store()
{
	//需要读取配置信息//???
	std::map<std::string, std::string> & confMap = conf_.getConfigMap();
	std::string pageLibPath = confMap[RIPEPAGELIB_KEY];
	std::string offsetLibPath = confMap[OFFSETLIB_KEY];

	std::ofstream ofsPage(pageLibPath.c_str());
	std::ofstream ofsOffset(offsetLibPath.c_str());
	if(!(ofsPage.good() && ofsOffset.good()))
	{
		std::cout << "ofstream open error!" << std::endl;
		return;
	}

	for(size_t idx = 0; idx != vecPages_.size(); ++idx)
	{
		int id = idx + 1;
		int length = vecPages_[idx].size();
		std::ofstream::pos_type offset = ofsPage.tellp();
		ofsPage << vecPages_[idx];

		ofsOffset << id << '\t' << offset << '\t' << length << '\n';
	}

	ofsPage.close();
	ofsOffset.close();
}

}//end of namespace wd
