#include <stdio.h>
#include "sys.h"
#include "aux.h"
#include "umix.h"


void Main ()
{
	DPrintf("Proc 2 should finish before Proc 1, and your program shouldn't crash or allow 1 to finish first.\n");
	DPrintf("This tests to make sure your pass value doesn't overflow.\n");
	if (GetSchedPolicy() != PROPORTIONAL) {
		DPrintf("ERROR: Policy is not set to PROPORTIONAL. Please manually set policy to PROPORTIONAL in mycode2.c.");
		Exit();
	}
	if (Fork() == 0) {
		RequestCPUrate(95);
		SlowPrintf(5, "222222222222222222");
		DPrintf("\nProcess %d exiting.\n", 2);
		Exit ();
	}
	RequestCPUrate (1);					// process 1
	SlowPrintf (9, "11111111111111111111");
	DPrintf("\nProcess %d exiting.\n", 1);
	Exit ();
}
