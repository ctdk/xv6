#include "types.h"
#include "user.h"

int main(int argc, char *argv[]){
	// stdin
	if (isatty(0))
		printf(1, "stdin is a tty\n");
	else
		printf(1, "stdin is not a tty\n");

	exit();
}
