#include "socket.h"

#include <unistd.h>
#include <fcntl.h>

#include <iostream>
#include <sstream>
#include <cstring>
#include <cerrno>
#include <cassert>

/////////////////////////////////////////////////////////////////////////////
//InetAddr

InetAddr::InetAddr(int port)
{
	addr_.sin_family = AF_INET;
	addr_.sin_port = htons(port);
	addr_.sin_addr.s_addr = htonl(INADDR_ANY);
}

InetAddr::InetAddr(const string& addr, int port)
{
	addr_.sin_family = AF_INET;
	addr_.sin_port = htons(port);
	inet_aton(addr.c_str(), &addr_.sin_addr);
}

string InetAddr::getIP()
{
	return string(inet_ntoa(addr_.sin_addr));
}

int InetAddr::getPort()
{
	return ntohs(addr_.sin_port);
}

string InetAddr::getIPAddr()
{
	ostringstream oss(getIP());
	oss << ":" << getPort();
	
	return oss.str();
}

////////////////////////////////////////////////////////////////////////////////////////////////
//class Socket

Socket::Socket(int domain, int type, int protoc)
	: domain_(domain), type_(type), protoc_(protoc)
{
	fd_ = socket(domain_, type_, protoc_);
	if(-1 == fd_)
		cout << "err: " << string(strerror(errno)) <<endl;
}

int Socket::bind(InetAddr& addr)
{
	assert(INVALID_SOCKET != fd_);
	
	int rst = ::bind(fd_, (struct sockaddr*)&addr.getNetAddr(), sizeof(sockaddr_in));
	if(-1 == rst)
		cout << "err: " << string(strerror(errno)) <<endl;
	
	return rst;
}

int Socket::listen(int backlog)
{
	assert(INVALID_SOCKET != fd_);
	int rst = ::listen(fd_, backlog);
	if(-1 == rst)
		cout << "err: " << string(strerror(errno)) <<endl;
	
	return rst;
}

int Socket::connect(InetAddr& addr)
{
	assert(INVALID_SOCKET != fd_);
	
	int rst = ::connect(fd_, (struct sockaddr*)&addr.getNetAddr(), sizeof(sockaddr_in));
	if(-1 == rst)
		cout << "err: " << string(strerror(errno)) <<endl;
	
	return rst;
}

int Socket::accept(Socket& s, InetAddr& addr)
{
    assert(INVALID_SOCKET == s.fd_);

    int fd = -1;
    struct sockaddr saddr;
    socklen_t sock_len;
    while((fd == ::accept(fd_, &saddr, &sock_len) < 0) && errno == EINTR);

    s.fd_ = fd;
    s.domain_ = this->domain_;

    return s.fd_;
}

int Socket::recv(void* pBuf, size_t len, int iflag)
{
    return ::recv(this->fd_, pBuf, len, iflag);
}


int Socket::send(const void* pBuf, size_t len, int iflag)
{
    return ::send(this->fd_, pBuf, len, iflag);
}


int Socket::setBlock(bool bBlock)
{
    int val = 0;
    if((val = fcntl(fd_, F_GETFL, 0)) == -1)
    {
        cout << "fcntl(F_GETFL) error: " << strerror(errno) << endl;

        return -1;
    }

    if(!bBlock)
        val |= O_NONBLOCK;
    else
        val &= ~O_NONBLOCK;

    if(fcntl(fd_, F_SETFL, val) == -1)
    {
        cout << "fcntl(f_setfl) error: " << strerror(errno) << endl;

        return -1;
    }

    return 0;
}
