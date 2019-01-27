#include <stdio.h>
#include "sys.h"
#include "aux.h"
#include "umix.h"


void Main ()
{
	DPrintf("Output expected is alternating numbers per quantum.\n");
	if (GetSchedPolicy() != ROUNDROBIN) {
		DPrintf("ERROR: Policy is not set to ROUNDROBIN. Please manually set policy to ROUNDROBIN in mycode2.c.");
		Exit();
	}
	if (Fork () == 0) {
		if (Fork () == 0) {
			SlowPrintf (5, "5555555555");		// process 5
			Exit ();
		}
		SlowPrintf (5, "2222222222");			// process 2
		Exit ();
	}
	if (Fork () == 0) {
		SlowPrintf (5, "3333333333");			// process 3
		Exit ();
	}
	if (Fork () == 0) {
		SlowPrintf (5, "4444444444");			// process 4
		Exit ();
	}
	SlowPrintf (5, "1111111111");			// process 1
	Exit ();
}
