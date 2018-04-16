#define CTL_BREAK_STREAM 1
#define CTL_END_STREAM
struct flea_pkg_header {
	uint16_t	sid;
	uint16_t	mid;
	uint8_t		ctl;
	uint32_t	param;
}





int chat = flea_chat(1001);
if(char == -1) 
	exit(-1);

flea_send_msg(1,"aaa",size);
flea_recv_msg(1,buf,size);
int pipe = flea_open_pipe(2,chat);
flea_write(pipe, buf, size);
flea_close_pipe(pipe, status);

while(flea_get())

