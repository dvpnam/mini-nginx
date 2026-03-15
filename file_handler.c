#include "file_handler.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void send_file(int client, char *path) {

    char fullpath[256];
    sprintf(fullpath, "www%s", path);

    FILE *file = fopen(fullpath, "rb");

    if (!file) {

        char response[] =
        "HTTP/1.1 404 Not Found\r\n"
        "Content-Type: text/html\r\n"
        "\r\n"
        "<h1>404 Not Found</h1>";

        write(client, response, strlen(response));
        return;
    }

    if (!file) {

        char *notfound =
        "HTTP/1.1 404 Not Found\r\n\r\n404";

        write(client, notfound, strlen(notfound));
        return;
    }

    const char *type = get_content_type(path);

    char header[256];

    sprintf(header,
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: %s\r\n"
    "\r\n", type);

    write(client, header, strlen(header));

    // ---- SAU ĐÓ MỚI GỬI FILE ----

    char buffer[1024];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), file)) > 0) {

        write(client, buffer, bytes);
    }

    fclose(file);
}

const char *get_content_type(char *path) {

    char *ext = strrchr(path, '.');

    if (!ext) return "text/plain";

    if (strcmp(ext, ".html") == 0) {
        return "text/html";
    }
    if (strcmp(ext, ".css") == 0) {
        return "text/css";
    }
    if (strcmp(ext, ".js") == 0) {
        return "application/javascript";
    }
    if (strcmp(ext, ".png") == 0) {
        return "image/png";
    }
    if (strcmp(ext, ".jpg") == 0 || strcmp(ext, ".jpeg") == 0) {
        return "image/jpeg";
    }
    if (strcmp(ext, ".gif") == 0) {
        return "image/gif";
    }

    return "text/plain";
}
