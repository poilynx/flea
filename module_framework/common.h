#include <windows.h>
#include <stdio.h>
struct FUNC_TABLE {
	HMODULE (WINAPI *LoadLibraryA)(LPCSTR lpFileName);
	FARPROC (WINAPI *GetProcAddress)(HMODULE hModule,LPCSTR  lpProcName);
};

extern unsigned int payload(struct FUNC_TABLE *);
