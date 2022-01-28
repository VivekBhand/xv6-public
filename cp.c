#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


int
main(int argc, char *argv[])
{
  int fd, fd2, count;
  char buf[512];

  if(argc <= 2){
    printf(1, "Usage :./cp file1 file2\n");
    exit();
  }
  fd = open(argv[1], O_RDONLY);
  fd2 = open(argv[2], O_WRONLY | O_CREATE);
  if((fd == -1) || (fd2 == -1)){
      printf(1, "Open failed file 1:%d file 2:%d\n", fd, fd2);
      exit();
    }
  while((count = read(fd, buf, 512)))
    write(fd2, buf, count);

  close(fd);
  close(fd2);
  exit();
}
