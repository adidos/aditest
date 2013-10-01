#include <sys/mmap.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
#include <string>
using namespace std;

int main()
{
  int fd = open("test", O_CREATE|O_RDWR, S_IRWXU);
  if(-1 == df)
  {
    cout << "error: " << strerror(errno) <<endl;
    return -1;
  }
  
  mmap()
  
  
  
  
}