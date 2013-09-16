#include "socket.h"

#include <iostream>
#include <cstring>
#include <cerrno>
#include <cassert>

InetAddr::InetAddr(int port)
{
	addr_.sin_family = AF_INET;
	addr_.sin_port = hton(port);
	addr_.sin_addr = htonl(INADDR_ANY);
}

InetAddr::InetAddr(const string& addr, int port)
{
	addr_.sin_family = AF_INET;
	addr_.sin_port = hton(port);
	inet_aton(addr.c_str(), &addr_.sin_addr.s_addr);
}

string InetAddr::getIP()
{
	return string(inet_ntoa(addr_.sin_addr.s_addr));
}

int InetAddr::getPort()
{
	return ntoh(addr_.sin_port);
}

string InetAddr::getIPAddr
{
	ostringstream oss(getIP());
	oss << ":" << getPort();
	
	return oss.str();
}

////////////////////////////////////////////////////////////////////////////////////////////////
//class Socket

Socket(int domain, int type, int protoc)
	: domain_(domain), type_(type), protoc_(protoc)
{
	fd_ = socket(domain_, type_, protoc_);
	if(-1 == fd_)
		cout << "err: " << string(strerrer(errno)) <<endl;
}

int Socket::bind(const InetAddr& addr)
{
	assert(-1 != fd_);
	
	int rst = ::bind(fd_, addr.getNetAddr(), sizeof(sockaddr_in));
	if(-1 == rst)
		cout << "err: " << string(strerror(errno)) <<endl;
	
	return rst;
}

int Socket::listen(int backlog)
{
	assert(-1 != fd_);
	int rst = ::listen(fd_, backlog);
	if(-1 == rst)
		cout << "err: " << string(strerror(errno)) <<endl;
	
	return rst;
}

int Socket::connect(const InetAddr& addr)
{
	assert(-1 != fd_);
	
	int rst = ::connect(fd_, addr.getNetAddr, sizeof(sockaddr_in));
	if(-1 == rst)
		cout << "err: " << string(strerror(errno)) <<endl;
	
	return rst;
}

int Socket()

