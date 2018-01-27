#include <stdio.h>
#include <windows.h>
#include <winsock.h>
#pragma comment(lib,"ws2_32.lib")
void service(void)
{
	goto b;
a:
	{
		register int a = 0;
		__asm {
			mov eax,[esp+4]
			mov a,eax

		}
		printf ("%p\n",a);
		__asm {ret}
	}
b:
	__asm{
		push 2
		call a
		add esp,4
	}
}

int main()
{
	service();
	return 0;
}
