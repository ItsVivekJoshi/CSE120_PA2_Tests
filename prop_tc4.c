#include <stdio.h>
#include "sys.h"
#include "aux.h"
#include "umix.h"


void Main ()
{
	DPrintf("Process should exit in order: 4, 1, {2, 3}\n");
	if (GetSchedPolicy() != PROPORTIONAL) {
		DPrintf("ERROR: Policy is not set to PROPORTIONAL. Please manually set policy to PROPORTIONAL in mycode2.c.");
		Exit();
	}
	if (Fork () == 0) {

		if (Fork () == 0) {

			RequestCPUrate (30);			// process 4
			SlowPrintf (5, "444");
			RequestCPUrate(60);
			SlowPrintf (5, "4444444");
			DPrintf("\nProcess %d exiting.\n", 4);
			Exit ();
		}

		SlowPrintf (5, "2222222222");
		DPrintf("\nProcess %d exiting.\n", 2);
		Exit ();
	}

	if (Fork () == 0) {

		SlowPrintf (5, "3333333333");
		DPrintf("\nProcess %d exiting.\n", 3);
		Exit ();
	}

	RequestCPUrate (40);					// process 1
	SlowPrintf (5, "1111111111");
	DPrintf("\nProcess %d exiting.\n", 1);
	Exit ();
}
