#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <fcntl.h>
#include "rtdsc.h"

TimeWatcher tw;

#define	DEV_FILE	"/dev/pcietest/0"

int main()
{
	int i;
	char buf[256];
	int fd;
	unsigned long long cycles[10];

	if ( ( fd = open( DEV_FILE, O_RDWR ) ) < 0 ) {
		fprintf( stderr, "File can not open\n" );
		return (-1);
	}
	get_cpu_cycle_per_sec();

	i = read( fd, buf, 256 );
	write( 0, buf, i);

	sscanf( buf, "%lu,%lu,%lu,%lu,%lu,%lu", &cycles[0], &cycles[1], &cycles[2], &cycles[3], &cycles[4], &cycles[5]);

	printf("CPU Frequency:%lldMHz (%lld cycles/sec)\n", cpu_cycles_per_sec / 1000000, cpu_cycles_per_sec);

	for (i=0; i<6; ++i) {
		printf("time:%llu ns, CPU cycles:%llu\n", cycles[i] * 1000000000 / cpu_cycles_per_sec / 100000, cycles[i] / 100000);
	}

	close(fd);

	return 0;
}
