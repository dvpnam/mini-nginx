all:
	gcc server.c http_parser.c file_handler.c -o mini-nginx -lpthread
