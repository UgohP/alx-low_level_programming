#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "main.h"

/**
 * read_textfile - Reads and prints a text file to standard output.
 * @filename: Name of the file to read.
 * @letters: Number of letters to read and print.
 * Return: The actual number of letters read and printed.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    int fd;
    ssize_t n_read, n_written;
    char *buffer;

    if (filename == NULL)
        return (0);

    buffer = malloc(sizeof(char) * letters);
    if (buffer == NULL)
        return (0);

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        free(buffer);
        return (0);
    }

    n_read = read(fd, buffer, letters);
    if (n_read == -1)
    {
        free(buffer);
        close(fd);
        return (0);
    }

    n_written = write(STDOUT_FILENO, buffer, n_read);
    if (n_written == -1 || n_written != n_read)
    {
        free(buffer);
        close(fd);
        return (0);
    }

    close(fd);
    free(buffer);

    return n_written;
}
