 ///
 /// @file    test_socket.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2015-11-04 18:11:26
 ///

#include "WordQuery.hpp"
#include "TcpServer.h"

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <string>
#include <iostream>
#include <memory>


wd::WordQuery * pWordQuery = nullptr;

void onConnection(const wd::TcpConnectionPtr & conn)
{
	printf("%s\n", conn->toString().c_str());
	//conn->send("Hello, welcome to wd's server\n");
}

void onMessage(const wd::TcpConnectionPtr & conn)
{
	std::string msg(conn->receive());
	//std::cout << "client: " << msg.size() << " ," << msg << std::endl;
	size_t pos = msg.find('\n');
	msg = msg.substr(0, pos);
	
	std::cout << "client:" << msg << ", msg's size:" << msg.size() << std::endl;
	std::string ret = pWordQuery->doQuery(msg);
	std::cout << "ret's size: " << ret.size() << std::endl;
	conn->send(ret);
}

void onClose(const wd::TcpConnectionPtr & conn)
{
	printf("%s close.\n", conn->toString().c_str());
}

int main(void)
{
	signal(SIGPIPE, SIG_IGN);

#if 1
	wd::Configuration conf("./conf/my.conf");
	wd::WordQuery wordQuery(conf);
	pWordQuery = & wordQuery;
#endif

	wd::TcpServer server(5080);
	server.setConnectionCallback(onConnection);
	server.setMessageCallback(onMessage);
	server.setCloseCallback(onClose);
	server.start();

	return 0;
}
