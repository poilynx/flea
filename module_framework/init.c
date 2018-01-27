#include "common.h"
int main(){
	struct FUNC_TABLE tab;
	tab.LoadLibraryA = LoadLibraryA;
	tab.GetProcAddress  = GetProcAddress;
	payload(&tab);
	return 0;
}