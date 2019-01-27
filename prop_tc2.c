#include <stdio.h>
#include "sys.h"
#include "aux.h"
#include "umix.h"


void Main ()
{
	DPrintf("Processes all have default CPU allocation, so they should end around the same time.\n");
	DPrintf("This should behave like round robin.\n");
	if (GetSchedPolicy() != PROPORTIONAL) {
		DPrintf("ERROR: Policy is not set to PROPORTIONAL. Please manually set policy to PROPORTIONAL in mycode2.c.");
		Exit();
	}
	if (Fork () == 0) {

		if (Fork () == 0) {

			SlowPrintf (5, "4444444444");
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

	SlowPrintf (5, "1111111111");
	DPrintf("\nProcess %d exiting.\n", 1);
	Exit ();
}
