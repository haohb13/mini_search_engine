 ///
 /// @file    Configuration.cpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2015-11-10 17:30:39
 ///

#include "Configuration.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

namespace wd
{

Configuration::Configuration(const std::string & filepath)
	: filepath_(filepath)
{
	readConfiguration();
}

void Configuration::readConfiguration()
{
	std::ifstream ifs(filepath_.c_str());
	if(ifs.good())
	{
		std::string line;
		while(getline(ifs, line))
		{
			std::istringstream iss(line);
			std::string key;
			std::string value;
			iss >> key >> value;
			configMap_[key] = value;
		}
		std::cout << "read configuration is over!" << std::endl;
	}
	else
	{
		std::cout << "ifstream open error" << std::endl;
	}
}

std::map<std::string, std::string> & Configuration::getConfigMap()
{
	return configMap_;
}

}// end of namespace wd
