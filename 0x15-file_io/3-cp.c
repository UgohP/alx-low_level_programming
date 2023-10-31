#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * main - Copies the content of one file to another.
 * @ac: Number of arguments.
 * @av: Array of arguments.
 * Return: 0 on success, 97, 98, 99, or 100 on failure.
 */
int main(int ac, char **av)
{
    int fd_from, fd_to, read_status, write_status;
    char buffer[1024];

    if (ac != 3)
    {
        dprintf(2, "Usage: %s file_from file_to\n", av[0]);
        exit(97);
    }

    fd_from = open(av[1], O_RDONLY);
    if (fd_from == -1)
    {
        dprintf(2, "Error: Can't read from file %s\n", av[1]);
        exit(98);
    }

    fd_to = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
    if (fd_to == -1)
    {
        dprintf(2, "Error: Can't write to %s\n", av[2]);
        close(fd_from);
        exit(99);
    }

    while ((read_status = read(fd_from, buffer, 1024)) > 0)
    {
        write_status = write(fd_to, buffer, read_status);
        if (write_status != read_status)
        {
            dprintf(2, "Error: Can't write to %s\n", av[2]);
            close(fd_from);
            close(fd_to);
            exit(99);
        }
    }

    if (read_status == -1)
    {
        dprintf(2, "Error: Can't read from file %s\n", av[1]);
        close(fd_from);
        close(fd_to);
        exit(98);
    }

    if (close(fd_from) == -1)
    {
        dprintf(2, "Error: Can't close fd %d\n", fd_from);
        exit(100);
    }

    if (close(fd_to) == -1)
    {
        dprintf(2, "Error: Can't close fd %d\n", fd_to);
        exit(100);
    }

    return (0);
}
