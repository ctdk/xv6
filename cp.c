#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
  char buf[512];
  int fd, dfd, r, w;
  char *src;
  char *dest;

  if(argc != 3){
    printf(2, "Usage: cp src dest\n");
    exit();
  }

  src = argv[1];
  dest = argv[2];

  if ((fd = open(src, O_RDONLY)) < 0) {
    printf(2, "cp: cannot open source %s\n", src);
    exit();
  }
  if ((dfd = open(dest, O_CREATE|O_WRONLY)) < 0) {
    printf(2, "cp: cannot open destination %s\n", dest);
    exit();
  }
  
  while ((r = read(fd, buf, sizeof(buf))) > 0) {
    w = write(dfd, buf, r);
    if (w != r || w < 0) 
      break;
  }
  if (r < 0 || w < 0)
    printf(2, "cp: error copying %s to %s\n", src, dest);

  close(fd);
  close(dfd);

  exit();
}
