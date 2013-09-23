#ifndef SOCKET_H
#define SOCKET_H

#include <string>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

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
	sockaddr_in& getNetAddr(){return addr_;};
	
private:
	sockaddr_in addr_;
};

#define INVALID_SOCKET -1

class Socket
{
public:
	Socket(){};
	Socket(int domain, int type, int protoc = 0);
	
	inline int getfd(){return fd_;};
	
	int bind(InetAddr& addr);
	int listen(int backlog = 5);
	int accept(Socket& s, InetAddr& addr);
	int connect(InetAddr& addr);
	int close(){return ::close(fd_);};
	
	int recv(void* pBuf, size_t len, int iflag);
	int send(const void* pBuf, size_t len, int iflag); 
	int recvfrom(){return 0;};
	int sendto(){return 0;};
	
	int setBlock(bool bBlock);
	
private:
	int domain_;
	int type_;
	int protoc_;
	
	int fd_;
};

#endif /*SOCKET_H*/
