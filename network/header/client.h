#include <stdint.h>

/* Listen to port */
int client_init(uint16_t port);
/* Return first connection-id and set index to first */
int client_conn_first();
/* Return next connection-id and move to next */
int client_conn_next();

int client_conn_get_address(int cid, char* addr);

/* Create a session and return session id 
 * Remote handler attached with mdlid will trigle a EV_INIT_SESSION event*/
int client_connect(uint16_t mdlid);

void client_disconnect(int sid);

/* Send data */
int client_send(int sid,uint8_t id, unsigned char *buf, int size);

/* Peek next message id */
int client_peekid(int sid, uint8_t *id);

int client_recv(int sid,unsigned char *buf, int *size);

/* Enter event loop */
int client_run()

