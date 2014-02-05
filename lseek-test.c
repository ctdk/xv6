#include "types.h"
#include "user.h"
#include "fcntl.h"

char buf[40];

int main(int argc, char *argv[]) {

	int fd = open("file", O_CREATE | O_RDWR);

	lseek(fd, 500, SEEK_CUR);
	printf(fd,"stuff\n\n");
	lseek(fd, 1000, SEEK_END);
	printf(fd, "moar stuff\n");

	// This lseek should fail. Sometimes it even returns an error.
	/* lseek(fd, -100, SEEK_SET);
	printf(fd, "shouldn't work\n");
	*/

	close(fd);
	exit();
}
