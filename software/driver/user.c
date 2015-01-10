#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <arpa/inet.h>

//#define DEBUG

#define	MEM_DEVICE	"/dev/pcietest/0"
#define	BUF_SIZE	(256)

int main(int argc,char **argv)
{
	unsigned long pa, mem0p, baraddr;
	int fd, i;
	unsigned char if_ipv4[4], if_mac[6];
	if ((fd=open(MEM_DEVICE,O_RDONLY)) <0) {
		fprintf(stderr,"cannot open %s\n",MEM_DEVICE);
		return 1;
	}
	i = 123;
	while (1) {
		printf ("i=%d, &i=%p, Physical Address=%012lx\n", i, &i, pa);
		usleep(10000);
	}
	close(fd);
}
