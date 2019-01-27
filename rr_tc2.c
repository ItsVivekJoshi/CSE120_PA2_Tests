#include <stdio.h>
#include "sys.h"
#include "aux.h"
#include "umix.h"

void Main ()
{
	if (GetSchedPolicy() != ROUNDROBIN) {
		DPrintf("ERROR: Policy is not set to ROUNDROBIN. Please manually set policy to ROUNDROBIN in mycode2.c.");
		Exit();
	}
	if (Fork () == 0) {
		if (Fork () == 0) {
			SlowPrintf (5, "5555555555");		// process 5
			DPrintf("\nProcess %d exiting.\n", 5);
			Exit ();
		}
		SlowPrintf (5, "2222222222");			// process 2
		DPrintf("\nProcess %d exiting.\n", 2);
		Exit ();
	}
	if (Fork () == 0) {
		if (Fork () == 0) {
			SlowPrintf (5, "AAAAAAAAAA");			// process 10
			DPrintf("\nProcess %d exiting.\n", 10);
			Exit ();
		}
		SlowPrintf (5, "3333333333");			// process 3
		DPrintf("\nProcess %d exiting.\n", 3);
		Exit ();
	}
	if (Fork () == 0) {
		if (Fork () == 0) {
			SlowPrintf (5, "999999999");			// process 9
			DPrintf("\nProcess %d exiting.\n", 9);
			Exit ();
		}
		SlowPrintf (5, "4444444444");			// process 4
		DPrintf("\nProcess %d exiting.\n", 4);
		Exit ();
	}

	if (Fork () == 0) {
		if (Fork () == 0) {
			SlowPrintf (5, "7777777777");			// process 7
			DPrintf("\nProcess %d exiting.\n", 7);
			Exit ();
			if (Fork () == 0) {
				SlowPrintf (5, "8888888888");			// process 8
				DPrintf("\nProcess %d exiting.\n", 8);
				Exit ();
			}
		}

		SlowPrintf (5, "6666666666");			// process 6
		DPrintf("\nProcess %d exiting.\n", 6);
		Exit ();
	}
	SlowPrintf (5, "1111111111");			// process 1
	DPrintf("\nProcess %d exiting.\n", 1);
	Exit ();
}
