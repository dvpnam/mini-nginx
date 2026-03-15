#include "http_parser.h"

#include <stdio.h>
#include <string.h>

void parse_request(char *request, char *path) {

    sscanf(request, "GET %s", path);

    // Directory index
    if (strcmp(path, "/") == 0) {

        strcpy(path, "/index.html");
    }
}
