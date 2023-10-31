#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * append_text_to_file - Appends text to the end of a file.
 * @filename: Name of the file to append to.
 * @text_content: A NULL-terminated string to append to the file.
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
    int fd, write_status;
    ssize_t text_len = 0;

    if (filename == NULL)
        return (-1);

    if (text_content == NULL)
        return (1);

    while (text_content[text_len] != '\0')
        text_len++;

    fd = open(filename, O_WRONLY | O_APPEND, 0600);
    if (fd == -1)
        return (-1);

    write_status = write(fd, text_content, text_len);
    close(fd);

    if (write_status == -1 || write_status != text_len)
        return (-1);

    return (1);
}
