//#define SEND_DATAGRAM 0
//#define SEND_OPEN_PIPE 1
//#define SEND_BREAK_PIPE 2
//#define SEND_CLOSE_PIPE 3
//
//#define RECV_DATAGRAM 0
//#define RECV_PIPE 1
//#define RECV_ENTER 2
//#define RECV_LEAVE 3
#include <stdint.h>

typedef int(*listenner)(int sid, int id, char *buf, int size, void** state);
int server_init();
int server_config(uint32_t addr,uint16_t port);
int server_clasp();
int server_secede();

int server_add_handler(uint16_t mdlid, listenner proc);
int server_remove_handler(uint16_t mdlid);

int server_send(int sid,uint8_t id, unsigned char *buf, int size);
int server_run();
