#include <stdio.h>
#include "sys.h"
#include "aux.h"
#include "umix.h"


void Main ()
{
	DPrintf("Process 2 should finish first.\n");
	if (GetSchedPolicy() != PROPORTIONAL) {
		DPrintf("ERROR: Policy is not set to PROPORTIONAL. Please manually set policy to PROPORTIONAL in mycode2.c.");
		Exit();
	}
	if (Fork () == 0) {
		RequestCPUrate(99);
		SlowPrintf(5, "2222222222");

		DPrintf("\nProcess %d exiting.\n", 2);
		Exit ();
	}
	if (Fork () == 0) {
		RequestCPUrate(0);
		SlowPrintf(5, "3333333333");
		DPrintf("\nProcess %d exiting.\n", 3);
		Exit ();
	}

	if (Fork () == 0) {
		RequestCPUrate(0);
		SlowPrintf(5, "4444444444");
		DPrintf("\nProcess %d exiting.\n", 4);
		Exit ();
	}

	RequestCPUrate(0);
	SlowPrintf (5, "1111111111");
	DPrintf("\nProcess %d exiting.\n", 1);
	Exit ();
}
