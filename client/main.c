#include "echosvr.h"
#include "utils.h"
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>

int main() {
	request req;
	
	if (echosvr_init() != ES_E_SUCCEED)
		return -1;
	
	if(echosvr_listen(&req) != ES_E_SUCCEED)
		return -1;
	char buf[100]="hello";
	//memset(buf,0x7a,sizeof(buf));
	if(echosvr_reply(&req,buf,sizeof(buf)) != ES_E_SUCCEED)
		return -1;
	printf("seq = %hd\n",req.seq);
	osid oi;
	parse_request(req.data,&oi);

	printf("iswow64 = %hhd\n"
		"ver:major = %d\n"
		"ver:minor = %d\n"
		"ver:build = %d\n"
		"hostname = %s\n"
		,oi.iswow64,oi.major,oi.minor,oi.build,oi.hostname);
	

	return 0;
}
