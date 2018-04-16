
//------------------------------------------
#define SEND_DATAGRAM 0
#define SEND_OPEN_PIPE 1
#define SEND_BREAK_PIPE 2
#define SEND_CLOSE_PIPE 3

#define RECV_DATAGRAM 0
#define RECV_PIPE 1
#define RECV_ENTER 2
#define RECV_LEAVE 3

int server_init();
int server_config(addr,port);
int server_clasp();
int server_secede();

int server_add_listenner(proc,sid);

int server_send(type,id,param)
int server_recv(type,id,*param)

int server_read(pid,buf,*size);
int server_write(pip,buf,size);


server_loop()


//-----------------------------------------
#define SEND_DATAGRAM 0
#define SEND_OPEN_PIPE 1
#define SEND_BREAK_PIPE 2
#define SEND_CLOSE_PIPE 3

#define RECV_DATAGRAM 0
#define RECV_PIPE 1
#define RECV_ENTER 2
#define RECV_LEAVE 3

int client_init(port);
int client_list(int*, int* count);
int client_get_addr(id,*addr);
int client_send(server,type,id,param);
int client_recv(server,type,id,*param);
int server_read(pid,buf,*size);
int server_write(pip,buf,size);

client_loop()








