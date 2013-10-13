#include <sys/socket.h>
#include <sys/types.h>
#include <sys/epoll.h>

#include <iostream>
#include <thread>

using namespace std;

int fd = -1;
epoll_event event[2];

int main()
{
	fd = socket(AF_INET, SOCK_STREAM, 0);
	if(fd < 0)
		perror("socket");

	int epfd = epoll_create(2);
	if(epfd < 0)
		perror("epoll_create");

	epoll_event ev;
	ev.events = EPOLLIN | EPOLLET;
	ev.data.u64 = 1 << 32 | fd;
	epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &ev);
	
	auto func1 = [=](){
		while(1)
		{
			int num = epoll_wait(epfd, event, 2, 5000);
			for(int i = 0; i < num; ++i)
			{
				if(event[i].data.fd == fd)
					cout << "event come in" << endl;
			}
			
		}
	};

	thread waitth(func1);

	auto func2 = [=](){
		while(1)
		{
			epoll_event ev;
			ev.events = EPOLLOUT | EPOLLET;
			ev.data.u64 = 1 << 32 | fd;
			epoll_ctl(epfd, EPOLL_CTL_MOD, fd, &ev);
			this_thread::sleep_for(std::chrono::seconds(5));
		}
	}
	thread modth(func2);

	return 0;
}
