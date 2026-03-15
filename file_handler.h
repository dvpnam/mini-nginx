#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

void send_file(int client, char *path);
const char *get_content_type(char *path);

#endif
