#include "common.h"
unsigned int payload(struct FUNC_TABLE *T) {
	__asm{ mov eax,0xABAB}
	printf("hello world\n");
	return 0;
}