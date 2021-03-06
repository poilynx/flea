#define _WIN32_WINNT 0x0501
#include <windows.h>
#include <stdio.h>



typedef struct ip_option_information {
  UCHAR  Ttl;
  UCHAR  Tos;
  UCHAR  Flags;
  UCHAR  OptionsSize;
  PUCHAR OptionsData;
} IP_OPTION_INFORMATION, *PIP_OPTION_INFORMATION;


#define _In_
#define _Out_
#define _In_opt_

typedef HANDLE (* _IcmpCreateFile)(void);


typedef BOOL (WINAPI*_IcmpCloseHandle)(
  _In_ HANDLE IcmpHandle
);


typedef DWORD (WINAPI*  _IcmpSendEcho2)(
  _In_     HANDLE                 IcmpHandle,
  _In_opt_ HANDLE                 Event,
  _In_opt_ PVOID/*PIO_APC_ROUTINE*/ApcRoutine,
  _In_opt_ PVOID                  ApcContext,
  _In_     DWORD                  DestinationAddress,
  _In_     LPVOID                 RequestData,
  _In_     WORD                   RequestSize,
  _In_opt_ /*PIP_OPTION_INFORMATION*/LPVOID RequestOptions,
  _Out_    LPVOID                 ReplyBuffer,
  _In_     DWORD                  ReplySize,
  _In_     DWORD                  Timeout
);

typedef struct icmp_echo_reply {
  DWORD/*IPAddr*/              Address;
  ULONG                        Status;
  ULONG                        RoundTripTime;
  USHORT                       DataSize;
  USHORT                       Reserved;
  PVOID                        Data;
  struct ip_option_information  Options;
} ICMP_ECHO_REPLY, *PICMP_ECHO_REPLY;

//#define IP_DEST_HOST_UNREACHABLE 11003
//#define IP_DEST_NET_UNREACHABLE 11002
#define IP_REQ_TIMED_OUT 11010
