#include "types.h"
#include "user.h"

int main (int argc, char *argv[]){
	int ut;
	ut = uptime();
	printf(1, "up %d ticks\n", ut);
	exit();
}
