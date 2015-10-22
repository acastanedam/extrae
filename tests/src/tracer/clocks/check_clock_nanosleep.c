#include <unistd.h>
#include <stdio.h>
#include "common.h"
#include "clock.h"
#include <time.h>

int main (int argc, char *argv[])
{
	UINT64 begin, end;
	unsigned u;

	UNREFERENCED_PARAMETER(argc);
	UNREFERENCED_PARAMETER(argv);

	Clock_Initialize (1);
	Clock_Initialize_thread ();
	
	for (u = 1 ; u < 5; u++)
	{
		UINT64 d;
		UINT64 n = u * 1000;
		struct timespec ns;
		ns.tv_sec = u;
		ns.tv_nsec = 0;

		begin = Clock_getCurrentTime(0);
		nanosleep (&ns, NULL);
		end = Clock_getCurrentTime(0);

		d = (end - begin) / 1000000;

		if ( n != d )
		{
			printf ("Executed nanosleep (%u seconds) but we measured %lu nanoseconds\n",
			  u, end-begin);
			printf ("Comparison of timing in microseconds do not match! (%lu != %lu)\n",
			  n, d);
			return 1;
		}
	}

	return 0;
}

