struct fls_request_header {
	uint16_t id;
	uint16_t 
	unsigned char buf[512];
	uint16_t size;
};

int	fls_get_request(struct fls_request_header* hdr);
int fls_response(int aborting,
fls_close


flc_request_t*	flc_request(uint16_t id, unsigned char * buf, size_t size, bool_t confirm)
flc_response_t*	flc_get_response(flc_request_t* req, int status, unsigned char * buf,size_t *size)
flc_close


flnet_read
flnet_write

flnet_close

