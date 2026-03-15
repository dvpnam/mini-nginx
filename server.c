#include "file_handler.h"
#include "http_parser.h"

#include <arpa/inet.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080

void handle_request(int client);
void *client_thread(void *arg);

int main(void)
{
    int server_fd;
    int client;

    struct sockaddr_in server_addr;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    listen(server_fd, 10);

    printf("mini-nginx running on port %d\n", PORT);

    while (1) {

        client = accept(server_fd, NULL, NULL);

        pthread_t tid;

        pthread_create(&tid, NULL, client_thread, &client);

        pthread_detach(tid);
    }

    return 0;
}

void handle_request(int client) {

    char buffer[2048];
    char path[256];

    read(client, buffer, sizeof(buffer));

    parse_request(buffer, path);

    printf("request: %s\n", path);

    send_file(client, path);
}

void *client_thread(void *arg) {

    int client = *(int*)arg;

    handle_request(client);

    close(client);

    return NULL;
}
