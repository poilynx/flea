#include <stdio.h>  
#include <stdlib.h>  
#include <errno.h>  
#include <string.h>  
#include <netdb.h>  
#include <sys/types.h>  
#include <netinet/in.h>  
#include <sys/socket.h>  
#include <sys/types.h>  

#define MAXDATASIZE 100  
#define SERVPORT 1234  
#define MAXLINE 1024  

struct {
	uint16_t mdlid;
	listener proc;
} handler_table[256];

struct {
	void *state
} session_table[256];




static int sockfd;  
static char hostname[256];
static uint16_t hostport;

static int initialized = 0;

static unsigned char read1byte(int sockfd);

int server_init() {
	bzero(listenner_table,sizeof(listenner_table);
	initialized = 1;
}

int server_config(char *name,uint16_t port) {
	strcpy(client_hostname,name);
	client_port = port;
}

int server_clasp() {
	struct hostent *host;  
	struct sockaddr_in serv_addr;  
	assert(initialized == 1);
	if(sockfd != -1)
		return 1;

	if((host = gethostbyname(client_hostname)) == NULL) {  
		perror("gethostbyname");  
		exit(1);  
	}
	if((sockfd = socket(AF_INET,SOCK_STREAM,0)) == -1) {  
		perror("socket error \n");  
		exit(1);  
	}  

	serv_addr.sin_family = AF_INET;  
	serv_addr.sin_port = htons(client_port);  
	serv_addr.sin_addr = *((struct in_addr *)host->h_addr);  
	bzero(&(serv_addr.sin_zero),8);  

	if(connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(struct sockaddr)) ==-1)  
	{  
		perror("connect \n");  
		exit(1);  
	}
	return 0;

}

int server_secede() {
	assert(initialized == 1);
	if(sockfd == -1)
		return 1;

	close(sockfd);
	sockfd = -1;
	return 0;
}

int server_add_listenner(listenner proc,uint16_t mdlid) {
	int i;
	int avai_idx = -1;
	assert(initialized == 1);
	if(mdlid == 0) {
		perror("port can not be 0");
		return 1;
	}
	for(i=0 ;i<256; i++) {
		if(listenner_table[i].mdlid == 0)
			avai_idx = i;
		else if(listenner_table[i].mdlid == mdlid) {
			perror("port already added.");
			return 2;
		}
	}

	if (avai_idx == -1) 
		return 3;
	listenner_table[avai_idx].mdlid = mdlid;
	listenner_table[avai_idx].mdlid = mdlid;

	return 0;
}

int server_send(int sid,uint8_t id, unsigned char *buf, int size) {

}
int server_peekid(int sid, uint8_t *id) {

}
int server_recv(int sid,unsigned char *buf, int *size) {

}

static unsigned char read1byte(int sockfd) {
	unsigned char b;
	int ret;
	ret = recv(sockid, &b, 1, 0);
	if(SOCKET_ERROR == ret) {
		perror("recv");
		exit(1);
	} else if(0 == ret)
		return -1;
	else
		return b;
}

int server_run() {
	unsigned char buf[1024];
	unsigned char by;
	assert(initialized == 1);
	by = read1byte(sockfd);
	if(by == PKG_CONNECT)
}

int main(int argc,char *argv[])  
{  
	int sockfd,sendbytes;  
	// char send[MAXLINE];  

	char send[MAXLINE];  
	char buf[MAXDATASIZE];  
	struct hostent *host;  
	struct sockaddr_in serv_addr;  

	if((host = gethostbyname("localhost")) == NULL)  
	{  
		perror("gethostbyname");  
		exit(1);  
	}  
	if((sockfd = socket(AF_INET,SOCK_STREAM,0)) == -1)  
	{  
		perror("socket error \n");  
		exit(1);  
	}  

	serv_addr.sin_family = AF_INET;  
	serv_addr.sin_port = htons(SERVPORT);  
	serv_addr.sin_addr = *((struct in_addr *)host->h_addr);  
	bzero(&(serv_addr.sin_zero),8);  

	if(connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(struct sockaddr)) ==-1)  
	{  
		perror("connect \n");  
		exit(1);  
	}  
	while(fgets(send,1024,stdin)!=NULL)  
	{  
		if((sendbytes = write(sockfd,send,100)) ==-1)  
		{  
			perror("send error \n");  
			exit(1);  
		}  
	}  
	close(sockfd);  
}  
