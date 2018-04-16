#include <stdint.h>
#define EV_RECEIVED 0
#define EV_INIT_MODULE 1
#define EV_INIT_SESSION 2
#define EV_UNINIT_MODULE 3
#define EV_UNINIT_SESSION 4

/* hcb_t (Handler Control Block) */
struct hcb_t {
	int event;		/* Event type, EV_* */
	int sid; 		/* Session ID */
	int mid; 		/* Message ID */
	void *buf; 		/* Receiving buffer */
	int len; 		/* Length Received */
	void *sstat; 	/* Session state */
	void *mstat; 	/* Module state */
}

/* Handler callback function definition */
typedef int(*handlerproc)(hcb_t *hcb);

/* Init socket and set remote address */
int server_init(uint32_t addr,uint16_t port); 
/* Try to connect to remote host */
int server_clasp();

/* Add Module ID(sub port), handler callback to handler-table */
int server_add_handler(uint16_t mdlid, handlerproc proc);

int server_rm_handler(uint16_t mdlid);

/* Send data */
int server_send(int sid,uint8_t id, unsigned char *buf, int size);

/* Disconnect to remote host */
int server_secede();

/* Enter event loop */
int server_run();
