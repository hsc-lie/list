#include <stdio.h>

#include "singly_list_test.h"
#include "doubly_list_test.h"


int main(void)
{

#if 1
	SinglyListInsertTest();
	SinglyListRemoveTest();
	SinglyListGetTest();
	SinglyListLoopTest();
	printf("\n");
#endif

#if 1
	DoublyListInsertTest();
	DoublyListRemoveTest();
	DoublyListGetTest();
	DoublyListLoopTest();
#endif

	return 0;
}