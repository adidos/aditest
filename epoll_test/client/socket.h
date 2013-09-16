#ifndef SOCKET_H
#define SOCKET_H

#include <string>

#include "net_inc.h"

using namespace std;

class InetAddr
{
public:
	explicit InetAddr(int port);
	InetAddr(const string& addr, int port);
	
	InetAddr(sockaddr_in& addr)
	 :addr_(addr){};

	string getIP();
	int getPort();
	string getIPAddr();
	sockaddr_in& getNetAddr(){return addr;};
	
private:
	sockaddr_in addr_;
};

class Socket
{
public:
	Socket(){};
	Socket(int domain, int type, int protoc = 0);
	
	inline int getfd(){return fd_;};
	
	int bind(const InetAddr& addr);
	int listen(int backlog = 5);
	int accept();
	int connect(const InetAddr& addr);
	int close(){return ::close(fd_);};
	
	int recv();
	int send(); 
	int recvfrom(){return 0;};
	int sendto(){return 0;};
	
	setNoBlock();
	
private:
	int domain_;
	int type_;
	int protoc_;
	
	int fd_;
};

#endif /*SOCKET_H*/