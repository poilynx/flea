#include <stdint.h>

int client_init(uint16_t port);
int client_list(int*svrarr, int size);
int client_get_addr(int svrid,*addr);

// return session id
int client_connect(uint16_t port);
void client_disconnect(int sid);

int client_send(int sid,uint8_t id, unsigned char *buf, int size);
int client_peekid(int sid, uint8_t *id);
int client_recv(int sid,unsigned char *buf, int *size);

int client_loop()

