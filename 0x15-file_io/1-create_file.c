#include <fcntl.h>
#include <unistd.h>
#include "main.h"

int create_file(const char *filename, char *text_content)
{
    int fd, write_status;
    ssize_t text_len = 0;

    if (filename == NULL)
        return (-1);

    if (text_content == NULL)
        text_content = "";

    while (text_content[text_len] != '\0')
        text_len++;

    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
    if (fd == -1)
        return (-1);

    write_status = write(fd, text_content, text_len);
    close(fd);

    if (write_status == -1 || write_status != (ssize_t)text_len)
        return (-1);

    return (1);
}
